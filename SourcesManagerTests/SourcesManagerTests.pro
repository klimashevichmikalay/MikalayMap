include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

ENTITIES =  ../SourcesManager/entities/
PARSERS =  ../SourcesManager/parsers/


INCLUDEPATH += \
        $$ENTITIES \
        $$PARSERS


HEADERS += \
        tst_basefigure.h \
        $$ENTITIES/BaseFigure.h \
        tst_coordinates.h \
        tst_entitiesalgorithms.h \
        tst_filledpolygon.h \
        tst_linestring.h \
        tst_multifilledpolygon.h \
        tst_multilinestring.h \
        tst_multipoint.h \
        tst_parsers.h \
        tst_point.h \
        $$ENTITIES/Point.h \
        tst_linestring.h \
        $$ENTITIES/LineString.h \
        $$ENTITIES/Coordinates.h \
        $$ENTITIES/MultiPoint.h \
        $$ENTITIES/IScale.h \
        $$ENTITIES/MultiLineString.h \
        $$ENTITIES/MultiFilledPolygon.h \
        $$ENTITIES/Triangle.h \
        $$ENTITIES/FilledPolygon.h \
        $$ENTITIES/Algorithms.h \
        $$PARSERS/ParsersAll.h \
        $$PARSERS/ParsersCommand.h \
        tst_triangle.h


SOURCES += \
        main.cpp \
        $$ENTITIES/Coordinates.cpp \
        $$ENTITIES/BaseFigure.cpp \
        $$ENTITIES/Point.cpp \
        $$ENTITIES/LineString.cpp \
        $$ENTITIES/IScale.cpp \
        $$ENTITIES/MultiPoint.cpp \
        $$ENTITIES/MultiLineString.cpp \
        $$ENTITIES/MultiFilledPolygon.cpp \
        $$ENTITIES/FilledPolygon.cpp
