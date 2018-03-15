TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Cone.cpp \
    ConesToellipse.cpp \
    DetectorType.cpp \
    Ellipse.cpp \
    EventEntry.cpp \
    FileToData.cpp \
    FilterEvents.cpp \
    GenerateCone.cpp \
    GenerateMatrix.cpp \
    GetUserInputs.cpp \
    MatrixToFile.cpp \
    ReadCCData.cpp \
    Vector3D.cpp \
    raygenerator.cpp

HEADERS += \
    Cone.h \
    ConesToEllipse.h \
    DetectorType.h \
    Ellipse.h \
    EventEntry.h \
    FileToData.h \
    FilterEvents.h \
    GenerateCone.h \
    GenerateMatrix.h \
    GetUserInputs.h \
    MatrixToFile.h \
    ReadCCData.h \
    Vector3D.h \
    raygenerator.h
