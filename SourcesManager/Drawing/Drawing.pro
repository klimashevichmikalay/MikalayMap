QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += console c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SSYSTEM =  ../SettlementSystem/
ENTITIES =  ../SourcesManager/entities/
PARSERS =  ../SourcesManager/parsers/

INCLUDEPATH += \
        $$SSYSTEM \
        $$ENTITIES \
        $$PARSERS

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        $$ENTITIES/Coordinates.cpp \
        $$ENTITIES/BaseFigure.cpp \
        $$ENTITIES/Point.cpp \
        $$ENTITIES/LineString.cpp \
        $$ENTITIES/Scale.cpp \
        $$ENTITIES/MultiPoint.cpp \
        $$ENTITIES/MultiLineString.cpp \
        $$ENTITIES/MultiFilledPolygon.cpp \
        $$ENTITIES/FilledPolygon.cpp

HEADERS += \
        mainwindow.h \
        $$ENTITIES/BaseFigure.h \
        $$ENTITIES/Point.h \
        $$ENTITIES/LineString.h \
        $$ENTITIES/Coordinates.h \
        $$ENTITIES/MultiPoint.h \
        $$ENTITIES/Scale.h \
        $$ENTITIES/MultiLineString.h \
        $$ENTITIES/MultiFilledPolygon.h \
        $$ENTITIES/Triangle.h \
        $$ENTITIES/FilledPolygon.h \
        $$ENTITIES/Algorithms.h \
        $$PARSERS/ParsersAll.h \
        $$PARSERS/ParsersCommand.h


FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
