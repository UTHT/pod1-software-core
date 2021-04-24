from twisted.internet.protocol import ReconnectingClientFactory
from autobahn.twisted.websocket import WebSocketClientProtocol, WebSocketClientFactory
from twisted.python import log
from twisted.internet import reactor

import json
import subprocess

server = "127.0.0.1"  # Server IP Address
port = 8080  # Server Port

streaming_process = None

class AppProtocol(WebSocketClientProtocol):

    def onConnect(self, response):
        print("Connected to the node server at 127.0.0.1:8080/")
        self.factory.resetDelay()

    def onOpen(self):
        print("Connection is open.")

        # when connection is open we send a test message the the server.

        def hello_server():
            with open('./test.json') as f:
                data = json.load(f)
            
            print(data)
            print(val)

            message = {"action": "pi_online", "payload": {"id": "tabvn", "secret": "key"}}

            self.sendMessage(json.dumps(message).encode('utf8'), isBinary = False)
            # self.sendMessage(u"Pi Here do you have any any job for me to do ?".encode('utf8'))

        hello_server()

    def onMessage(self, payload, isBinary):
        if (isBinary):
            print("Got Binary message {0} bytes".format(len(payload)))
        else:
            print("Got Text message from the server {0}".format(payload.decode('utf8')))
            # need to decode this message and know what is server command

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

    print("Please select the Testing Options (number): \n \t 1: Speed \n \t 2: Temperature")
    val = input("Enter your value: ")
    
    

    factory = AppFactory(u"ws://{0}".format(server).format(":").format(port))
    reactor.connectTCP(server, port, factory)
    reactor.run()