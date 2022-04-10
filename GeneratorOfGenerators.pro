TEMPLATE = app

CONFIG += c++17
CONFIG += console

QT += widgets

FORMS += $$files(*.ui, true)
SOURCES += $$files(*.cpp, true)
HEADERS += $$files(*.h, true)

INCLUDEPATH += src

MOC_DIR = build
OBJECTS_DIR = build
UI_DIR = build

DESTDIR = build
