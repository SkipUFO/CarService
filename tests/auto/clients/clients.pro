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
