#include <QQmlEngineExtensionPlugin>

class SortFilterProxyModelPlugin : public QQmlEngineExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlEngineExtensionInterface_iid)
};


#include "plugins.moc"
