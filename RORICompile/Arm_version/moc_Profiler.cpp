/****************************************************************************
** Meta object code from reading C++ file 'Profiler.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../RORI_c/Profiler.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Profiler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Profiler[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   10,    9,    9, 0x05,
      50,   42,    9,    9, 0x05,
      72,   67,    9,    9, 0x05,
      96,   88,    9,    9, 0x05,
     113,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     123,   10,    9,    9, 0x0a,
     156,  141,    9,    9, 0x0a,
     189,  183,  178,    9, 0x0a,
     213,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Profiler[] = {
    "Profiler\0\0message\0endOfTreatment(QString)\0"
    "newPath\0newPath(QString)\0path\0"
    "delPro(QString)\0newWord\0newWord(QString)\0"
    "newFunc()\0workData(QString)\0pathToFunction\0"
    "execFunction(QString)\0bool\0conds\0"
    "condAccept(QStringList)\0readEnd()\0"
};

void Profiler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Profiler *_t = static_cast<Profiler *>(_o);
        switch (_id) {
        case 0: _t->endOfTreatment((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->newPath((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->delPro((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->newWord((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->newFunc(); break;
        case 5: _t->workData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->execFunction((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: { bool _r = _t->condAccept((*reinterpret_cast< QStringList(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: _t->readEnd(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Profiler::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Profiler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Profiler,
      qt_meta_data_Profiler, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Profiler::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Profiler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Profiler::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Profiler))
        return static_cast<void*>(const_cast< Profiler*>(this));
    return QObject::qt_metacast(_clname);
}

int Profiler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Profiler::endOfTreatment(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Profiler::newPath(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Profiler::delPro(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Profiler::newWord(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Profiler::newFunc()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
