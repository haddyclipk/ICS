#!/usr/bin/env python

import time, sys

sleepTime = sys.argv[1]
sys.stdout.write("Sleeping for " + sleepTime + " seconds...\n")
sys.stdout.flush()
time.sleep(float(sleepTime))
sys.stdout.write(sleepTime + " seconds are up.\n")
sys.stdout.flush()
