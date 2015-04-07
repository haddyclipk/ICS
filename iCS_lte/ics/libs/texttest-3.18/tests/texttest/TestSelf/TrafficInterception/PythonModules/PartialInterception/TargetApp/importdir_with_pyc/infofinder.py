#!/usr/bin/env python

def method():
    return "Real method answer"

def othermethod():
    return "Other Real method answer"

class ClassName:
    @staticmethod
    def staticMethod():
        return "Real static method answer"

    @staticmethod
    def otherStaticMethod():
        return "Other Real static method answer"

    def __repr__(self):
        return "infofinder.ClassName()"

class OtherClassName:
    def method(self):
        return "Real Other Class method answer"

