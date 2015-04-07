#!/usr/bin/env python

from glob import glob

for fileName in sorted(glob("*.properties")):
    print fileName
    print "......."
    print open(fileName).read()
