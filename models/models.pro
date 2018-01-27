TARGET = model
TEMPLATE = lib
CONFIG += shared c++11
QT += sql
QT -= gui
greaterThan(QT_MAJOR_VERSION, 4): QT += qml
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers sqlobjects mongoobjects
DEPENDPATH  += ../helpers sqlobjects mongoobjects
LIBS += -L../lib -lhelper

include(../appbase.pri)

HEADERS += sqlobjects/usersobject.h
HEADERS += users.h
SOURCES += users.cpp
HEADERS += sqlobjects/companiesobject.h
HEADERS += companies.h
SOURCES += companies.cpp
HEADERS += sqlobjects/industriesobject.h
HEADERS += industries.h
SOURCES += industries.cpp
HEADERS += sqlobjects/jobsobject.h
HEADERS += jobs.h
SOURCES += jobs.cpp
HEADERS += sqlobjects/usersindustriesobject.h
HEADERS += usersindustries.h
SOURCES += usersindustries.cpp
HEADERS += sqlobjects/userscompaniesobject.h
HEADERS += userscompanies.h
SOURCES += userscompanies.cpp
