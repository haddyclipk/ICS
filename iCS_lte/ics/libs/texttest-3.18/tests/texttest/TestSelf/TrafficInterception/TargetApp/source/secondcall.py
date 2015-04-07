#!/usr/bin/env python

import os, sys

sys.stderr.write("secondcall.py called with " + repr(sys.argv[1:]) + " as arguments\n" + \
                 "MY_ENV_VAR = " + repr(os.getenv("MY_ENV_VAR")) + "\n")

print "The current working directory is", os.path.basename(os.getcwd())
print "The process ID is", os.getpid()
