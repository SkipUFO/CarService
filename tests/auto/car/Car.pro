#-------------------------------------------------
#
# Project created by QtCreator 2012-10-11T20:05:09
#
#-------------------------------------------------

QT       += network sql xml xmlpatterns testlib

TARGET = tst_car
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_cartest.cpp \
           ../CarService/car.cpp

#DEFINES += SRCDIR=\\\"../CarService\\\"

HEADERS += \
    ../CarService/car.h
