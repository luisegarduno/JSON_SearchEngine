QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++1z
#CONFIG += c++11
#LIBS += -lstdc++fs

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    avltree_index.cpp \
    hashtable_index.cpp \
    interactive.cpp \
    main.cpp \
    maintenance.cpp \
    mode.cpp \
    porter2_stemmer.cpp \
    searchquery.cpp \
    word.cpp

HEADERS += \
    avltree.h \
    avltree_index.h \
    avltree_node.h \
    compare_referenced_map.h \
    hashtable.h \
    hashtable_entry.h \
    hashtable_index.h \
    index_interface.h \
    interactive.h \
    maintenance.h \
    mode.h \
    porter2_stemmer.h \
    searchquery.h \
    word.h

FORMS += \
    maintenance.ui \
    mode.ui \
    searchquery.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    StopWords.txt