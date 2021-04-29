#ifndef QUTILS_H
#define QUTILS_H

#include <QList>
#include <QVariantList>

template<typename T>
QList<T> qListFromVariant (const QVariantList & list) {
    QList<T> ret;
    ret.reserve (list.size ());
    for (QVariantList::const_iterator it = list.constBegin (); it != list.constEnd (); it++) {
        const QVariant & var = (QVariant) (* it);
        ret.append (var.value<T> ());
    }
    return ret;
}

template<typename T>
QVariantList qListToVariant (const QList<T> & list) {
    QVariantList ret;
    ret.reserve (list.size ());
    for (typename QList<T>::const_iterator it = list.constBegin (); it != list.constEnd (); it++) {
        const T & val = (T) (* it);
        ret.append (QVariant::fromValue (val));
    }
    return ret;
}

// custom foreach for QList, which uses no copy and check pointer non-null
#define FOREACH_PTR_IN_QLIST(_type_, _var_, _list_) \
    for (typename QList<_type_ *>::const_iterator it = _list_.begin (); it != _list_.end (); it++) \
        for (_type_ * _var_ = (_type_ *) (* it); _var_ != Q_NULLPTR; _var_ = Q_NULLPTR)


#endif // QUTILS_H
