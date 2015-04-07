#!/usr/bin/env python

import sys, socket

def runQuery(serverAddress, toSend):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect(serverAddress)
    sock.sendall(toSend)
    sock.shutdown(1)
    response = sock.makefile().read()
    print "Sent to server:", toSend
    print "Got reply:", response
    sock.close()

servAddr = sys.argv[1]
host, port = servAddr.split(":")
serverAddress = (host, int(port))
runQuery(serverAddress, "Here is a string")
runQuery(serverAddress, "Here is a longer string")
runQuery(serverAddress, "terminate")
