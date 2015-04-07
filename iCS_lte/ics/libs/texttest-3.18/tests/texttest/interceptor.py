
# Make sure the tests with Swedish chars work correctly
# on systems with other default locales than ISO8859-1 ...

import locale

def default_locale():
    return "en_US", "ISO8859-1"

locale.getdefaultlocale = default_locale
