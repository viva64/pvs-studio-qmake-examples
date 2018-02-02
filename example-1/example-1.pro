TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

pvs_studio.target = pvs
pvs_studio.output = true
pvs_studio.cxxflags = -std=c++11
pvs_studio.sources = $${SOURCES}
include(../PVS-Studio.pri)
