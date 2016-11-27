QT       += core network
CONFIG  += c++11 c++14

#TARGET    = qhttp
#TEMPLATE  = lib

DEFINES       *= QHTTP_MEMORY_LOG=0
win32:DEFINES *= QHTTP_EXPORT

DEFINES += QHTTP_HAS_CLIENT

# Joyent http_parser
SOURCES  += $$PWD/3rdparty/http-parser/http_parser.c
HEADERS  += $$PWD/3rdparty/http-parser/http_parser.h

SOURCES  += \
    $$PWD/src/qhttpabstracts.cpp \
    $$PWD/src/qhttpserverconnection.cpp \
    $$PWD/src/qhttpserverrequest.cpp \
    $$PWD/src/qhttpserverresponse.cpp \
    $$PWD/src/qhttpserver.cpp \
    $$PWD/src/qhttpclientrequest.cpp \
    $$PWD/src/qhttpclientresponse.cpp \
    $$PWD/src/qhttpclient.cpp

HEADERS  += \
    $$PWD/src/qhttpfwd.hpp \
    $$PWD/src/qhttpabstracts.hpp \
    $$PWD/src/qhttpserverconnection.hpp \
    $$PWD/src/qhttpserverrequest.hpp \
    $$PWD/src/qhttpserverresponse.hpp \
    $$PWD/src/qhttpserver.hpp \
    $$PWD/src/qhttpclient.hpp \
    $$PWD/src/qhttpclientresponse.hpp \
    $$PWD/src/qhttpclientrequest.hpp

INCLUDEPATH += $$PWD/3rdparty \
    $$PWD/includes \
    $$PWD/src
