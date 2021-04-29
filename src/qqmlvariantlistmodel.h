#ifndef QQMLVARIANTLISTMODEL_H
#define QQMLVARIANTLISTMODEL_H

#include "global.h"
#include "qqmlmodels.h"

#include <qqml.h>


class QQmlVariantListModelPrivate;

class QtQmlTricks_API_ QQmlVariantListModel : public QAbstractListModel {
    Q_OBJECT
    Q_PROPERTY (int count READ count NOTIFY countChanged)

    QML_NAMED_ELEMENT(VariantListModel)
    QML_UNCREATABLE("Use it in C++ only.")
public:
    explicit QQmlVariantListModel (QObject * parent);
    virtual ~QQmlVariantListModel ();

public: // QAbstractItemModel interface reimplemented
    virtual int rowCount (const QModelIndex & parent = QModelIndex ()) const;
    virtual bool setData (const QModelIndex & index, const QVariant & value, int role);
    virtual QVariant data (const QModelIndex & index, int role) const;
    virtual QHash<int, QByteArray> roleNames () const;

    int count () const;
    bool isEmpty () const;
    QVariant get (int idx) const;
    QVariantList list () const;
public slots: // public API
    void clear ();

    void append (QVariant item);
    void prepend (QVariant item);
    void insert (int idx, QVariant item);
    void appendList (QVariantList itemList);
    void prependList (QVariantList itemList);
    void replace (int pos, QVariant item);
    void insertList (int idx, QVariantList itemList);
    void move (int idx, int pos);
    void remove (int idx);

signals: // notifiers
    void countChanged (int count);

private:
    QQmlVariantListModelPrivate * m_privateImpl;
};

#endif // QQMLVARIANTLISTMODEL_H
