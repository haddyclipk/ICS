#!/usr/bin/env python

import os

os.system("editor.py --rootdir=" + os.path.abspath("writedir"))
print open("writedir/link").read()
print os.path.realpath("writedir/deadlink")
