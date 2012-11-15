#-------------------------------------------------
#
# Project created by QtCreator 2012-10-11T20:05:09
#
#-------------------------------------------------

QT       += testlib

TARGET = tst_car
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

CONFIG(debug, debug|release) {
    DESTDIR = "debug"
}

LIBS += -lgcov
QMAKE_CXXFLAGS += -g -fprofile-arcs -ftest-coverage -O0
QMAKE_LDFLAGS += -g -fprofile-arcs -ftest-coverage  -O0

SOURCES += tst_car.cpp \
        ../../../src/car.cpp

#DEFINES += SRCDIR=\"$$PWD/../../../src\"

HEADERS += \
        ../../../src/car.h
