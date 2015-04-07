#!/usr/bin/env python

import infofinder

print infofinder.method()
print infofinder.othermethod()
print infofinder.ClassName.staticMethod()
print infofinder.ClassName.otherStaticMethod()
print infofinder.ClassName().otherStaticMethod()

class MyClassName(infofinder.OtherClassName):
    pass

print MyClassName().method()
