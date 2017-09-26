#include <string>
#include <iostream>
#include <chrono>
#include <memory>
#include <sys/time.h>
#include <deque>
#include <fstream>
#include <mutex>

#include <grpc/grpc.h>
#include <grpc++/server.h>
#include <grpc++/server_builder.h>
#include <grpc++/server_context.h>
#include <grpc++/security/server_credentials.h>
#include "main.grpc.pb.h"

#define DEBUG
#define NUM_CHATS 20

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerReaderWriter;
using grpc::ServerWriter;
using grpc::Status;
using grpc::Service;

using google::protobuf::MapPair;
using google::protobuf::Timestamp;

using hw::Request;
using hw::ChatRoom;
using hw::MainServer;
using hw::Client;
using hw::ChatMsg;

using namespace std;

class MainServerImpl final : public MainServer::Service {
	public:
	
		typedef MapPair<string, bool> Pair;
		typedef ServerReaderWriter<ChatMsg, ChatMsg>*  Streamer;
		typedef deque<ChatMsg> Msgs;

		MainServerImpl();
		~MainServerImpl() {
			for(auto& n : this->clients) delete n.second;
			for(auto& n : this->chatRooms) delete n.second;
		}
		
		Status RegisterClient(ServerContext* context, const Request* request,
												ChatRoom* response) override;
		
		Status ListRoom(ServerContext* context, const Request* request,
										ServerWriter<ChatRoom>* response) override;
		Status JoinRoom(ServerContext* context, const Request* request,
										Request* response) override;
		Status LeaveRoom(ServerContext* context, const Request* request,
										Request* response) override;
		Status Chat(ServerContext* context,
		 						ServerReaderWriter<ChatMsg, ChatMsg>* stream) override;
								
	private:
	
		void UpdateRecord(const string& c, const ChatMsg& m);   // update records database for client
		void WriteToFile(const string& room, const ChatMsg& cm);  // save chats to room file
		// TO-DO : database needs to be protected by mutex
		map<string, ChatRoom*> chatRooms;
		map<string, Client*> clients;
		map<string, Streamer> observers; // online clients
		map<string, Msgs> records;    // most recent 20 chats of a client
		
		// mutex for databases
		mutex roomMutex;				// for chat rooms
		mutex clientMutex;			// for users
		mutex observerMutex;		// for observers
		mutex recordMutex;			// for records
		mutex fileMutex;        // for room files
};

/*--------------------------------Main Server---------------------------------*/

void RunServer(string& port){
	string server_address("localhost:" + port);
	MainServerImpl service;
	
  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;
	server->Wait();
}

MainServerImpl::
MainServerImpl() {
	chatRooms.clear();
	clients.clear();
	observers.clear();
	records.clear();
}


Status
MainServerImpl::
RegisterClient(ServerContext* context,
							 const Request* request,
								ChatRoom* response) {
	// identify the client name from request	
	// update client database
	// create a chat room
	// update chatroom database
	
	string who = request->from();
	
	if(this->clients.find(who) == this->clients.end()){  // new client
		clientMutex.lock();
		Client* c = new Client;
		c->set_name(who);
		c->mutable_chatrooms()->insert(Pair(who, true));
		this->clients.insert(make_pair(who, c));
		clientMutex.unlock();
		
		roomMutex.lock();
		ChatRoom* cr = new ChatRoom;
		cr->set_owner(who);
		cr->mutable_clients()->insert(Pair(who, true));
		this->chatRooms.insert(make_pair(who, cr));
		roomMutex.unlock();
	
		response = cr;
	}
	else {  // old client logs back in
		response = chatRooms[who];
	}
	return Status::OK;
}

Status
MainServerImpl::
ListRoom(ServerContext* context, 
					const Request* request,
					ServerWriter<ChatRoom>* writer) {
	// traverse the chat room databases
	// identify the chat room owned by querying client
	if(request->request() == "ALL")
		for(const auto& cr : this->chatRooms)
			writer->Write(*cr.second);
	else if(request->request() == "JOINED") {
		string who = request->from();
		Client* c = clients[who];

		for(auto i : c->chatrooms()) {
			string name = i.first;
			writer->Write(*chatRooms[name]);
		}
	}
	return Status::OK;
}

Status
MainServerImpl::
JoinRoom(ServerContext* context,
				 const Request* request,
					Request* response) {
	// add client to chat room list
	string who = request->from();
	string room = request->request();
	if(this->chatRooms.find(room) == this->chatRooms.end()) { // room does not exist
		string r = "@Room " + room + " does not exist";
		string error = "ERROR";
		response->set_request(r);
		response->set_from(error);
	}
	else { // update database
		roomMutex.lock();
		ChatRoom* cr = this->chatRooms[room];
		// check if the client is already in chatroom
		if(cr->clients().find(who) == cr->clients().end()) {
			cr->mutable_clients()->insert(Pair(who, true));
			roomMutex.unlock();
		}
		else {
			string r = "@Room " + room + " already has user " + who;
			string error = "ERROR";
			response->set_request(r);
			response->set_from(error);
			roomMutex.unlock();
			return Status::OK;
		}
		
		clientMutex.lock();
		Client* c = this->clients[who];
		c->mutable_chatrooms()->insert(Pair(room, true));
		clientMutex.unlock();
		
		string r = "Successfully joined to room " + room;
		response->set_request(r);
		response->clear_from();
	}
	return Status::OK;
}

Status
MainServerImpl::
LeaveRoom(ServerContext* context,
					const Request* request,
					Request* response) {
	
	string who = request->from();
	string room = request->request();
	
	if(this->chatRooms.find(room) == this->chatRooms.end()) { // no such room
		string r = "@Room " + room + " does not exists";
		string error = "ERROR";
		response->set_from(error);
		response->set_request(r);
		return Status::OK;
	}
	ChatRoom* cr = this->chatRooms[room];
	Client* c = this->clients[who];
	
	if(cr->clients().find(who) == cr->clients().end()) { // no such client
		string r = "@No " + who + " exists in this room " + room;
		string error = "ERROR";
		response->set_request(r);
		response->set_from(error);
	}
	else {
		roomMutex.lock();
		cr->mutable_clients()->erase(who);
		roomMutex.unlock();
		
		clientMutex.lock();
		c->mutable_chatrooms()->erase(room);
		clientMutex.unlock();
		string r = "Successfully leave the room " + cr->owner();
		response->set_request(r);
	}
	return Status::OK;
}

void
MainServerImpl::
UpdateRecord(const string& c, const ChatMsg& m) {					
	Msgs& q = this->records[c];
	recordMutex.lock();
	if(q.size() != NUM_CHATS) {
		q.push_back(m);
	}
	else {
		q.pop_front();
		q.push_back(m);
	}
	recordMutex.unlock();
#ifdef DEBUG
	cout << "records size from client " 
				<< c << " is " << q.size() << endl;
#endif
}

void
MainServerImpl::
WriteToFile(const string& room, const ChatMsg& cm) {
	auto sec = cm.timestamp().seconds();
	char buffer[80];
	strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", localtime((time_t*)&sec));
	
	fileMutex.lock();
	ofstream out("./chats/" + room + ".txt", ios::app);
	out << buffer << " " << cm.from() 
				<< " (from room " << cm.room()
					<< ") says: " << cm.msg() << "\r\n";
	out.close();
	fileMutex.unlock();
}

Status
MainServerImpl::
Chat(ServerContext* context,
		 ServerReaderWriter<ChatMsg, ChatMsg>* stream) {
		ChatMsg msg;
		while(stream->Read(&msg)) {
			if(msg.init()){  // register as observers
				observerMutex.lock();
				this->observers.insert(make_pair(msg.from(), stream));
				observerMutex.unlock();
#ifdef DEBUG
				cout << "@observers size " << this->observers.size() << endl;
#endif
				// send last 20 chats to client
				for(auto& k : this->records[msg.from()]) {
					k.set_finished(false);
					stream->Write(k);
				}
				//stream->WritesDone();
				// tell client write is done
				//ChatMsg doneMsg;
				//doneMsg.set_finished(true);
				//stream->Write(doneMsg);
				continue;
			}
			string who = msg.from();
			Client* c = this->clients[who];
			// find each joined room
			auto cr = c->chatrooms();
			for(auto& n : cr) {
				auto cc = this->chatRooms[n.first]->clients();
				msg.set_room(n.first);
				// write to chat room file
				this->WriteToFile(n.first, msg);
				//for each client in that chat room
				for(auto& k : cc) {
					string w = k.first;
					// update records database for each client
					this->UpdateRecord(w, msg);
					if(this->observers.find(w) != this->observers.end()) { // if on line
						this->observers[w]->Write(msg);
					}
				}
			}
		}
		// off-line
		// unregister client from observers
		observerMutex.lock();
		this->observers.erase(msg.from());
		observerMutex.unlock();
		return Status::OK;
}

int main(int argc, char** argv){
	if(argc != 2) {
		cout << "@Wrong format of input, please enter, for example,\n"
					<< "\t ./fbsd port" << endl;
		exit(-1);
	}
	string port(argv[1]);
	RunServer(port);
	return 0;
}
