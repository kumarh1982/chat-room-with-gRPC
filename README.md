#chat room with gRPC

* generate interfaces and stubs from proto

  chmod +x ./update.sh <br>
  ./update.sh

* compile cc files

  make

* clean all the files mentioned above

  make clean

* to execute

  <br> note: there will be some parameter passed to program, username, port num, etc later

  ./server <br>
  ./client
