#!/usr/bin/env python

import mymodule

try:
    mymodule.callFunction()
except Exception, e:
    print "Caught exception", e
    
