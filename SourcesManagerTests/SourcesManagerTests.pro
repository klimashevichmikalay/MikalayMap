include(gtest_dependency.pri)

TEMPLATE = app
#CONFIG += console c++11
CONFIG += c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

ENTITIES =  ../SourcesManager/entities/
#PARSERS =  ../SourcesManager/parsers/
#RAPIDJSON =  ../RapidJson/

INCLUDEPATH += \
        $$ENTITIES \
       # $$PARSERS \
       #  $$RAPIDJSON

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
        tst_point.h \
        $$ENTITIES/Point.h \
        tst_linestring.h \
        $$ENTITIES/LineString.h \
        $$ENTITIES/Coordinates.h \
        $$ENTITIES/MultiPoint.h \
        $$ENTITIES/Scale.h \
        $$ENTITIES/MultiLineString.h \
        $$ENTITIES/MultiFilledPolygon.h \
        $$ENTITIES/Triangle.h \
        $$ENTITIES/FilledPolygon.h \
        $$ENTITIES/Algorithms.h \
     #   $$PARSERS/ParsersAll.h \
        tst_triangle.h \
      #  $$RAPIDJSON/rapidjson/document.h" \
       # $$RAPIDJSON/rapidjson/prettywriter.h" \
       # $$RAPIDJSON/rapidjson/reader.h"

SOURCES += \
        main.cpp \
        $$ENTITIES/Coordinates.cpp \
        $$ENTITIES/BaseFigure.cpp \
        $$ENTITIES/Point.cpp \
        $$ENTITIES/LineString.cpp \
        $$ENTITIES/Scale.cpp \
        $$ENTITIES/MultiPoint.cpp \
        $$ENTITIES/MultiLineString.cpp \
        $$ENTITIES/MultiFilledPolygon.cpp \
        $$ENTITIES/FilledPolygon.cpp


