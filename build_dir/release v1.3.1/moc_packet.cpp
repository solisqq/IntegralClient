/****************************************************************************
** Meta object code from reading C++ file 'packet.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ZalfonIntegral/connection/packet.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'packet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Packet_t {
    QByteArrayData data[12];
    char stringdata0[104];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Packet_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Packet_t qt_meta_stringdata_Packet = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Packet"
QT_MOC_LITERAL(1, 7, 11), // "getResponse"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 10), // "QList<int>"
QT_MOC_LITERAL(4, 31, 4), // "resp"
QT_MOC_LITERAL(5, 36, 7), // "timeout"
QT_MOC_LITERAL(6, 44, 7), // "Packet*"
QT_MOC_LITERAL(7, 52, 6), // "packet"
QT_MOC_LITERAL(8, 59, 13), // "responseReady"
QT_MOC_LITERAL(9, 73, 11), // "QByteArray&"
QT_MOC_LITERAL(10, 85, 3), // "arr"
QT_MOC_LITERAL(11, 89, 14) // "timeoutHandler"

    },
    "Packet\0getResponse\0\0QList<int>\0resp\0"
    "timeout\0Packet*\0packet\0responseReady\0"
    "QByteArray&\0arr\0timeoutHandler"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Packet[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       5,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   40,    2, 0x0a /* Public */,
      11,    0,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,

       0        // eod
};

void Packet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Packet *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getResponse((*reinterpret_cast< const QList<int>(*)>(_a[1]))); break;
        case 1: _t->timeout((*reinterpret_cast< Packet*(*)>(_a[1]))); break;
        case 2: _t->responseReady((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->timeoutHandler(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Packet* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Packet::*)(const QList<int> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Packet::getResponse)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Packet::*)(Packet * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Packet::timeout)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Packet::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Packet.data,
    qt_meta_data_Packet,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Packet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Packet::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Packet.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Packet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Packet::getResponse(const QList<int> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Packet::timeout(Packet * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
