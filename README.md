#chat room with gRPC

* generate interfaces and stubs from proto

  chmod +x ./update.sh <br>
  ./update.sh

* compile cc files

  make

* clean all the files mentioned above

  make clean

* to execute

  <br> note: there will be other parameters passed to program, port num, etc later
  <br> for now it's just username

  ./server <br>
  ./client username

* unresolved problems yet
<ol>
  <li>thread ID is negative in console : thread_t type to int 32 conversion</li>
  <li>find next available port for new chat room</li>
</ol>
