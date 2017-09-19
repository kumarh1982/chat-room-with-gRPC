#include <chrono>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <thread>

#include <grpc/grpc.h>
#include <grpc++/channel.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc++/security/credentials.h>
#include "main.grpc.pb.h"

#define DEBUG;

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientReaderWriter;
using grpc::ClientWriter;
using grpc::Status;
using hw::Request;
using hw::ChatRoom;

using namespace std;

class Client {
	public:
		  Client(shared_ptr<Channel> channel)
					: serverStub(MainServer::NewStub(channel)){};
			void RegisterClient();
			void ListRoom();
			void JoinRoom();
			void LeaveRoom();
			void Chat();
			void PrintRoom();
			void PrintChat();
	private:
			unique_ptr<MainServer::Stub> serverStub;
			vector<unique_ptr<RoomServer::Stub> > roomStubs;
			string name;
			ChatRoom owned;
};

void Client::RegisterClient(){
	Request request;
	ClientContext context;
	
	request.mutable_from()->set_from(this->name);
	Stauts status = serverStub ->RegisterClient(&context, request, &this->owned);
	
	if(!status.ok()) {
		cout << "@Register Client rpc failed." << endl;
	}
}

int main(int argc, char** argv){
	Client client(
     grpc::CreateChannel("localhost:50051",
                grpc::InsecureChannelCredentials())
			);
#ifdef DEBUG
	cout << "successfully connected to the main server" << endl;
#endif

	client.RegisterClient();			
	// command mode
	
	
	return 0;
}
