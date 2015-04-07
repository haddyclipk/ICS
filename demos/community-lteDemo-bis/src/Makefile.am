XERCES_LIBS = -l$(LIB_XERCES)

bin_PROGRAMS = itscoopdemoapp_v2

COMMON_LIBS = libitscoopdemoapp_v2.a \
./utils/options/liboptions.a \
./utils/common/libcommon.a \
./utils/xml/libxml.a \
./utils/iodevices/libiodevices.a \
./foreign/tcpip/libtcpip.a \
./utils/log/liblog.a \
$(XERCES_LIBS)

noinst_LIBRARIES = libitscoopdemoapp_v2.a

libitscoopdemoapp_v2_a_SOURCES = server.h server.cpp \
app-commands-subscriptions-constants.h \
application-logic.h application-logic.cpp

itscoopdemoapp_v2_SOURCES = its_demo_app_main.cpp 

itscoopdemoapp_v2_LDFLAGS = $(XERCES_LDFLAGS)

itscoopdemoapp_v2_LDADD = $(COMMON_LIBS)

SUBDIRS = utils foreign

EXTRA_DIST = config.h
