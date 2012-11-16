#-------------------------------------------------
#
# Project created by QtCreator 2012-10-11T20:05:09
#
#-------------------------------------------------

QT       += xml testlib

TARGET = tst_clients
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

CONFIG(debug, debug|release) {
    DESTDIR = "debug"
}

LIBS += -lgcov
QMAKE_CXXFLAGS += -g -fprofile-arcs -ftest-coverage -O0
QMAKE_LDFLAGS += -g -fprofile-arcs -ftest-coverage  -O0


SOURCES += \
           tst_clients.cpp \
           ../../../src/clients.cpp \
           ../../../src/client.cpp \
           ../../../src/car.cpp


#DEFINES += SRCDIR=\\\"../CarService\\\"

HEADERS += \
    ../../../src/clients.h \
    ../../../src/client.h \
    ../../../src/car.h
