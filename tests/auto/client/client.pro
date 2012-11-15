#-------------------------------------------------
#
# Project created by QtCreator 2012-10-11T20:05:09
#
#-------------------------------------------------

QT       += testlib

TARGET = tst_client
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
           ../../../src/client.cpp \
           ../../../src/car.cpp \
           tst_client.cpp


#DEFINES += SRCDIR=\\\"../CarService\\\"

HEADERS += \
    ../../../src/client.h \
    ../../../src/car.h
