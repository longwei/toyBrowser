
TEMPLATE = subdirs
CONFIG += ordered c++11


SUBDIRS = \
    src \
    app \
    test

app.depends = src
tests.depends = src

OTHER_FILES += \
    defaults.pri
