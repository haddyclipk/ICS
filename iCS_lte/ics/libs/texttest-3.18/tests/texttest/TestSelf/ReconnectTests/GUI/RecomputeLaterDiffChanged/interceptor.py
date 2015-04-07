
import os, time, stat

class UptodateStat:
    def __init__(self, origStat, filename):
        self.origStat = origStat
        self.filename = filename
    def __getattr__(self, name):
        return getattr(self.origStat, name)
    def __getitem__(self, item):
        if item != stat.ST_MTIME or self.filename.find("TargetApp") != -1:
            return self.origStat[item]
        else:
            return time.time()

origStat = os.stat
def myStat(filename):
    info = origStat(filename)
    if filename.endswith(".hello"):
        return UptodateStat(info, filename)
    else:
        return info
    
os.stat = myStat
