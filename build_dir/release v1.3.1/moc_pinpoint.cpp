/****************************************************************************
** Meta object code from reading C++ file 'pinpoint.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ZalfonIntegral/widgets/pinpoint/pinpoint.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pinpoint.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PinPoint_t {
    QByteArrayData data[25];
    char stringdata0[255];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PinPoint_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PinPoint_t qt_meta_stringdata_PinPoint = {
    {
QT_MOC_LITERAL(0, 0, 8), // "PinPoint"
QT_MOC_LITERAL(1, 9, 11), // "mouseOverMe"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 17), // "closeToPointEvent"
QT_MOC_LITERAL(4, 40, 12), // "QMouseEvent*"
QT_MOC_LITERAL(5, 53, 5), // "event"
QT_MOC_LITERAL(6, 59, 13), // "setupDeclared"
QT_MOC_LITERAL(7, 73, 8), // "removeMe"
QT_MOC_LITERAL(8, 82, 9), // "PinPoint*"
QT_MOC_LITERAL(9, 92, 5), // "point"
QT_MOC_LITERAL(10, 98, 14), // "updateDatabase"
QT_MOC_LITERAL(11, 113, 9), // "PinPoint&"
QT_MOC_LITERAL(12, 123, 8), // "pinpoint"
QT_MOC_LITERAL(13, 132, 12), // "mouseOverPin"
QT_MOC_LITERAL(14, 145, 11), // "updateState"
QT_MOC_LITERAL(15, 157, 12), // "CustomState*"
QT_MOC_LITERAL(16, 170, 5), // "state"
QT_MOC_LITERAL(17, 176, 12), // "QList<Zone*>"
QT_MOC_LITERAL(18, 189, 6), // "source"
QT_MOC_LITERAL(19, 196, 10), // "updateView"
QT_MOC_LITERAL(20, 207, 12), // "QHostAddress"
QT_MOC_LITERAL(21, 220, 7), // "address"
QT_MOC_LITERAL(22, 228, 8), // "uint16_t"
QT_MOC_LITERAL(23, 237, 4), // "port"
QT_MOC_LITERAL(24, 242, 12) // "onUpdateEmit"

    },
    "PinPoint\0mouseOverMe\0\0closeToPointEvent\0"
    "QMouseEvent*\0event\0setupDeclared\0"
    "removeMe\0PinPoint*\0point\0updateDatabase\0"
    "PinPoint&\0pinpoint\0mouseOverPin\0"
    "updateState\0CustomState*\0state\0"
    "QList<Zone*>\0source\0updateView\0"
    "QHostAddress\0address\0uint16_t\0port\0"
    "onUpdateEmit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PinPoint[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    1,   60,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x06 /* Public */,
       7,    1,   64,    2, 0x06 /* Public */,
      10,    1,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   70,    2, 0x0a /* Public */,
      14,    2,   71,    2, 0x08 /* Private */,
      19,    2,   76,    2, 0x08 /* Private */,
      24,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 17,   16,   18,
    QMetaType::Void, 0x80000000 | 20, 0x80000000 | 22,   21,   23,
    QMetaType::Void,

       0        // eod
};

void PinPoint::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PinPoint *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mouseOverMe(); break;
        case 1: _t->closeToPointEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->setupDeclared(); break;
        case 3: _t->removeMe((*reinterpret_cast< PinPoint*(*)>(_a[1]))); break;
        case 4: _t->updateDatabase((*reinterpret_cast< PinPoint(*)>(_a[1]))); break;
        case 5: _t->mouseOverPin(); break;
        case 6: _t->updateState((*reinterpret_cast< CustomState*(*)>(_a[1])),(*reinterpret_cast< QList<Zone*>(*)>(_a[2]))); break;
        case 7: _t->updateView((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< uint16_t(*)>(_a[2]))); break;
        case 8: _t->onUpdateEmit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< PinPoint* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<Zone*> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PinPoint::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PinPoint::mouseOverMe)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PinPoint::*)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PinPoint::closeToPointEvent)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PinPoint::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PinPoint::setupDeclared)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PinPoint::*)(PinPoint * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PinPoint::removeMe)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (PinPoint::*)(PinPoint & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PinPoint::updateDatabase)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PinPoint::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_PinPoint.data,
    qt_meta_data_PinPoint,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PinPoint::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PinPoint::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PinPoint.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ErrorAble"))
        return static_cast< ErrorAble*>(this);
    if (!strcmp(_clname, "AdvancedGraphics"))
        return static_cast< AdvancedGraphics*>(this);
    return QWidget::qt_metacast(_clname);
}

int PinPoint::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void PinPoint::mouseOverMe()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PinPoint::closeToPointEvent(QMouseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PinPoint::setupDeclared()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void PinPoint::removeMe(PinPoint * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PinPoint::updateDatabase(PinPoint & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
