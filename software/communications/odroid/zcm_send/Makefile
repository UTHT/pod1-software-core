CC = g++
CFLAGS = $(INCLUDES) -g -Wall
TARGET = zcm_send

# Common directories
LIBRARIES_FOLDER = ../../libraries

# Instead of using relative paths within each .cpp/.c or header file, define it here.
INCLUDES += -I$(LIBRARIES_FOLDER)
INCLUDES += -I$(LIBRARIES_FOLDER)/libserial/src
INCLUDES += -I$(LIBRARIES_FOLDER)/linux_cobs_serial_transport
INCLUDES += -I$(LIBRARIES_FOLDER)/zcm
INCLUDES += -I$(LIBRARIES_FOLDER)/zcm_types/src/

# VPATH is used to define where the arguments of each rule are located
VPATH += $(LIBRARIES_FOLDER)/linux_cobs_serial_transport
VPATH += $(LIBRARIES_FOLDER)/libserial/src
VPATH += $(LIBRARIES_FOLDER)/zcm
VPATH += $(LIBRARIES_FOLDER)/zcm_types/src/

# Final objects needed to build the zcm_send executable file
OBJECTS = zcm_send.o linux_cobs_serial_transport.o SerialStream.o SerialStreamBuf.o zcm.o nonblocking.o test_msg.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

zcm_send.o: zcm_send.cpp
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
