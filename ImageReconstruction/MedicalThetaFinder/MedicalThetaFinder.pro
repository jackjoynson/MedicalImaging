TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ReadCCData.cpp \
    EventEntry.cpp \
    calculatetheta.cpp \
    DetectorType.cpp \
    findaveragestdev.cpp

HEADERS += \
    ReadCCData.h \
    EventEntry.h \
    calculatetheta.h \
    DetectorType.h \
    findaveragestdev.h
