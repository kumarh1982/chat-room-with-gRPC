#chat room with gRPC

* generate interfaces and stubs from proto

  chmod +x ./update.sh
  ./update.sh

* compile cc files

  make

* clean all the files mentioned above

  make clean

* to execute

  ./server
  ./client
