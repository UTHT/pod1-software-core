CC = g++
INCLUDES = -I../libraries -I../libraries/libserial/src -I../libraries/linux_cobs_serial_transport
VPATH = ../libraries/linux_cobs_serial_transport ../libraries/libserial/src ../libraries/zcm ../libraries/zcm_types/src/
CFLAGS = $(INCLUDES) -g -Wall
TARGET = zcm_receive
OBJECTS = zcm_receive.o linux_cobs_serial_transport.o SerialStream.o SerialStreamBuf.o zcm.o nonblocking.o test_msg.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

zcm_receive.o: zcm_receive.cpp
	$(CC) -c $(CFLAGS) $^ -o $@
	
linux_cobs_serial_transport.o: linux_cobs_serial_transport.cpp
	$(CC) -c $(CFLAGS) $^ -o $@

SerialStream.o: SerialStream.cc
	$(CC) -c $(CFLAGS) $^ -o $@

SerialStreamBuf.o: SerialStreamBuf.cc
	$(CC) -c $(CFLAGS) $^ -o $@

test_msg.o: test_msg.c
	gcc -c $(CFLAGS) $^ -o $@

zcm.o: zcm.c nonblocking.o
	gcc -c $(CFLAGS) $^ -o $@

nonblocking.o: nonblocking.c
	gcc -c $(CFLAGS) $^ -o $@
