
import locale

# Get this with LANG=C on linux
def default_locale():
    return None, None

locale.getdefaultlocale = default_locale
