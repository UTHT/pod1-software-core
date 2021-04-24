// =============================================================================
// Copyright (c) 2013 Christopher Baker <http://christopherbaker.net>
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


#include <Arduino.h>
#include "Encoding/COBS.h"


template<typename EncoderType, uint8_t PacketMarker = 0, int BufferSize = 1024>
class PacketSerial_
{
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

    void begin(unsigned long baud, size_t port = 0)
    {
        switch(port) 
        {
        //#if defined(UBRR1H)
            case 1:
                Serial1.begin(baud);
                _serial = &Serial1;
                break;
        //#endif
        //#if defined(UBRR2H)
            case 2:
                Serial2.begin(baud);
                _serial = &Serial2;
                break;
        //#endif
        //#if defined(UBRR3H)
            case 3:
                Serial3.begin(baud);
                _serial = &Serial3;
                break;
        //#endif
            default:
                Serial.begin(baud);
                _serial = &Serial;
        }
    }

    void update()
    {
        if (_serial == 0) return;

        while (_serial->available() > 0)
        {
            uint8_t data = _serial->read();

            if (data == PacketMarker)
            {
                if (_onPacketFunction) 
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
                    _serial->write("overflow\n");
                }
            }
        }
    }

    void send(const uint8_t* buffer, size_t size)
    {
        if(_serial == 0 || buffer == 0 || size == 0) return;
            size_t numEncoded = EncoderType::encode(buffer, 
                                                    size, 
                                                    _encodeBuffer);

            _serial->write(_encodeBuffer, numEncoded);
            _serial->write(PacketMarker);
            _serial->flush();
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
    uint8_t _decodeBuffer[BufferSize];
    uint8_t _encodeBuffer[BufferSize+500]; // TODO(gizatt) dangerous! may need to be bigger...

    Stream* _serial;
    
    PacketHandlerFunction _onPacketFunction;
    void * _extraArg;

};


typedef PacketSerial_<COBS> PacketSerial;
