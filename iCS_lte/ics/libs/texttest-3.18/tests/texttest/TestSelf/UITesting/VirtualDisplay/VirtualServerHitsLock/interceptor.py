
import os

# Basic point is to map the process IDs to a predictable increasing sequence

realpid = str(os.getpid())

def getpid():
    if os.path.isfile("xvfblock"):
        prevrealpid, prevgivenpid = open("xvfblock").read().strip().split()
        if prevrealpid == realpid:
            return int(prevgivenpid)
        else:
            givenpid = int(prevgivenpid) + 1
    else:
        givenpid = 1

    open("xvfblock", "w").write(realpid + " " + str(givenpid))
    return givenpid

os.getpid = getpid
