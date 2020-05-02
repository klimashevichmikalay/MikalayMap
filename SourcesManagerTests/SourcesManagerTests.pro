include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

ENTITIES =  ../SourcesManager/entities/

INCLUDEPATH += \
        $$ENTITIES

HEADERS += \
        tst_basefigure.h \
        $$ENTITIES/BaseFigure.h

SOURCES += \
        main.cpp \
        $$ENTITIES/BaseFigure.cpp
