// =============================================================================
// Copyright (c) 2016 Gregory Izatt, MIT Hyperloop Team
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================

#pragma once

#include "Encoding/COBS.h"

#include <SerialStream.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>


using namespace LibSerial ;

template<typename EncoderType, uint8_t PacketMarker = 0, int BufferSize = 1024>
class PacketSerial_
{
private:
    uint8_t _decodeBuffer[BufferSize];

public:
    typedef void (*PacketHandlerFunction)(const uint8_t* buffer, size_t size, void * extra);

    PacketSerial_():
        _recieveBufferIndex(0),
        _serial(0),
        _onPacketFunction(0),
        _extraArg(0)
    {
    }

    ~PacketSerial_()
    {
    }

    bool begin(unsigned long baud, char * port)
    {       
        //
        // Open the serial port.
        // ;
        _serial = new SerialStream();
        _serial->Open( port );  
        if ( ! _serial->good() ) 
        {
            std::cerr << "[" << __FILE__ << ":" << __LINE__ << "] "
                      << "Error: Could not open serial port." 
                      << std::endl ;
            exit(1) ;
        }
        //
        // Set the baud rate of the serial port.
        SerialStreamBuf::BaudRateEnum baud_enum;
        if (baud == 115200){
            baud_enum = SerialStreamBuf::BAUD_115200;
        }
        else if (baud == 230400){
            baud_enum = SerialStreamBuf::BAUD_230400;
        }
        else{
            std::cerr << "Unsupported baud rate of " << baud << " in PacketSerialLinux.h" << std::endl;
            exit(1);
        }

        _serial->SetBaudRate( baud_enum ) ;
        if ( ! _serial->good() ) 
        {
            std::cerr << "Error: Could not set the baud rate." << std::endl ;
            exit(1) ;
        }
        //
        // Set the number of data bits.
        //
        _serial->SetCharSize( SerialStreamBuf::CHAR_SIZE_8 ) ;
        if ( ! _serial->good() ) 
        {
            std::cerr << "Error: Could not set the character size." << std::endl ;
            exit(1) ;
        }
        //
        // Disable parity.
        //
        _serial->SetParity( SerialStreamBuf::PARITY_NONE ) ;
        if ( ! _serial->good() ) 
        {
            std::cerr << "Error: Could not disable the parity." << std::endl ;
            exit(1) ;
        }
        //
        // Set the number of stop bits.
        //
        _serial->SetNumOfStopBits( 1 ) ;
        if ( ! _serial->good() ) 
        {
            std::cerr << "Error: Could not set the number of stop bits."
                      << std::endl ;
            exit(1) ;
        }
        //
        // Turn off hardware flow control.
        //
        _serial->SetFlowControl( SerialStreamBuf::FLOW_CONTROL_NONE ) ;
        if ( ! _serial->good() ) 
        {
            std::cerr << "Error: Could not use hardware flow control."
                      << std::endl ;
            exit(1) ;
        }
    }

    void update()
    {
        if (_serial == 0) return;

        while (_serial->good() && _serial->rdbuf()->in_avail() > 0){
            char charin;
            _serial->get(charin);
            if (!_serial->good()){
                printf("Serial fail during getchar.\n");
                _serial->clear();
                continue;
            }
            uint8_t data = (uint8_t) charin;
            if (data == PacketMarker)
            {
                if (_recieveBufferIndex > 0 && _onPacketFunction) 
                {

                    size_t numDecoded = EncoderType::decode(_recieveBuffer, 
                                                            _recieveBufferIndex, 
                                                            _decodeBuffer);

                    _onPacketFunction(_decodeBuffer, numDecoded, _extraArg);
                }

                _recieveBufferIndex = 0;
            }
            else
            {
                if ((_recieveBufferIndex + 1) < BufferSize)
                {
                    _recieveBuffer[_recieveBufferIndex++] = data;
                }
                else
                {
                    // Error, buffer overflow if we write.
                }
            }
        }
    }

    void send(const uint8_t* buffer, size_t size)
    {
        if(_serial == 0 || buffer == 0 || size == 0) return;

        uint8_t _encodeBuffer[EncoderType::getEncodedBufferSize(size)];

        size_t numEncoded = EncoderType::encode(buffer, 
                                                size, 
                                                _encodeBuffer);

        _serial->write((char *)_encodeBuffer, numEncoded);
        char marker = (char) PacketMarker;
        _serial->write(&marker, 1);
        _serial->flush();

        if (!_serial->good()){
            printf("Serial failure during send.\n");
            _serial->clear();
        }
    }
    
    void setPacketHandler(PacketHandlerFunction onPacketFunction, void * extra)
    {
        _onPacketFunction = onPacketFunction;
        _extraArg = extra;
    }


private:
    PacketSerial_(const PacketSerial_&);
    PacketSerial_& operator = (const PacketSerial_&);

    uint8_t _recieveBuffer[BufferSize];
    size_t _recieveBufferIndex;
        
    SerialStream * _serial;
    
    PacketHandlerFunction _onPacketFunction;
    void * _extraArg;

};


typedef PacketSerial_<COBS> PacketSerial;
