#-------------------------------------------------
#
# Project created by QtCreator 2017-07-07T12:46:11
#
#-------------------------------------------------

QT       += core gui
QT       += xml
QT       += charts

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
    gui/Circuit.cpp \
    gui/Connect.cpp \
    gui/Element.cpp \
    gui/Line.cpp \
    gui/elements/Ground.cpp \
    gui/elements/Neuron.cpp \
    gui/elements/Nfet.cpp \
    gui/elements/Pfet.cpp \
    gui/elements/Pin.cpp \
    gui/Wire.cpp \
    gui/elements/Power.cpp \
    gui/GraphicsItem.cpp \
    gui/GraphicsView.cpp \
    Main.cpp \
    gui/MainWindow.cpp \
    gui/View.cpp \

HEADERS  += \
    gui/Circuit.h \
    gui/Connect.h \
    gui/Element.h \
    gui/Line.h \
    gui/elements/Ground.h \
    gui/elements/Neuron.h \
    gui/elements/Nfet.h \
    gui/elements/Pfet.h \
    gui/elements/Pin.h \
    gui/Wire.h \
    gui/elements/Power.h \
    gui/GraphicsItem.h \
    gui/GraphicsView.h \
    gui/MainWindow.h \
    gui/View.h \

RESOURCES += \
    images.qrc

DESTDIR = ../output
