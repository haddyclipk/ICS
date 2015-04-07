#!/usr/bin/env python

import mymodule

theObject = mymodule.MyObject()
theObject.value = "My Value"
theObject.itself = theObject
print theObject.itself.getValue()
