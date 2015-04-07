#!/usr/bin/env python
"""
@file    apply_astyle.py
@author  Michael.Behrisch@dlr.de
@date    2007
@version $Id: apply_astyle.py 8385 2010-03-05 20:51:30Z behrisch $

Applies astyle with the proper settings used in SUMO on all
 files in src.

Copyright (C) 2008 DLR/TS, Germany
All rights reserved
"""

import os, os.path, sys

srcRoot = os.path.join(os.path.dirname(sys.argv[0]), "../../src/")
for root, dirs, files in os.walk(srcRoot):
    for name in files:
        if name.endswith(".h") or name.endswith(".cpp"):
            os.system("astyle --style=kr -U -l -n " + os.path.join(root, name))
        for ignoreDir in ['.svn', 'foreign']:
            if ignoreDir in dirs:
                dirs.remove(ignoreDir)
