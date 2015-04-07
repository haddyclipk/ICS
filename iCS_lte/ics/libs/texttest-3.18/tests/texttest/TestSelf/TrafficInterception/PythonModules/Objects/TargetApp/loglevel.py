#!/usr/bin/env python

import logging

logger = logging.getLogger("""Some Multiline
Logger""")
if isinstance(logger, logging.Logger):
    print logger.getEffectiveLevel() / 10
    print "Nonsense attributes = " + repr(hasattr(logger, "nonsense"))
else:
    print "Strange type here!"

