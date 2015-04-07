#!/usr/bin/env python

import os, time
from threading import Thread

def run():
    os.system("sleep.py 2")

x = Thread(target=run)
x.start()
time.sleep(0.5)
os.system("sleep.py 0.5")
