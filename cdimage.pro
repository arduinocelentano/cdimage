######################################################################
# Automatically generated by qmake (3.1) Fri Jul 8 07:52:22 2022
######################################################################

TEMPLATE = app
TARGET = cdimage
INCLUDEPATH += .
QT += widgets

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += src/cdpreview.h \
           src/converter.h \
           src/createtrackdialog.h \
           src/mainwindow.h
FORMS += src/createtrackdialog.ui src/mainwindow.ui
SOURCES += src/cdpreview.cpp \
           src/converter.cpp \
           src/createtrackdialog.cpp \
           src/main.cpp \
           src/mainwindow.cpp
