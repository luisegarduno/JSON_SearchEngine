TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        classifier.cpp \
        dsstring.cpp \
        main.cpp \
        test.cpp

HEADERS += \
    catch.hpp \
    classifier.h \
    dsstring.h \
    dsvector.h
