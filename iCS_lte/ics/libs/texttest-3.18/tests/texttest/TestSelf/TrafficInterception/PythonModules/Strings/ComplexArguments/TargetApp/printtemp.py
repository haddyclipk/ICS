#!/usr/bin/env python

import tempfile

strVal = u"""This
is a large unicode string"""

withQuote = """This one
has a ' in it"""

try:
    print tempfile.gettempprefix({ "string" : strVal, "quotestring": withQuote })
except Exception, e:
    pass
