/****************************************************************************
** Meta object code from reading C++ file 'jobsobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sqlobjects/jobsobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jobsobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_JobsObject_t {
    QByteArrayData data[10];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_JobsObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_JobsObject_t qt_meta_stringdata_JobsObject = {
    {
QT_MOC_LITERAL(0, 0, 10), // "JobsObject"
QT_MOC_LITERAL(1, 11, 2), // "id"
QT_MOC_LITERAL(2, 14, 5), // "title"
QT_MOC_LITERAL(3, 20, 8), // "location"
QT_MOC_LITERAL(4, 29, 4), // "wage"
QT_MOC_LITERAL(5, 34, 16), // "shortdescription"
QT_MOC_LITERAL(6, 51, 10), // "dateposted"
QT_MOC_LITERAL(7, 62, 11), // "closingdate"
QT_MOC_LITERAL(8, 74, 8), // "industry"
QT_MOC_LITERAL(9, 83, 7) // "company"

    },
    "JobsObject\0id\0title\0location\0wage\0"
    "shortdescription\0dateposted\0closingdate\0"
    "industry\0company"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JobsObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       9,   14, // properties
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
       6, QMetaType::QDateTime, 0x00095003,
       7, QMetaType::QDateTime, 0x00095003,
       8, QMetaType::Int, 0x00095003,
       9, QMetaType::Int, 0x00095003,

       0        // eod
};

void JobsObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        JobsObject *_t = static_cast<JobsObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getid(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->gettitle(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getlocation(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->getwage(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->getshortdescription(); break;
        case 5: *reinterpret_cast< QDateTime*>(_v) = _t->getdateposted(); break;
        case 6: *reinterpret_cast< QDateTime*>(_v) = _t->getclosingdate(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->getindustry(); break;
        case 8: *reinterpret_cast< int*>(_v) = _t->getcompany(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        JobsObject *_t = static_cast<JobsObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setid(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->settitle(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setlocation(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setwage(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setshortdescription(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setdateposted(*reinterpret_cast< QDateTime*>(_v)); break;
        case 6: _t->setclosingdate(*reinterpret_cast< QDateTime*>(_v)); break;
        case 7: _t->setindustry(*reinterpret_cast< int*>(_v)); break;
        case 8: _t->setcompany(*reinterpret_cast< int*>(_v)); break;
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

const QMetaObject JobsObject::staticMetaObject = {
    { &TSqlObject::staticMetaObject, qt_meta_stringdata_JobsObject.data,
      qt_meta_data_JobsObject,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *JobsObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JobsObject::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_JobsObject.stringdata0))
        return static_cast<void*>(const_cast< JobsObject*>(this));
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(const_cast< JobsObject*>(this));
    return TSqlObject::qt_metacast(_clname);
}

int JobsObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TSqlObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
