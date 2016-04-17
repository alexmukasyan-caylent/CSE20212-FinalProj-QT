#-------------------------------------------------
#
# Project created by QtCreator 2016-03-26T13:05:11
#
#-------------------------------------------------

QT       += core gui
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Code_Editor
TEMPLATE = app


SOURCES += main.cpp\
        codeeditor.cpp \
    syntaxhighlight.cpp \
    mainwindow.cpp

HEADERS  += codeeditor.h \
    syntaxhighlighter.h \
    mainwindow.h


FORMS    += codeeditor.ui
