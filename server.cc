#include <string>
#include <iostream>
#include <chrono>
#include <memory>
#include <pthread.h>


#include <grpc/grpc.h>
#include <grpc++/server.h>
#include <grpc++/server_builder.h>
#include <grpc++/server_context.h>
#include <grpc++/security/server_credentials.h>
#include "main.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::ServerReader;
using grpc::ServerReaderWriter;
using grpc::ServerWriter;
using grpc::Status;
using grpc::Service;
using hw::Request;
using hw::ChatRoom;
using hw::MainServer;
using hw::RoomServer;
using hw::Client;
using std::chrono::system_clock;

using namespace std;

void* RunRoom(void* param);

class MainServerImpl final : public MainServer::Service {
	public:

		MainServerImpl();
		~MainServerImpl() {
			for(auto& n : clients) delete n.second;
		}
		
		Status RegisterClient(ServerContext* context, const Request* request,
												ChatRoom* response) override;
		
		Status ListRoom(ServerContext* context, const Request* request,
										ServerWriter<ChatRoom>* response) override;
		Status JoinRoom(ServerContext* context, const Request* request,
										Request* response) override;
		Status LeaveRoom(ServerContext* context, const Request* request,
										Request* response) override;
		Status Chat(ServerContext* context, const Request* request,
								Request* response) override;
								
	private:
	
		map<string, ChatRoom*> chatRooms;
		map<string, Client*> clients;
};

class RoomServerImpl final : public RoomServer::Service{
	public:
		explicit RoomServerImpl(ChatRoom* cr) : chatRoom(cr){}
		
	//	Status Chat(ServerContext* context, 
	//							ServerReaderWriter<Request, Request>* stream) override;
	private:
		//void WriteToFile();
		ChatRoom* chatRoom;
};

/*--------------------------------Main Server---------------------------------*/

void RunServer(){
	string server_address("localhost:50051");
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
}


Status
MainServerImpl::
RegisterClient(ServerContext* context,
							 const Request* request,
								ChatRoom* response) {
	// identify the client name from request	
	// update client database
	// create a chat room thread owned by client
	// update chatroom database
	// run the chat room server
	
	string who = request->from();
	
	if(clients.find(who) == clients.end()){  // new client
		Client* c = new Client;
		c->set_name(who);
		c->add_chatrooms(who);
		
		ChatRoom* cr = new ChatRoom;
		cr->set_owner(who);
		// TO-DO : find next available port
		int port = 5001;
		cr->set_port(port);
		cr->add_clients(who);
		pthread_t thread;
		pthread_create(&thread, NULL, RunRoom, (void*)cr);
		// TO-DO : thread id and int 32, type conversion is wrong
		cr->set_thread(thread);
		// cr->add_clients();
	
		this->clients.insert(make_pair(who, c));
		this->chatRooms.insert(make_pair(who, cr));
	
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
		int size = c->chatrooms_size();
		for(int i = 0; i < size; i++) {
			string name = c->chatrooms(i);
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
	if(chatRooms.find(room) == chatRooms.end()) { // room does not exist
		string r = "@Room " + room + " does not exist";
		response->set_request(r);
	}
	else { // update database
		
	}
}

Status
MainServerImpl::
LeaveRoom(ServerContext* context,
					const Request* request,
					Request* response) {
								;		
}

Status
MainServerImpl::
Chat(ServerContext* context,
		 const Request* request,
			Request* response) {
					;			
}

/*------------------------------------Chat Room Server------------------------------------------*/

void* RunRoom(void* param) {
	// TO-DO: find next available port
	ChatRoom* cr = (ChatRoom*)param;
	int port = cr->port();
	string server_address("localhost:5001");
	RoomServerImpl service(cr);
	
  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Chat Room " << cr->owner() <<" listening on " << server_address << std::endl;
	server->Wait();
}


int main(int argc, char** argv){
	RunServer();
	return 0;
}
