/****************************************************************************
** Meta object code from reading C++ file 'connection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ZalfonIntegral/connection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'connection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Connection_t {
    QByteArrayData data[36];
    char stringdata0[448];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Connection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Connection_t qt_meta_stringdata_Connection = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Connection"
QT_MOC_LITERAL(1, 11, 10), // "updateView"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "QHostAddress"
QT_MOC_LITERAL(4, 36, 2), // "ip"
QT_MOC_LITERAL(5, 39, 8), // "uint16_t"
QT_MOC_LITERAL(6, 48, 4), // "port"
QT_MOC_LITERAL(7, 53, 19), // "currentStateUpdated"
QT_MOC_LITERAL(8, 73, 12), // "CustomState*"
QT_MOC_LITERAL(9, 86, 5), // "state"
QT_MOC_LITERAL(10, 92, 12), // "QList<Zone*>"
QT_MOC_LITERAL(11, 105, 6), // "source"
QT_MOC_LITERAL(12, 112, 14), // "makeConnection"
QT_MOC_LITERAL(13, 127, 17), // "setConnectionData"
QT_MOC_LITERAL(14, 145, 7), // "address"
QT_MOC_LITERAL(15, 153, 12), // "showTerminal"
QT_MOC_LITERAL(16, 166, 21), // "on_connectBtn_clicked"
QT_MOC_LITERAL(17, 188, 9), // "onTcpRead"
QT_MOC_LITERAL(18, 198, 22), // "on_terminalBtn_clicked"
QT_MOC_LITERAL(19, 221, 10), // "setVersion"
QT_MOC_LITERAL(20, 232, 10), // "QList<int>"
QT_MOC_LITERAL(21, 243, 3), // "ver"
QT_MOC_LITERAL(22, 247, 10), // "checkState"
QT_MOC_LITERAL(23, 258, 21), // "onConnectionEstablish"
QT_MOC_LITERAL(24, 280, 18), // "showZoneEditDialog"
QT_MOC_LITERAL(25, 299, 5), // "Zone*"
QT_MOC_LITERAL(26, 305, 4), // "zone"
QT_MOC_LITERAL(27, 310, 12), // "onArmRequest"
QT_MOC_LITERAL(28, 323, 5), // "zones"
QT_MOC_LITERAL(29, 329, 17), // "onAlarmOffRequest"
QT_MOC_LITERAL(30, 347, 14), // "onUnarmRequest"
QT_MOC_LITERAL(31, 362, 31), // "on_passLineEdit_editingFinished"
QT_MOC_LITERAL(32, 394, 16), // "handlePacketLost"
QT_MOC_LITERAL(33, 411, 7), // "Packet*"
QT_MOC_LITERAL(34, 419, 6), // "packet"
QT_MOC_LITERAL(35, 426, 21) // "on_pushButton_clicked"

    },
    "Connection\0updateView\0\0QHostAddress\0"
    "ip\0uint16_t\0port\0currentStateUpdated\0"
    "CustomState*\0state\0QList<Zone*>\0source\0"
    "makeConnection\0setConnectionData\0"
    "address\0showTerminal\0on_connectBtn_clicked\0"
    "onTcpRead\0on_terminalBtn_clicked\0"
    "setVersion\0QList<int>\0ver\0checkState\0"
    "onConnectionEstablish\0showZoneEditDialog\0"
    "Zone*\0zone\0onArmRequest\0zones\0"
    "onAlarmOffRequest\0onUnarmRequest\0"
    "on_passLineEdit_editingFinished\0"
    "handlePacketLost\0Packet*\0packet\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Connection[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  104,    2, 0x06 /* Public */,
       7,    2,  109,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,  114,    2, 0x0a /* Public */,
      13,    2,  115,    2, 0x0a /* Public */,
      15,    0,  120,    2, 0x0a /* Public */,
      16,    0,  121,    2, 0x08 /* Private */,
      17,    0,  122,    2, 0x08 /* Private */,
      18,    0,  123,    2, 0x08 /* Private */,
      19,    1,  124,    2, 0x08 /* Private */,
      22,    0,  127,    2, 0x08 /* Private */,
      23,    0,  128,    2, 0x08 /* Private */,
      24,    1,  129,    2, 0x08 /* Private */,
      27,    1,  132,    2, 0x08 /* Private */,
      29,    1,  135,    2, 0x08 /* Private */,
      30,    1,  138,    2, 0x08 /* Private */,
      31,    0,  141,    2, 0x08 /* Private */,
      32,    1,  142,    2, 0x08 /* Private */,
      35,    0,  145,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 10,    9,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,   14,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void, 0x80000000 | 10,   28,
    QMetaType::Void, 0x80000000 | 10,   28,
    QMetaType::Void, 0x80000000 | 10,   28,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 33,   34,
    QMetaType::Void,

       0        // eod
};

void Connection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Connection *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateView((*reinterpret_cast< QHostAddress(*)>(_a[1])),(*reinterpret_cast< uint16_t(*)>(_a[2]))); break;
        case 1: _t->currentStateUpdated((*reinterpret_cast< CustomState*(*)>(_a[1])),(*reinterpret_cast< QList<Zone*>(*)>(_a[2]))); break;
        case 2: _t->makeConnection(); break;
        case 3: _t->setConnectionData((*reinterpret_cast< const QHostAddress(*)>(_a[1])),(*reinterpret_cast< uint16_t(*)>(_a[2]))); break;
        case 4: _t->showTerminal(); break;
        case 5: _t->on_connectBtn_clicked(); break;
        case 6: _t->onTcpRead(); break;
        case 7: _t->on_terminalBtn_clicked(); break;
        case 8: _t->setVersion((*reinterpret_cast< const QList<int>(*)>(_a[1]))); break;
        case 9: _t->checkState(); break;
        case 10: _t->onConnectionEstablish(); break;
        case 11: _t->showZoneEditDialog((*reinterpret_cast< Zone*(*)>(_a[1]))); break;
        case 12: _t->onArmRequest((*reinterpret_cast< const QList<Zone*>(*)>(_a[1]))); break;
        case 13: _t->onAlarmOffRequest((*reinterpret_cast< const QList<Zone*>(*)>(_a[1]))); break;
        case 14: _t->onUnarmRequest((*reinterpret_cast< const QList<Zone*>(*)>(_a[1]))); break;
        case 15: _t->on_passLineEdit_editingFinished(); break;
        case 16: _t->handlePacketLost((*reinterpret_cast< Packet*(*)>(_a[1]))); break;
        case 17: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<Zone*> >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<int> >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Zone* >(); break;
            }
            break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<Zone*> >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<Zone*> >(); break;
            }
            break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<Zone*> >(); break;
            }
            break;
        case 16:
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
            using _t = void (Connection::*)(QHostAddress , uint16_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Connection::updateView)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Connection::*)(CustomState * , QList<Zone*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Connection::currentStateUpdated)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Connection::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Connection.data,
    qt_meta_data_Connection,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Connection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Connection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Connection.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "ErrorAble"))
        return static_cast< ErrorAble*>(this);
    if (!strcmp(_clname, "AuthorizationInterface"))
        return static_cast< AuthorizationInterface*>(this);
    return QWidget::qt_metacast(_clname);
}

int Connection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void Connection::updateView(QHostAddress _t1, uint16_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Connection::currentStateUpdated(CustomState * _t1, QList<Zone*> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
