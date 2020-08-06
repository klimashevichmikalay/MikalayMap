TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt


RAPID_JSON =  ../RapidJson/

HEADERS += \
    entities/Algorithms.h \
    entities/BaseFigure.h \
    entities/Coordinates.h \
    entities/EntitiesAll.h \
    entities/ExceptionsMsgs.h \
    entities/FigureType.h \
    entities/FilledPolygon.h \
    entities/GeometryConstants.h \
    entities/IScale.h \
    entities/MultiFigure.h \
    entities/MultiFilledPolygon.h \
    entities/MultiLineString.h \
    entities/MultiPoint.h \
    entities/LineString.h \
    entities/Point.h \
    entities/SumCounter.h \
    entities/Triangle.h \
    parsers/BaseFigureParser.h \
    parsers/Converters.h \
    parsers/CoordinatesParser.h \
    parsers/FilledPolygonParser.h \
    parsers/ICommand.h \
    parsers/JsonCommand.h \
    parsers/LineStringParser.h \
    parsers/MultiFilledPolygonParser.h \
    parsers/MultiLineParser.h \
    parsers/MultiPointParser.h \
    parsers/ParsersAll.h \
    parsers/ParsersCommand.h \
    parsers/ParsersConstants.h \
    $$RAPID_JSON/rapidjson.h \
    parsers/PointParser.h

SOURCES += \
    entities/BaseFigure.cpp \
    entities/Coordinates.cpp \
    entities/FilledPolygon.cpp \
    entities/IScale.cpp \
    entities/MultiFigure.cpp \
    entities/MultiFilledPolygon.cpp \
    entities/MultiLineString.cpp \
    entities/MultiPoint.cpp \
    entities/LineString.cpp \
    entities/Point.cpp \
    entities/SumCounter.cpp \
    main.cpp

DISTFILES += \
    belarus


