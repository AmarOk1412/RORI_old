/****************************************************************************
** Meta object code from reading C++ file 'RORI.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../RORI_c/RORI.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RORI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RORI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x08,
      22,    5,    5,    5, 0x08,
      36,    5,    5,    5, 0x08,
      77,   55,    5,    5, 0x08,
     124,  109,    5,    5, 0x08,
     165,  157,    5,    5, 0x08,
     193,  187,    5,    5, 0x08,
     239,    5,  235,    5, 0x08,
     260,    5,    5,    5, 0x08,
     266,  157,    5,    5, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RORI[] = {
    "RORI\0\0newConnection()\0receiveData()\0"
    "disconnectClient()\0ip,port,messageToSend\0"
    "sendAt(QString,QString,QString)\0"
    "target,message\0sendMessage(QTcpSocket*,QString)\0"
    "message\0saySomething(QString)\0error\0"
    "SocketError(QAbstractSocket::SocketError)\0"
    "int\0timeBeforeQuestion()\0ask()\0"
    "workData(QString)\0"
};

void RORI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RORI *_t = static_cast<RORI *>(_o);
        switch (_id) {
        case 0: _t->newConnection(); break;
        case 1: _t->receiveData(); break;
        case 2: _t->disconnectClient(); break;
        case 3: _t->sendAt((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 4: _t->sendMessage((*reinterpret_cast< QTcpSocket*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->saySomething((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->SocketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 7: { int _r = _t->timeBeforeQuestion();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 8: _t->ask(); break;
        case 9: _t->workData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RORI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RORI::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RORI,
      qt_meta_data_RORI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RORI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RORI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RORI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RORI))
        return static_cast<void*>(const_cast< RORI*>(this));
    return QObject::qt_metacast(_clname);
}

int RORI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
