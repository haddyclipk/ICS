
import locale

def default_locale():
    return "en_US", "ISO8859-1"

locale.getdefaultlocale = default_locale
