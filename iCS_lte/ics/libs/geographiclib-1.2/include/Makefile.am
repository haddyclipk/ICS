#
# Makefile.am
#
# Copyright (C) 2009, Francesco P. Lovergine <frankie@debian.org>
# $Id: Makefile.am 6822 2010-03-11 13:10:13Z flovergine $

nobase_include_HEADERS = GeographicLib/AzimuthalEquidistant.hpp \
				GeographicLib/CassiniSoldner.hpp \
				GeographicLib/Constants.hpp \
				GeographicLib/DMS.hpp \
				GeographicLib/EllipticFunction.hpp \
				GeographicLib/Geocentric.hpp \
				GeographicLib/GeoCoords.hpp \
				GeographicLib/Geodesic.hpp \
				GeographicLib/Geoid.hpp \
				GeographicLib/LambertConformalConic.hpp \
				GeographicLib/LocalCartesian.hpp \
				GeographicLib/MGRS.hpp \
				GeographicLib/PolarStereographic.hpp \
				GeographicLib/TransverseMercatorExact.hpp \
				GeographicLib/TransverseMercator.hpp \
				GeographicLib/UTMUPS.hpp

geoids_dir=$(datadir)/GeographicLib/geoids

DEFS=-DGEOID_DEFAULT_PATH=\"$(geoids_dir)\"  @DEFS@

EXTRA_DIST = Makefile.mk
