TEMPLATE = lib
QT += core gui qml quick svg
CONFIG += c++11 shared
TARGET = QtQmlTricks
DEFINES += QtQmlTricks_SHARED
include(src.pri)

RESOURCES += ../import/QtQmlTricks/components.qrc

DESTDIR = ../lib
