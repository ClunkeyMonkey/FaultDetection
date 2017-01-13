TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += static

SOURCES += main.cpp \
    datacollect.cpp \
    temperatureanalysis.cpp \
    doorswitchanalysis.cpp \
    poweranalysis.cpp \
    dutyanalysis.cpp

DISTFILES += \
    sample.json

HEADERS += \
    json.hpp \
    doorswitchanalysis.hpp \
    datacollect.hpp \
    poweranalysis.hpp \
    temperatureanalysis.hpp \
    dutyanalysis.hpp
