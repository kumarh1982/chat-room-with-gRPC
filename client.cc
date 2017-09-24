#include <chrono>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <thread>
#include <sstream>

#include <grpc/grpc.h>
#include <grpc++/channel.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc++/security/credentials.h>
#include "main.grpc.pb.h"

#define DEBUG

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientReaderWriter;
using grpc::ClientWriter;
using grpc::Status;
using hw::Request;
using hw::ChatRoom;
using hw::MainServer;
using hw::RoomServer;

using namespace std;

vector<string> stringSpliter(string& s);

class Client {
	public:
		  Client(shared_ptr<Channel> channel, string& n)
					: serverStub(MainServer::NewStub(channel)), name(n) {};
			void RegisterClient();
			void ListRoom();
			void ListAll();
			void ListJoined();
			void JoinRoom(string& r);
			void LeaveRoom(string& r);
			void Chat();
			void PrintRoom(ChatRoom& cr);
			void PrintChat();
	private:
			unique_ptr<MainServer::Stub> serverStub;
			vector<unique_ptr<RoomServer::Stub> > roomStubs;
			string name;
			ChatRoom owned;
};

void Client::Chat(){
        // TODO
        // retrieve the last 20 chats from all joined rooms
        Request request, response;
        ClientContext context;

        request.set_from(this->name);
        Status status = serverStub->Chat(&context, request, &response);
        if(!status.ok())
            cout << "@Chat request rpc failed." << endl;
        else{

        }
}

void Client::RegisterClient(){
	Request request;
	ClientContext context;

	request.set_from(this->name);
	Status status = serverStub->RegisterClient(&context, request, &this->owned);
	if(!status.ok())
		cout << "@Register Client rpc failed." << endl;
}

void Client::ListAll() {
	Request request;
	string r = "ALL";
	ClientContext context;
	ChatRoom cr;

	request.set_from(this->name);
	request.set_request(r);
	unique_ptr<ClientReader<ChatRoom> > reader(
		serverStub->ListRoom(&context, request));
	cout << "---------------all rooms---------------" << endl;
	while(reader->Read(&cr)) {
		this->PrintRoom(cr);
	}
	cout << "---------------------------------------" << endl;
	Status status = reader->Finish();
	if(!status.ok())
		cout << "@ListRoom rpc failed." << endl;
}

void Client::ListJoined() {
	Request request;
	string r = "JOINED";
	ClientContext context;
	ChatRoom cr;

	request.set_from(this->name);
	request.set_request(r);
	unique_ptr<ClientReader<ChatRoom> > reader(
		serverStub->ListRoom(&context, request));
	cout << "--------------joined rooms--------------" << endl;
	while(reader->Read(&cr)) {
		this->PrintRoom(cr);
	}
	cout << "----------------------------------------" << endl;
	Status status = reader->Finish();
	if(!status.ok())
		cout << "@ListRoom rpc failed." << endl;
}

void Client::ListRoom() {
	this->ListAll();
	this->ListJoined();
}

void Client::JoinRoom(string& r) {
        // send request to mainserver to get the port number of chat room to
        // join, then establish rpc connection with the chat room and store it
        // in roomsstub list
	ClientContext context;
	Request request, response;
	request.set_from(this->name);
	request.set_request(r);
	Status status = serverStub->JoinRoom(&context, request, &response);
	if(!status.ok())
		cout << "@JoinRoom rpc failed." << endl;
	else{
                string responseStr = response.request();
		cout << responseStr << endl;
                vector<string> splited = stringSpliter(responseStr);
                string addr_str = splited.back();
                // establish a bidirectional streaming roomstub?
                RoomServerStub roomStub(grpc::CreateChannel(addr_str,
                      grpc::InsecureChannelCredentials()), )
        }
}

void Client::PrintRoom(ChatRoom& cr) {

	cout << "chat room -> port:" << cr.port()
				<< " | owner: " << cr.owner()
				<< " | thread: " << cr.thread()
				<< endl;
}

void CommandMode(Client& c) {
	while(true) {
		cout << "Please enter a request below." << endl;
		string request;
		getline(cin, request);
		vector<string> splited = stringSpliter(request);
		if(request == "CHAT") return;
		else if(request == "LIST") c.ListRoom();
		else if(splited.front() == "JOIN") c.JoinRoom(splited.back());
		//else if(splited.front() == "LEAVE") c.LeaveRoom(splited.front());
		else if(request == "quit") exit(0);
		else
			cout << "@Unrecognized command, please reenter." << endl;
	}
}

vector<string> stringSpliter(string& s) {
	stringstream ss(s);
	vector<string> res;
	string item;
	while(getline(ss, item, ' ')) res.push_back(item);
	return res;
}

int main(int argc, char** argv){

	string name(argv[1]);
	Client client(
     grpc::CreateChannel("localhost:50051",
                grpc::InsecureChannelCredentials()), name
			);
#ifdef DEBUG
	cout << "successfully connected to the main server" << endl;
#endif
	client.RegisterClient();

	// command mode

	CommandMode(client);

	return 0;
}
