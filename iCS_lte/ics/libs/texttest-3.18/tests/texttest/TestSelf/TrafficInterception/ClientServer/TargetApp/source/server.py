#!/usr/bin/env python

from SocketServer import TCPServer, StreamRequestHandler
import sys, os, socket

def createSocket():
    servAddr = os.getenv("TEXTTEST_MIM_SERVER")
    if servAddr:
        host, port = servAddr.split(":")
        serverAddress = (host, int(port))
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.connect(serverAddress)
        return sock

def sendServerState(stateDesc):
    sock = createSocket()
    if sock:
        sock.sendall("SUT_SERVER:" + stateDesc + "\n")
        sock.close()

class MyRequestHandler(StreamRequestHandler):
    calledBefore = False
    def handle(self):
        if not self.calledBefore:
            MyRequestHandler.calledBefore = True
            return
        clientData = self.rfile.read()
        if clientData.strip() == "terminate":
            self.wfile.write("Exiting...")
            global gotExit
            gotExit = True
        else:
            self.wfile.write("Length was " + str(len(clientData)))

server = TCPServer((socket.gethostname(), 0), MyRequestHandler)
host, port = server.socket.getsockname()
address = host + ":" + str(port)
message = "Started string-length server at " + address
sendServerState(message)
print message
sys.stdout.flush()

gotExit = False
while not gotExit:
    server.handle_request()
