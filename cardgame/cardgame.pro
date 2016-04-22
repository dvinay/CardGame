#-------------------------------------------------
#
# Project created by QtCreator 2014-04-28T12:15:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cardgame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    card.cpp \
    pile.cpp \
    rulesdialog.cpp

HEADERS  += mainwindow.h \
    card.h \
    pile.h \
    rulesdialog.h

FORMS    += mainwindow.ui \
    rulesdialog.ui
RESOURCES += \
CardBmps.qrc \
    CardBmps.qrc
QMAKE_CXXFLAGS += -fpermissive

DISTFILES +=
