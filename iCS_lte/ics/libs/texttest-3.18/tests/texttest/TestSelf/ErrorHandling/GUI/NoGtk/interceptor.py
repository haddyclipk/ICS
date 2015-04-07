
import __builtin__

origImport = __builtin__.__import__
def myImport(name, *args, **kwargs):
    if name == "gtk":
        raise ImportError, "No module named gtk"
    else:
        return origImport(name, *args, **kwargs)

__builtin__.__import__ = myImport
