TEMPLATE = app

QT += widgets

FORMS += $$files(*.ui, true)
SOURCES += $$files(*.cpp, true)
HEADERS += $$files(*.h, true)

MOC_DIR = build
OBJECTS_DIR = build
UI_DIR = build

DESTDIR = build
