import gtk, gobject, sys, os, logging

sys.version_info = 2, 9, 42, "final", 0
gtk.pygtk_version = 2, 42, 0
gtk.gtk_version = 2, 58, 42
gobject.pygobject_version = 2, 61, 42
gobject.glib_version = 2, 74, 42

# Credits have Swedish names, fix the locale to UTF-8
import locale

def default_locale():
    return "en_US", "utf"

locale.getdefaultlocale = default_locale

def my_startfile(fileName):
    print "Called startfile on", fileName
    sys.stdout.flush()

os.startfile = my_startfile
