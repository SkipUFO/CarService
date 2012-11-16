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
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_LDFLAGS += -fprofile-arcs -ftest-coverage

SOURCES += tst_car.cpp \
        ../../../src/car.cpp

#DEFINES += SRCDIR=\"$$PWD/../../../src\"

HEADERS += \
        ../../../src/car.h
