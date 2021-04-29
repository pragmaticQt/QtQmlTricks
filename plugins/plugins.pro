TEMPLATE = lib
TARGET = qtqmltricksplugin
QT += qml quick svg
CONFIG += qt plugin qmltypes c++11
DEFINES += QtQmlTricks_STATIC

TARGET = $$qtLibraryTarget($$TARGET)
uri = QtQmlTricks

QML_IMPORT_NAME = $$uri
QML_IMPORT_MAJOR_VERSION = 1
#QML_IMPORT_PATH = $$OUT_PWD
DESTDIR = $$QML_IMPORT_NAME
QMLTYPES_FILENAME = $$DESTDIR/plugins.qmltypes

include(../src/src.pri)

SOURCES += plugins.cpp

HEADERS +=

DISTFILES = qmldir

# copy files list here to DESTDIR
PLUGINFILES = \
    qmldir \
    ../import/QtQmlTricks/QtCoreApi.js \
    ../import/QtQmlTricks/RowContainer.qml \
    ../import/QtQmlTricks/GridContainer.qml \
    ../import/QtQmlTricks/ScrollContainer.qml \
    ../import/QtQmlTricks/WrapLeftRightContainer.qml \
    ../import/QtQmlTricks/IconTextButton.qml \
    ../import/QtQmlTricks/SingleLineEditBox.qml

pluginfiles_copy.files = $$PLUGINFILES
pluginfiles_copy.path = $$DESTDIR

COPIES += pluginfiles_copy
