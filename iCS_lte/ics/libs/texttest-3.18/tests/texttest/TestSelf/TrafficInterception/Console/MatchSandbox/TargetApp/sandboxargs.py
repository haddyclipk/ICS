#!/usr/bin/env python

import subprocess, os
subprocess.call([ "some_program", "--argument", os.getcwd() ])
