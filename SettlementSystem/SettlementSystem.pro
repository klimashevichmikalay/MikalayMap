TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

ENTITIES =  ../SourcesManager/entities/
PARSERS =  ../SourcesManager/parsers/


INCLUDEPATH += \
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
        SSAlgorithms.h \
        SSConstants.h



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


