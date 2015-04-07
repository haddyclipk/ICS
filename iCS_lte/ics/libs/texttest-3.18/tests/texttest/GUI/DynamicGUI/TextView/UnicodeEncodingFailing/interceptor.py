
import locale

def default_locale():
    return "en_US", "utf"

locale.getdefaultlocale = default_locale
