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
        $$ENTITIES/MultiFigure.h \
        $$ENTITIES/MultiFigureImpl.h \
        $$ENTITIES/LineString.h \
        $$ENTITIES/Coordinates.h \
        $$ENTITIES/MultiPoint.h \
        $$ENTITIES/IScale.h \
        $$ENTITIES/MultiLineString.h \
        $$ENTITIES/MultiFilledPolygon.h \
        $$ENTITIES/Triangle.h \
        $$ENTITIES/FilledPolygon.h \
        SettlementSystemAlgorithms.h \
        $$PARSERS/ParsersAll.h \
        $$PARSERS/ParsersCommand.h \
        Core.h \
        PermutationsGenerator.h \
        SSAlgorithms.h \
        SSConstants.h \
        SettlementCalculation.h



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


