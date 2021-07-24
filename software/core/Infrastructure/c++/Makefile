CC = g++ -std=c++11
#CC = g++ -std=c++11
LDFLAGS=  -L/usr/local/opt/openssl/lib
CPPFLAGS= -I/usr/local/opt/openssl/include

socket: socket.cpp
	$(CC) socket.cpp -o socket -pthread -lboost_system -lcrypto -lssl -lcpprest

	
all: socket

clean:
	rm -rf *.o socket *.dSYM
