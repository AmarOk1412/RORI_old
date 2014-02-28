/****************************************************************************
** Meta object code from reading C++ file 'Interface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../RORI-Interface/Interface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Interface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Interface_t {
    QByteArrayData data[22];
    char stringdata[262];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Interface_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Interface_t qt_meta_stringdata_Interface = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 12),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 14),
QT_MOC_LITERAL(4, 39, 14),
QT_MOC_LITERAL(5, 54, 13),
QT_MOC_LITERAL(6, 68, 5),
QT_MOC_LITERAL(7, 74, 12),
QT_MOC_LITERAL(8, 87, 5),
QT_MOC_LITERAL(9, 93, 12),
QT_MOC_LITERAL(10, 106, 13),
QT_MOC_LITERAL(11, 120, 11),
QT_MOC_LITERAL(12, 132, 11),
QT_MOC_LITERAL(13, 144, 11),
QT_MOC_LITERAL(14, 156, 5),
QT_MOC_LITERAL(15, 162, 7),
QT_MOC_LITERAL(16, 170, 13),
QT_MOC_LITERAL(17, 184, 11),
QT_MOC_LITERAL(18, 196, 17),
QT_MOC_LITERAL(19, 214, 11),
QT_MOC_LITERAL(20, 226, 28),
QT_MOC_LITERAL(21, 255, 5)
    },
    "Interface\0goToRoriMode\0\0goToOptionMode\0"
    "goToAgendaMode\0changeBGImage\0image\0"
    "changeColor1\0color\0changeColor2\0"
    "onTimerFinish\0sendClicked\0sendMessage\0"
    "QTcpSocket*\0cible\0message\0newConnection\0"
    "dataReceive\0serverReceiveData\0SocketError\0"
    "QAbstractSocket::SocketError\0error\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Interface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a,
       3,    0,   80,    2, 0x0a,
       4,    0,   81,    2, 0x0a,
       5,    1,   82,    2, 0x0a,
       7,    1,   85,    2, 0x0a,
       9,    1,   88,    2, 0x0a,
      10,    0,   91,    2, 0x0a,
      11,    0,   92,    2, 0x0a,
      12,    2,   93,    2, 0x0a,
      16,    0,   98,    2, 0x0a,
      17,    0,   99,    2, 0x0a,
      18,    0,  100,    2, 0x0a,
      19,    1,  101,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QString,   14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,   21,

       0        // eod
};

void Interface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Interface *_t = static_cast<Interface *>(_o);
        switch (_id) {
        case 0: _t->goToRoriMode(); break;
        case 1: _t->goToOptionMode(); break;
        case 2: _t->goToAgendaMode(); break;
        case 3: _t->changeBGImage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->changeColor1((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->changeColor2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->onTimerFinish(); break;
        case 7: _t->sendClicked(); break;
        case 8: _t->sendMessage((*reinterpret_cast< QTcpSocket*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->newConnection(); break;
        case 10: _t->dataReceive(); break;
        case 11: _t->serverReceiveData(); break;
        case 12: _t->SocketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject Interface::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Interface.data,
      qt_meta_data_Interface,  qt_static_metacall, 0, 0}
};


const QMetaObject *Interface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Interface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Interface.stringdata))
        return static_cast<void*>(const_cast< Interface*>(this));
    return QWidget::qt_metacast(_clname);
}

int Interface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
