TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        dsstring.cpp \
        main.cpp \
        test.cpp

HEADERS += \
    catch.hpp \
    dsstring.h \
    dsvector.h
