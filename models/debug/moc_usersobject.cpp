/****************************************************************************
** Meta object code from reading C++ file 'usersobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sqlobjects/usersobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usersobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UsersObject_t {
    QByteArrayData data[7];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UsersObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UsersObject_t qt_meta_stringdata_UsersObject = {
    {
QT_MOC_LITERAL(0, 0, 11), // "UsersObject"
QT_MOC_LITERAL(1, 12, 2), // "id"
QT_MOC_LITERAL(2, 15, 4), // "name"
QT_MOC_LITERAL(3, 20, 5), // "email"
QT_MOC_LITERAL(4, 26, 5), // "phone"
QT_MOC_LITERAL(5, 32, 7), // "country"
QT_MOC_LITERAL(6, 40, 8) // "password"

    },
    "UsersObject\0id\0name\0email\0phone\0country\0"
    "password"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UsersObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       6,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00095003,
       2, QMetaType::QString, 0x00095003,
       3, QMetaType::QString, 0x00095003,
       4, QMetaType::QString, 0x00095003,
       5, QMetaType::QString, 0x00095003,
       6, QMetaType::QString, 0x00095003,

       0        // eod
};

void UsersObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        UsersObject *_t = static_cast<UsersObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getid(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getname(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getemail(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->getphone(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->getcountry(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->getpassword(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        UsersObject *_t = static_cast<UsersObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setid(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setname(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setemail(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setphone(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setcountry(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setpassword(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject UsersObject::staticMetaObject = {
    { &TSqlObject::staticMetaObject, qt_meta_stringdata_UsersObject.data,
      qt_meta_data_UsersObject,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UsersObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UsersObject::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UsersObject.stringdata0))
        return static_cast<void*>(const_cast< UsersObject*>(this));
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(const_cast< UsersObject*>(this));
    return TSqlObject::qt_metacast(_clname);
}

int UsersObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TSqlObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
