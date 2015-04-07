
import os, time, stat

class UptodateStat:
    def __init__(self, origStat, filename):
        self.origStat = origStat
        self.filename = filename
    def __getattr__(self, name):
        return getattr(self.origStat, name)
    def __getitem__(self, item):
        origItem = self.origStat[item]
        if item != stat.ST_MTIME or not "TargetApp" in self.filename or abs(time.time() - origItem) < 60:
            return origItem
        else:
            return origItem - 60 * 60 * 24 * 365

origStat = os.stat
def myStat(filename):
    info = origStat(filename)
    if "hello" in filename:
        return UptodateStat(info, filename)
    else:
        return info
    
os.stat = myStat
