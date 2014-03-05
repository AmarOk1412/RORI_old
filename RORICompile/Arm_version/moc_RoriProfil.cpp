/****************************************************************************
** Meta object code from reading C++ file 'RoriProfil.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../RORI_c/RoriProfil.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RoriProfil.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RoriProfil[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   11,   12,   11, 0x0a,
      31,   11,   12,   11, 0x0a,
      47,   11,   12,   11, 0x0a,
      62,   11,   12,   11, 0x0a,
      80,   11,   12,   11, 0x0a,
      96,   11,   12,   11, 0x0a,
     120,  111,   11,   11, 0x0a,
     138,  111,   11,   11, 0x0a,
     157,  111,   11,   11, 0x0a,
     175,  111,   11,   11, 0x0a,
     196,  111,   11,   11, 0x0a,
     215,  111,   11,   11, 0x0a,
     241,   11,  233,   11, 0x0a,
     251,   11,  233,   11, 0x0a,
     266,   11,   12,   11, 0x0a,
     275,  111,   11,   11, 0x0a,
     292,  111,   11,   11, 0x0a,
     314,  111,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RoriProfil[] = {
    "RoriProfil\0\0int\0getRoriHumor()\0"
    "getRoriPolite()\0getRoriJokes()\0"
    "getRoriIsABadIA()\0getRoriScared()\0"
    "getRoriMoral()\0newValue\0setRoriHumor(int)\0"
    "setRoriPolite(int)\0setRoriJokes(int)\0"
    "setRoriIsABadIA(int)\0setRoriScared(int)\0"
    "setRoriMoral(int)\0QString\0getName()\0"
    "getFirstName()\0getAge()\0setName(QString)\0"
    "setFirstName(QString)\0setAge(int)\0"
};

void RoriProfil::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RoriProfil *_t = static_cast<RoriProfil *>(_o);
        switch (_id) {
        case 0: { int _r = _t->getRoriHumor();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: { int _r = _t->getRoriPolite();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: { int _r = _t->getRoriJokes();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { int _r = _t->getRoriIsABadIA();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: { int _r = _t->getRoriScared();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 5: { int _r = _t->getRoriMoral();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 6: _t->setRoriHumor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setRoriPolite((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setRoriJokes((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->setRoriIsABadIA((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setRoriScared((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->setRoriMoral((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: { QString _r = _t->getName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 13: { QString _r = _t->getFirstName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 14: { int _r = _t->getAge();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 15: _t->setName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->setFirstName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: _t->setAge((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RoriProfil::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RoriProfil::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RoriProfil,
      qt_meta_data_RoriProfil, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RoriProfil::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RoriProfil::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RoriProfil::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RoriProfil))
        return static_cast<void*>(const_cast< RoriProfil*>(this));
    return QObject::qt_metacast(_clname);
}

int RoriProfil::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
