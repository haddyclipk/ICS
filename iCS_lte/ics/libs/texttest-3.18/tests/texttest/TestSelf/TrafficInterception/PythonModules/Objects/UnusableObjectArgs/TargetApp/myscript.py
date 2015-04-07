#!/usr/bin/env python

import mymodule

class Difficult:
    def __repr__(self):
        return "<You'll never evaluate me!>"

d1 = Difficult()
d2 = Difficult()

print mymodule.callFunction(d1, param=d2)
