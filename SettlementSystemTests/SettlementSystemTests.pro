include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

SSYSTEM =  ../SettlementSystem/
ENTITIES =  ../SourcesManager/entities/
PARSERS =  ../SourcesManager/parsers/

INCLUDEPATH += \
        $$SSYSTEM \
        $$ENTITIES \
        $$PARSERS


HEADERS += \
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
        $$PARSERS/ParsersCommand.h \
        tst_algorithms.h \
        tst_core.h \
        tst_permutations.h \
        tst_settlement.h \
        tst_setvisiblepoints.h


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


