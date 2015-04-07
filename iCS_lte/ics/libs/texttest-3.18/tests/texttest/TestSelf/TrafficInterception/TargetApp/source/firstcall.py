#!/usr/bin/env python

import sys, time
print "firstcall.py called with", len(sys.argv), "arguments"
print "The time is now", time.asctime()
sys.exit(1)
