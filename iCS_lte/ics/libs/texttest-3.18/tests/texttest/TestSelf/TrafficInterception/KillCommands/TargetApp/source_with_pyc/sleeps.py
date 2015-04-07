#!/usr/bin/env python

import os, time, subprocess, signal
from jobprocess import JobProcess

def showExitCode(exitCode):
    # We cheat on Windows where killed processes don't have
    # exit codes
    if os.name == "posix":
        return exitCode
    else:
        return -15

proc = subprocess.Popen([ "sleep", "100" ])
time.sleep(1)
if proc.poll():
    print "Process terminated already."
else:
    JobProcess(proc.pid).killAll(signal.SIGTERM)
    exitCode = proc.wait()
    print "Terminated process: exit code was", showExitCode(exitCode)
