#-------------------------------------------------
#
# Project created by QtCreator 2017-07-07T12:46:11
#
#-------------------------------------------------

QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

qtHaveModule(printsupport): QT += printsupport
qtHaveModule(opengl): QT += opengl

CONFIG(debug, debug|release) {
    TARGET = neuronerd
} else {
    TARGET = neuroner
}

CONFIG += console
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES +=\
    core/Circuit.cpp \
    core/Connect.cpp \
    core/Element.cpp \
    core/Line.cpp \
    core/elements/Ground.cpp \
    core/elements/Nfet.cpp \
    core/elements/Pfet.cpp \
    core/elements/Pin.cpp \
    core/Wire.cpp \
    core/elements/Power.cpp \
    core/GraphicsItem.cpp \
    core/GraphicsView.cpp \
    core/Main.cpp \
    core/MainWindow.cpp \
    core/View.cpp \

HEADERS  += \
    core/Circuit.h \
    core/Connect.h \
    core/Element.h \
    core/Line.h \
    core/elements/Ground.h \
    core/elements/Nfet.h \
    core/elements/Pfet.h \
    core/elements/Pin.h \
    core/Wire.h \
    core/elements/Power.h \
    core/GraphicsItem.h \
    core/GraphicsView.h \
    core/MainWindow.h \
    core/View.h \

RESOURCES += \
    images.qrc

DESTDIR = ../output
