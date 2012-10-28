#-------------------------------------------------
#
# Project created by QtCreator 2012-10-11T20:05:09
#
#-------------------------------------------------

QT       += network sql xml xmlpatterns testlib

TARGET = tst_clients
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
           tst_clients.cpp \
           ../CarService/clients.cpp \
           ../CarService/client.cpp \
           ../CarService/car.cpp


#DEFINES += SRCDIR=\\\"../CarService\\\"

HEADERS += \
    ../CarService/clients.h \
    ../CarService/client.h \
    ../CarService/car.h
