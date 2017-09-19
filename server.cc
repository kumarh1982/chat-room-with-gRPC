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

		MainServerImpl(){;}
		
		Status RegisterClient(ServerContext* context, const Request* request,
												ChatRoom* response) override;
		
		Status ListRoom(ServerContext* context, const Request* request,
										ServerWriter<ChatRoom>* response) override;
		Status JoinRoom(ServerContext* context, const Request* request,
										Request* response) override{;}
		Status LeaveRoom(ServerContext* context, const Request* request,
										Request* response) override{;}
		Status Chat(ServerContext* context, const Request* request,
								Request* response) override{;}
								
	private:
	
		map<string, unique_ptr<ChatRoom> > chatRooms;
		map<string, unique_ptr<Client> > clients;
};

class RoomServerImpl final : public RoomServer::Service{
	public:
		RoomServerImpl();
		Status Chat(ServerContext* context, 
								ServerReaderWriter<Request, Request>* stream) override;
	private:
		void WriteToFile();
		unique_ptr<ChatRoom> chatRoom;
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
	unique_ptr<Client> c;
	c->mutable_name()->set_name(who);
		
	unique_ptr<ChatRoom> cr(c->add_chatroom());
	// TO-DO : find next available port
	int port;
	pthread_t thread;
	pthread_create(&thread, NULL, RunRoom, (void*)&port);
	cr->mutable_owner()->set_owner(who);
	cr->mutable_thread()->set_thread(thread);
	cr->mutable_port()->set_port(port);
	
	// cr->add_clients();
	
	this->clients.insert(make_pair(who, c));
	this->chatRooms.insert(make_pair(who, cr));
	
	response = cr;
}

Status
MainServerImpl::
ListRoom(ServerContext* context, 
					const Request* request,
					ServerWriter<ChatRoom>* writer) {
	// traverse the chat room databases
	// identify the chat room owned by querying client
	for(const auto& cr : this->chatRooms) {
		writer->Write(cr);
	}
	return Status::OK;
}

Status
MainServerImpl::
JoinRoom(ServerContext* context,
				 const Request* request,
					Request* response) {
	// add client to chat room list
}

Status
MainServerImpl::
LeaveRoom(ServerContext* context,
					const Request* request,
					Request* response) {
										
}

Status
MainServerImpl::
Chat(ServerContext* context,
		 const Request* request,
			Request* response) {
								
}

/*------------------------------------Chat Room Server------------------------------------------*/

void* RunRoom(void* param) {
	// TO-DO: find next available port
	int* o = (int*)param;
	int port = *o;
	string server_address("localhost:50051");
	RoomServerImpl service;
	
  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Chat Room listening on " << server_address << std::endl;
	server->Wait();
}

int main(int argc, char** argv){
	RunServer();
	return 0;
}
