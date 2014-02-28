/****************************************************************************
** Meta object code from reading C++ file 'RORI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../RORI_c/RORI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'RORI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_RORI_t {
    QByteArrayData data[20];
    char stringdata[210];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_RORI_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_RORI_t qt_meta_stringdata_RORI = {
    {
QT_MOC_LITERAL(0, 0, 4),
QT_MOC_LITERAL(1, 5, 13),
QT_MOC_LITERAL(2, 19, 0),
QT_MOC_LITERAL(3, 20, 11),
QT_MOC_LITERAL(4, 32, 16),
QT_MOC_LITERAL(5, 49, 6),
QT_MOC_LITERAL(6, 56, 2),
QT_MOC_LITERAL(7, 59, 4),
QT_MOC_LITERAL(8, 64, 13),
QT_MOC_LITERAL(9, 78, 11),
QT_MOC_LITERAL(10, 90, 11),
QT_MOC_LITERAL(11, 102, 6),
QT_MOC_LITERAL(12, 109, 7),
QT_MOC_LITERAL(13, 117, 12),
QT_MOC_LITERAL(14, 130, 11),
QT_MOC_LITERAL(15, 142, 28),
QT_MOC_LITERAL(16, 171, 5),
QT_MOC_LITERAL(17, 177, 18),
QT_MOC_LITERAL(18, 196, 3),
QT_MOC_LITERAL(19, 200, 8)
    },
    "RORI\0newConnection\0\0receiveData\0"
    "disconnectClient\0sendAt\0ip\0port\0"
    "messageToSend\0sendMessage\0QTcpSocket*\0"
    "target\0message\0saySomething\0SocketError\0"
    "QAbstractSocket::SocketError\0error\0"
    "timeBeforeQuestion\0ask\0workData\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RORI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08,
       3,    0,   65,    2, 0x08,
       4,    0,   66,    2, 0x08,
       5,    3,   67,    2, 0x08,
       9,    2,   74,    2, 0x08,
      13,    1,   79,    2, 0x08,
      14,    1,   82,    2, 0x08,
      17,    0,   85,    2, 0x08,
      18,    0,   86,    2, 0x08,
      19,    1,   87,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    6,    7,    8,
    QMetaType::Void, 0x80000000 | 10, QMetaType::QString,   11,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,

       0        // eod
};

void RORI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject RORI::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_RORI.data,
      qt_meta_data_RORI,  qt_static_metacall, 0, 0}
};


const QMetaObject *RORI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RORI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RORI.stringdata))
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
