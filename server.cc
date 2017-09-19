#include <string>
#include <iostream>
#include <chrono>
#include <memory>

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

class MainServerImpl final : public MainServer::Service {
	public:

		MainServerImpl(){;}
		
		Status RegisterClient(ServerContext* context, const Request* request,
												ChatRoom* response) override{;}
		
		Status ListRoom(ServerContext* context, const Request* request,
										ServerWriter<ChatRoom>* response) override{;}
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




int main(int argc, char** argv){
	RunServer();
	return 0;
}
