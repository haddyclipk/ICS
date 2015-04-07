
"""
Utilities for both master and slave code
"""

def queueSystemName(app):
    return app.getConfigValue("queue_system_module")

def socketSerialise(test):
    return test.app.name + test.app.versionSuffix() + ":" + test.getRelPath()        
