TEMPLATE = app
#CONFIG += console c++11
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt
#CONFIG += c++11

RAPID_JSON =  ../RapidJson/

HEADERS += \
    entities/Algorithms.h \
    entities/BaseFigure.h \
    entities/Coordinates.h \
    entities/FilledPolygon.h \
    entities/MultiFilledPolygon.h \
    entities/MultiLineString.h \
    entities/MultiPoint.h \
    entities/Scale.h \
    entities/EntitiesConstants.h \
    entities/FiguresTypes.h \
    entities/LineString.h \
    entities/Point.h \
    entities/Triangle.h \
    parsers/BaseFigureParser.h \
    parsers/Converters.h \
    parsers/CoordinatesParser.h \
    parsers/FilledPolygonParser.h \
    parsers/ICommand.h \
    parsers/LineStringParser.h \
    parsers/MultiFilledPolygonParser.h \
    parsers/MultiLineParser.h \
    parsers/MultiPointParser.h \
    parsers/ParsersAll.h \
    parsers/ParsersConstants.h \
    $$RAPID_JSON/rapidjson.h \
    parsers/PointParser.h

SOURCES += \
    entities/BaseFigure.cpp \
    entities/Coordinates.cpp \
    entities/FilledPolygon.cpp \
    entities/MultiFilledPolygon.cpp \
    entities/MultiLineString.cpp \
    entities/MultiPoint.cpp \
    entities/Scale.cpp \
    entities/LineString.cpp \
    entities/Point.cpp \
    main.cpp


