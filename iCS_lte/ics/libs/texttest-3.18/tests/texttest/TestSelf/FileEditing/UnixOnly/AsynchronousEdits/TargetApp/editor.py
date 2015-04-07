#!/usr/bin/env python

import sys, subprocess, os

fileName = sys.argv[1]
print "Editing file", fileName
sys.stdout.flush()
subprocess.Popen([ "realeditor.py", fileName ], shell=os.name=="nt", stdin=open(os.devnull), stdout=open(os.devnull, "w"), stderr=open(os.devnull, "w"))
