TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        dsstring.cpp \
        flightPlan.cpp \
        flightdata.cpp \
        test.cpp

HEADERS += \
    adjacencylist.h \
    catch.hpp \
    dslinkedlist.h \
    dsnode.h \
    dsstack.h \
    dsstring.h \
    dsvector.h \
    flightdata.h
