#-------------------------------------------------
#
# Project created by QtCreator 2012-10-11T20:05:09
#
#-------------------------------------------------

QT       += network sql xml xmlpatterns testlib

TARGET = tst_client
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
           ../CarService/client.cpp \
           ../CarService/car.cpp \
           tst_clienttest.cpp


#DEFINES += SRCDIR=\\\"../CarService\\\"

HEADERS += \
    ../CarService/client.h \
    ../CarService/car.h
