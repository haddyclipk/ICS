#!/usr/bin/env python

import sys, os, time

def editFile(fileName):
    file = open(fileName, "a")
    file.write("The Editor has made its mark\n")

time.sleep(1)
fileName = sys.argv[1]
editFile(fileName)
