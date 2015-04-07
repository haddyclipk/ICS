import __builtin__

realGtk = None

class MyGtkModule:
    def __init__(self):
        self.pygtk_version = 2, 2, 0
    def __getattr__(self, name):
        return getattr(realGtk, name)

origImport = __builtin__.__import__
def myImport(name, *args, **kwargs):
    if name == "gtk":
        global realGtk
        realGtk = origImport(name, *args, **kwargs)
        return MyGtkModule()
    else:
        return origImport(name, *args, **kwargs)

__builtin__.__import__ = myImport
