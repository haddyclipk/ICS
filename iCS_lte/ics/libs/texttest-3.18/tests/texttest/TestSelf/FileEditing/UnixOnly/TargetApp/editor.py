#!/usr/bin/env python

import sys, os

fileName = sys.argv[1].split("=")[1]
dirName = fileName + "/subdir"
os.makedirs(dirName)
open(dirName + "/file", "w").write("dummy\n")
os.symlink(dirName, fileName + "/dirlink")
os.symlink(fileName + "/dirlink/file", fileName + "/link")
os.symlink("/into/the/void", fileName + "/deadlink")
