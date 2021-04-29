TEMPLATE = lib
QT += core gui qml quick svg
CONFIG += c++11 static
TARGET = QtQmlTricks
DEFINES += QtQmlTricks_STATIC
include(src.pri)

RESOURCES += ../import/QtQmlTricks/components.qrc

DESTDIR = ../lib
