/****************************************************************************
** Meta object code from reading C++ file 'buddylistwidget.h'
**
** Created: Wed Jul 1 16:37:08 2015
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../buddylistwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'buddylistwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BuddyListWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   17,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BuddyListWidget[] = {
    "BuddyListWidget\0\0value\0"
    "ScrollBarValueChanged(int)\0"
};

void BuddyListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BuddyListWidget *_t = static_cast<BuddyListWidget *>(_o);
        switch (_id) {
        case 0: _t->ScrollBarValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BuddyListWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BuddyListWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BuddyListWidget,
      qt_meta_data_BuddyListWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BuddyListWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BuddyListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BuddyListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BuddyListWidget))
        return static_cast<void*>(const_cast< BuddyListWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int BuddyListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
