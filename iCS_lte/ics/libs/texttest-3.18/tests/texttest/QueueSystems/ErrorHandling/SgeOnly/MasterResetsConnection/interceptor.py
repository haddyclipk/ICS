
import socket, time

origSocket = socket.socket

class ResettingSocket(origSocket):
    callCount = 0
    def sendall(self, *args, **kwargs):
        ResettingSocket.callCount += 1
        if ResettingSocket.callCount >= 3:
            raise socket.error, "Connection reset by peer"
        else:
            return origSocket.sendall(self, *args, **kwargs)

def fakeSleep(*args):
    pass

socket.socket = ResettingSocket
time.sleep = fakeSleep
