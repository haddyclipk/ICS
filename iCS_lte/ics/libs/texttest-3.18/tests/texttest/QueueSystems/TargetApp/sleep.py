#!/usr/bin/env python

import sys, time

def getSleepLength():
    if len(sys.argv) > 1:
        return int(sys.argv[1])
    else:
        return 5

try:
    sleepLength = getSleepLength()
    print "Sleeping for", sleepLength, "seconds..."
    sys.stdout.flush()
    time.sleep(sleepLength)
    print "Done"
except KeyboardInterrupt:
    pass
