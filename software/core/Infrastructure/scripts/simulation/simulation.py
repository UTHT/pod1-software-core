from twisted.internet.protocol import ReconnectingClientFactory
from autobahn.twisted.websocket import WebSocketClientProtocol, WebSocketClientFactory,  connectWS
from twisted.python import log
from twisted.internet import reactor
import time
import json
import subprocess

server = "127.0.0.1"  # Server IP Address
port = 8080  # Server Port
SEND_COUNT = 30
streaming_process = None
with open('./test.json') as f:
    raw_data = json.load(f)

class AppProtocol(WebSocketClientProtocol):

    def onConnect(self, response):
        print("Connected to the node server at 127.0.0.1:8080/")
        self.factory.resetDelay()
    
    def FirstMessage(self):
        firstMsg = {'eventType':'connection','data':{'clientType':'odroid'},'isNew':1}
        self.sendMessage(json.dumps(firstMsg).encode('utf8'), isBinary = False)

    def sendOneOdroidMessage(self):
        data = raw_data['data']

        if self.count < 20:
            data['velocity'][0]['value'] += 30

            data['temperature'][0]['value'] += 1
            data['temperature'][1]['value'] += 3
            data['temperature'][2]['value'] += 1
            # data['temperature'][3]['value'] += 1

            data['pressure'][2]['value'] -= 1
            data['pressure'][1]['value'] -= 2

            data['pressure'][2]['status'] = 1
            data['pressure'][2]['value'] +=10
            data['pressure'][1]['status'] = 1
            data['pressure'][1]['value'] +=20
            data['gap_height'][0]['value'] += 0.5
            data['vibrations'][0]['value'] +=0.5

            data['battery'][0]['value'] -= 0.5
            data['battery'][1]['value'] -=1

        elif  self.count  < 56:
            data['pressure'][2]['status'] = 1
            data['pressure'][2]['value'] +=10
            data['pressure'][1]['status'] = 1
            data['pressure'][1]['value'] +=10

            data['velocity'][0]['value'] -= 30

            data['temperature'][0]['value'] -= 0.5
            data['temperature'][1]['value'] -= 1
            data['temperature'][2]['value'] += 1
            data['gap_height'][0]['value'] -= 0.5
            data['vibrations'][0]['value'] += 0.5

            data['battery'][0]['value'] -= 1.5
            data['battery'][1]['value'] -=0.5
            # data['temperature'][3]['value'] += 1
            # data['temperature'][2]['value'] += 3
            # data['temperature'][3]['value'] += 3
        self.sendMessage(json.dumps(raw_data).encode('utf8'), isBinary = False)
                


    def onOpen(self):
        print("Connection is open.")
        self.count = 0
        self.FirstMessage()

    def onMessage(self, payload, isBinary):
        if (isBinary):
            print("Got Binary message {0} bytes".format(len(payload)))
        else:
            print("Got Text message from the server {0}".format(payload.decode('utf8')))
        
        self.count +=1
        if self.count < SEND_COUNT:
            # Change speed
            time.sleep(0.3)
            self.sendOneOdroidMessage()

    def onClose(self, wasClean, code, reason):
        print("Connect closed {0}".format(reason))


class AppFactory(WebSocketClientFactory, ReconnectingClientFactory):
    protocol = AppProtocol

    def clientConnectionFailed(self, connector, reason):
        print("Unable connect to the server {0}".format(reason))
        self.retry(connector)

    def clientConnectionLost(self, connector, reason):
        print("Lost connection and retrying... {0}".format(reason))
        self.retry(connector)


if __name__ == '__main__':
    import sys


    log.startLogging(sys.stdout)
    
    factory = AppFactory(u"ws://{0}".format(server + ":" + str(port)))
    reactor.connectTCP(server, port, factory)
    connectWS(factory)
    reactor.run()