
import os, subprocess

def getpid():
    # my first phone number :)
    return 3979

RealPopen = subprocess.Popen
class NoXvfbPopen(RealPopen):
    def __init__(self, cmdArgs, *args, **kwargs):
        if cmdArgs[0] == "Xvfb":
            raise OSError, "No Xvfb running here!"
        RealPopen.__init__(self, cmdArgs, *args, **kwargs)

os.getpid = getpid
subprocess.Popen = NoXvfbPopen
