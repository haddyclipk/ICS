
import socket, time

origSocket = socket.socket

class BadSocket(origSocket):
    def connect(self, *args, **kwargs):
        raise socket.error, "Can't connect to non-existent machines!"
        
def fakeSleep(*args):
    pass

socket.socket = BadSocket
time.sleep = fakeSleep
