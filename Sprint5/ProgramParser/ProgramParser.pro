TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lstdc++fs

SOURCES += \
        main.cpp \
        parser.cpp \
        porter2_stemmer.cpp

HEADERS += \
    AVLTree.h \
    parser.h \
    porter2_stemmer.h
