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

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientReaderWriter;
using grpc::ClientWriter;
using grpc::Status;
using hw::Request;
using hw::ChatRoom;
using hw::MainServer;

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
	private:
			unique_ptr<MainServer::Stub> serverStub;
			vector<unique_ptr<RoomServer::Stub> > roomStubs;
};

int main(int argc, char** argv){
	Client client(
     grpc::CreateChannel("localhost:50051",
                grpc::InsecureChannelCredentials())
			);
	

/*
  client.ListRoom();

  client.JoinRoom();

  client.LeaveRoom();

  client.Chat();
*/
	return 0;
}
