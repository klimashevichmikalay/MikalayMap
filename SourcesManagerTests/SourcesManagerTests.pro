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
        $$ENTITIES/BaseFigure.h \
        tst_coordinates.h \
        tst_filledpolygon.h \
        tst_linestring.h \
        tst_multipoint.h \
        tst_point.h \
        $$ENTITIES/Point.h \
        tst_linestring.h \
        $$ENTITIES/LineString.h \
        $$ENTITIES/Coordinates.h \
        $$ENTITIES/MultiPoint.h \
        $$ENTITIES/Scale.h \
        $$ENTITIES/FilledPolygon.h

SOURCES += \
        main.cpp \
        $$ENTITIES/Coordinates.cpp \
        $$ENTITIES/BaseFigure.cpp \
        $$ENTITIES/Point.cpp \
        $$ENTITIES/LineString.cpp \
        $$ENTITIES/Scale.cpp \
        $$ENTITIES/MultiPoint.cpp \
        $$ENTITIES/FilledPolygon.cpp


