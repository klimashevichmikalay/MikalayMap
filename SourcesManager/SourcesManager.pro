TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

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
    parsers/ICommand.h



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
    main.cpp \
    parsers/ferrefre.cpp




