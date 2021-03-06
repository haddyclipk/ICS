#!/usr/bin/env python

import signal, os

gotSignal, sentInfo = 0, False

def makeSocket():
    import socket
    try:
        return socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    except AttributeError: # in case we get interrupted partway through
        reload(socket)
        return socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    
def createSocket():
    servAddr = os.getenv("TEXTTEST_MIM_SERVER")
    if servAddr:
        host, port = servAddr.split(":")
        serverAddress = (host, int(port))
        sock = makeSocket()
        sock.connect(serverAddress)
        return sock

def sendKill():
    sock = createSocket()
    text = "SUT_COMMAND_KILL:" + str(gotSignal) + ":SUT_SEP:" + str(os.getpid())
    sock.sendall(text)
    sock.close()

def handleKill(sigNum, *args):
    global gotSignal
    gotSignal = sigNum
    if sentInfo:
        sendKill()

if os.name == "posix":
    signal.signal(signal.SIGINT, handleKill)
    signal.signal(signal.SIGTERM, handleKill)

def readFromSocket(sock):
    from socket import error
    try:
        return sock.makefile().read()
    except error: # If we're interrupted, try again
        return sock.makefile().read()

def getCommandLine():
    from sys import argv
    if os.name == "posix":
        return argv
    else:
        base = os.path.splitext(argv[0])[0]
        return [ base ] + argv[1:]

def createAndSend():
    sock = createSocket()
    text = "SUT_COMMAND_LINE:" + repr(getCommandLine()) + ":SUT_SEP:" + repr(os.environ) + \
           ":SUT_SEP:" + os.getcwd() + ":SUT_SEP:" + str(os.getpid())
    sock.sendall(text)
    return sock

def infoSent():
    global sentInfo
    if gotSignal:
        sendKill()
    sentInfo = True
        
if __name__ == "__main__":
    sock = createAndSend()
    sock.shutdown(1)
    infoSent()
    response = readFromSocket(sock)
    sock.close()
    try:
        stdout, stderr, exitStr = response.split("|TT_CMD_SEP|")
        import sys
        sys.stdout.write(stdout)
        sys.stdout.flush()
        sys.stderr.write(stderr)
        sys.stderr.flush()
        exitCode = int(exitStr)
        if exitCode < 0:
            # process was killed (on UNIX...)
            # We should hang if we haven't been killed ourselves (though we might be replaying on Windows anyway)
            if os.name == "posix":
                signal.signal(signal.SIGINT, signal.SIG_DFL)
                signal.signal(signal.SIGTERM, signal.SIG_DFL)
                if gotSignal:
                    os.kill(os.getpid(), gotSignal)
                else:
                    signal.pause()
            else:
                import time
                time.sleep(10000) # The best we can do on Windows where waiting for signals is concerned :)
        else:
            sys.exit(exitCode)
    except ValueError:
        from sys import stderr
        stderr.write("Received unexpected communication from MIM server:\n " + response + "\n\n")

