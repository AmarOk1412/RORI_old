/****************************************************************************
** Meta object code from reading C++ file 'AppearanceOptionWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../RORI-Interface/AppearanceOptionWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AppearanceOptionWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AppearanceOptionWidget_t {
    QByteArrayData data[14];
    char stringdata[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_AppearanceOptionWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_AppearanceOptionWidget_t qt_meta_stringdata_AppearanceOptionWidget = {
    {
QT_MOC_LITERAL(0, 0, 22),
QT_MOC_LITERAL(1, 23, 22),
QT_MOC_LITERAL(2, 46, 0),
QT_MOC_LITERAL(3, 47, 5),
QT_MOC_LITERAL(4, 53, 13),
QT_MOC_LITERAL(5, 67, 5),
QT_MOC_LITERAL(6, 73, 13),
QT_MOC_LITERAL(7, 87, 7),
QT_MOC_LITERAL(8, 95, 12),
QT_MOC_LITERAL(9, 108, 21),
QT_MOC_LITERAL(10, 130, 9),
QT_MOC_LITERAL(11, 140, 9),
QT_MOC_LITERAL(12, 150, 9),
QT_MOC_LITERAL(13, 160, 9)
    },
    "AppearanceOptionWidget\0backgroundImageChanged\0"
    "\0image\0color1Changed\0color\0color2Changed\0"
    "setupUi\0resetClicked\0changeBackgroundImage\0"
    "setColor1\0setColor2\0getColor1\0getColor2\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppearanceOptionWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06,
       4,    1,   67,    2, 0x06,
       6,    1,   70,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       7,    0,   73,    2, 0x0a,
       8,    0,   74,    2, 0x0a,
       9,    0,   75,    2, 0x0a,
      10,    0,   76,    2, 0x0a,
      11,    0,   77,    2, 0x0a,
      12,    0,   78,    2, 0x0a,
      13,    0,   79,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::QString,

       0        // eod
};

void AppearanceOptionWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AppearanceOptionWidget *_t = static_cast<AppearanceOptionWidget *>(_o);
        switch (_id) {
        case 0: _t->backgroundImageChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->color1Changed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->color2Changed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->setupUi(); break;
        case 4: _t->resetClicked(); break;
        case 5: _t->changeBackgroundImage(); break;
        case 6: _t->setColor1(); break;
        case 7: _t->setColor2(); break;
        case 8: { QString _r = _t->getColor1();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 9: { QString _r = _t->getColor2();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AppearanceOptionWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppearanceOptionWidget::backgroundImageChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (AppearanceOptionWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppearanceOptionWidget::color1Changed)) {
                *result = 1;
            }
        }
        {
            typedef void (AppearanceOptionWidget::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AppearanceOptionWidget::color2Changed)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject AppearanceOptionWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AppearanceOptionWidget.data,
      qt_meta_data_AppearanceOptionWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *AppearanceOptionWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppearanceOptionWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AppearanceOptionWidget.stringdata))
        return static_cast<void*>(const_cast< AppearanceOptionWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int AppearanceOptionWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void AppearanceOptionWidget::backgroundImageChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AppearanceOptionWidget::color1Changed(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AppearanceOptionWidget::color2Changed(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
