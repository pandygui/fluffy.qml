QT       += core network qml
SOURCES  += \
    $$PWD/src/httpserver.cpp \
    $$PWD/src/httpserverrequest.cpp \
    $$PWD/src/httpserverresponse.cpp

HEADERS  += \
    $$PWD/src/httpserver.h \
    $$PWD/src/httpserverrequest.h \
    $$PWD/src/httpserverresponse.h

INCLUDEPATH += $$PWD/src
