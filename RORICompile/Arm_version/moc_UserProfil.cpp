/****************************************************************************
** Meta object code from reading C++ file 'UserProfil.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../RORI_c/UserProfil.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UserProfil.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UserProfil[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   11,   12,   11, 0x0a,
      28,   11,   12,   11, 0x0a,
      41,   11,   12,   11, 0x0a,
      53,   11,   12,   11, 0x0a,
      65,   11,   12,   11, 0x0a,
      82,   11,   12,   11, 0x0a,
      96,   11,   12,   11, 0x0a,
     117,  108,   11,   11, 0x0a,
     132,  108,   11,   11, 0x0a,
     148,  108,   11,   11, 0x0a,
     163,  108,   11,   11, 0x0a,
     178,  108,   11,   11, 0x0a,
     198,  108,   11,   11, 0x0a,
     215,  108,   11,   11, 0x0a,
     238,   11,  230,   11, 0x0a,
     248,   11,  230,   11, 0x0a,
     263,   11,   12,   11, 0x0a,
     272,  108,   11,   11, 0x0a,
     289,  108,   11,   11, 0x0a,
     311,  108,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_UserProfil[] = {
    "UserProfil\0\0int\0getUHumor()\0getUPolite()\0"
    "getUJokes()\0getUTired()\0getUIsABadUser()\0"
    "getUCurious()\0getUMoral()\0newValue\0"
    "setUHumor(int)\0setUPolite(int)\0"
    "setUJokes(int)\0setUTired(int)\0"
    "setUIsABadUser(int)\0setUCurious(int)\0"
    "setUMoral(int)\0QString\0getName()\0"
    "getFirstName()\0getAge()\0setName(QString)\0"
    "setFirstName(QString)\0setAge(int)\0"
};

void UserProfil::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UserProfil *_t = static_cast<UserProfil *>(_o);
        switch (_id) {
        case 0: { int _r = _t->getUHumor();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { int _r = _t->getUPolite();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: { int _r = _t->getUJokes();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->getUTired();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { int _r = _t->getUIsABadUser();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: { int _r = _t->getUCurious();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 6: { int _r = _t->getUMoral();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 7: _t->setUHumor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setUPolite((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->setUJokes((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setUTired((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->setUIsABadUser((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->setUCurious((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->setUMoral((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: { QString _r = _t->getName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 15: { QString _r = _t->getFirstName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 16: { int _r = _t->getAge();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 17: _t->setName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->setFirstName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: _t->setAge((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData UserProfil::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject UserProfil::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UserProfil,
      qt_meta_data_UserProfil, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UserProfil::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UserProfil::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UserProfil::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UserProfil))
        return static_cast<void*>(const_cast< UserProfil*>(this));
    return QObject::qt_metacast(_clname);
}

int UserProfil::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
