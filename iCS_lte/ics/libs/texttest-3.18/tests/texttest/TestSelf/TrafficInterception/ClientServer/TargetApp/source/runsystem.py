#!/usr/bin/env python

import os, sys
from threading import Thread
from time import sleep

def null():
    if os.name == "posix":
        return "/dev/null"
    else:
        return "nul"

def runClientThread():
    sleep(4) # give the server chance to start
    os.system("client.py " + os.getenv("TEXTTEST_MIM_SERVER") + " > " + null())

if len(sys.argv) > 1:
    os.system("client.py " + os.getenv("TEXTTEST_MIM_SERVER"))
else:
    if os.getenv("TEXTTEST_RECORDING_TRAFFIC"):
        clientThread = Thread(target=runClientThread)
        clientThread.start()
    os.system("server.py")
