#-------------------------------------------------
#
# Project created by QtCreator 2017-11-18T18:12:45
#
#-------------------------------------------------

QT       += core gui \
            charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets \
                charts

TARGET = example02
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    chart.cpp

HEADERS  += mainwindow.h \
    chart.h

FORMS    += mainwindow.ui
