CC = g++
CFLAGS = $(INCLUDES) -g -Wall
TARGET = channel_handler

# Common directories
LIBRARIES_FOLDER = ../../libraries

# Instead of using relative paths within each .cpp/.c or header file, define it here.
INCLUDES += -I$(LIBRARIES_FOLDER)
INCLUDES += -I$(LIBRARIES_FOLDER)/libserial/src
INCLUDES += -I$(LIBRARIES_FOLDER)/linux_cobs_serial_transport
INCLUDES += -I$(LIBRARIES_FOLDER)/zcm
INCLUDES += -I$(LIBRARIES_FOLDER)/zcm_types/src/
INCLUDES += -I$(LIBRARIES_FOLDER)/../channels/

# VPATH is used to define where the arguments of each rule are located
VPATH += $(LIBRARIES_FOLDER)/linux_cobs_serial_transport
VPATH += $(LIBRARIES_FOLDER)/libserial/src
VPATH += $(LIBRARIES_FOLDER)/zcm
VPATH += $(LIBRARIES_FOLDER)/zcm_types/src/
VPATH += $(LIBRARIES_FOLDER)/../channels/

# Final objects needed to build the channel_handler executable file
OBJECTS = channel_handler.o linux_cobs_serial_transport.o SerialStream.o SerialStreamBuf.o zcm.o nonblocking.o channel_msg.o channel.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

channel_handler.o: channel_handler.cpp
	$(CC) -c  -std=c++11 $(CFLAGS) $^ -o $@
	
linux_cobs_serial_transport.o: linux_cobs_serial_transport.cpp
	$(CC) -c  -std=c++11 $(CFLAGS) $^ -o $@

channel.o: channel.cpp
	$(CC) -c  -std=c++11 $(CFLAGS) $^ -o $@

SerialStream.o: SerialStream.cc
	$(CC) -c $(CFLAGS) $^ -o $@

SerialStreamBuf.o: SerialStreamBuf.cc
	$(CC) -c $(CFLAGS) $^ -o $@

channel_msg.o: channel_msg.c
	gcc -c $(CFLAGS) $^ -o $@

zcm.o: zcm.c nonblocking.o
	gcc -c $(CFLAGS) $^ -o $@

nonblocking.o: nonblocking.c
	gcc -c $(CFLAGS) $^ -o $@
