cd ./protos
protoc -I=. --cpp_out=. ./main.proto
cd ..
make main.grpc.pb.cc main.pb.cc
