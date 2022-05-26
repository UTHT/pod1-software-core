CC = g++ -std=c++11
#CC = g++ -std=c++11
LDFLAGS=  -L/usr/local/opt/openssl/lib
CPPFLAGS= -I/usr/local/opt/openssl/include

socket: socketBoost.cpp
	$(CC) socketBoost.cpp -o socket -pthread 
	
all: socket

clean:
	rm -rf *.o socket *.dSYM
