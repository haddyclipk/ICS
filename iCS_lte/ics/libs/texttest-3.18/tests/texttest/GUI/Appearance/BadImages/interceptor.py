
import gtk, os

def pixbuf_broken(icon):
    raise Exception, "Didn't like the look of image '" + os.path.basename(icon) + "'"

gtk.gdk.pixbuf_new_from_file = pixbuf_broken
