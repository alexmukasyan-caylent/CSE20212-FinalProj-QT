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
    spellchecker.cpp\
    utf_info.cxx \
    suggestmgr.cxx \
    replist.cxx \
    phonet.cxx \
    hunzip.cxx \
    hunspell.cxx \
    hashmgr.cxx \
    filemgr.cxx \
    dictmgr.cxx \
    csutil.cxx \
    affixmgr.cxx \
    affentry.cxx

HEADERS  += codeeditor.h \
    syntaxhighlighter.h \
    spellchecker.h \
    w_char.hxx \
    suggestmgr.hxx \
    replist.hxx \
    phonet.hxx \
    langnum.hxx \
    hunzip.hxx \
    hunvisapi.h \
    hunspell.hxx \
    hunspell.h \
    htypes.hxx \
    hashmgr.hxx \
    finddialog.h \
    filemgr.hxx \
    dictmgr.hxx \
    csutil.hxx \
    baseaffix.hxx \
    atypes.hxx \
    affixmgr.hxx \
    affentry.hxx

FORMS    += codeeditor.ui
