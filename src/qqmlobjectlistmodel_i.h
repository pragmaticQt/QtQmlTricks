#ifndef QQMLOBJECTLISTMODEL_I_H
#define QQMLOBJECTLISTMODEL_I_H

#include "global.h"

#include <qqml.h>
#include <QAbstractListModel>



class QtQmlTricks_API_ QQmlObjectListModelBase : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY (int count READ count NOTIFY countChanged)

    QML_NAMED_ELEMENT(ObjectListModelBase)
    QML_UNCREATABLE("Use it in C++ only.")
public:
    explicit QQmlObjectListModelBase (QObject * parent = Q_NULLPTR) : QAbstractListModel (parent) { }
    virtual int size (void) const = 0;
    virtual int count (void) const = 0;
    virtual bool isEmpty (void) const = 0;
    virtual bool contains (QObject * item) const = 0;
    virtual int indexOf (QObject * item) const = 0;
    virtual int roleForName (const QByteArray & name) const = 0;
    virtual QObject * get (int idx) const = 0;
    virtual QObject * get (const QString & uid) const = 0;
    virtual QObject * getFirst (void) const = 0;
    virtual QObject * getLast (void) const = 0;
    virtual QVariantList toVarArray (void) const = 0;

public slots: // virtual methods API for QML
    virtual void clear (void) = 0;
    virtual void append (QObject * item) = 0;
    virtual void prepend (QObject * item) = 0;
    virtual void insert (int idx, QObject * item) = 0;
    virtual void move (int idx, int pos) = 0;
    virtual void remove (QObject * item) = 0;
    virtual void remove (int idx) = 0;

protected slots: // internal callback
    virtual void onItemPropertyChanged (void) = 0;

signals: // notifier
    void countChanged (void);
};

#endif // QQMLOBJECTLISTMODEL_I_H
