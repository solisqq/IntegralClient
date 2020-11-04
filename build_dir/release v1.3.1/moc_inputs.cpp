/****************************************************************************
** Meta object code from reading C++ file 'inputs.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ZalfonIntegral/widgets/inputs.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inputs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Inputs_t {
    QByteArrayData data[15];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Inputs_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Inputs_t qt_meta_stringdata_Inputs = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Inputs"
QT_MOC_LITERAL(1, 7, 13), // "noAlarmEmited"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 11), // "alarmEmited"
QT_MOC_LITERAL(4, 34, 10), // "editEmited"
QT_MOC_LITERAL(5, 45, 7), // "Inputs&"
QT_MOC_LITERAL(6, 53, 5), // "input"
QT_MOC_LITERAL(7, 59, 6), // "saveMe"
QT_MOC_LITERAL(8, 66, 8), // "setAlarm"
QT_MOC_LITERAL(9, 75, 2), // "on"
QT_MOC_LITERAL(10, 78, 5), // "setup"
QT_MOC_LITERAL(11, 84, 5), // "_name"
QT_MOC_LITERAL(12, 90, 2), // "id"
QT_MOC_LITERAL(13, 93, 4), // "type"
QT_MOC_LITERAL(14, 98, 20) // "on_indicator_clicked"

    },
    "Inputs\0noAlarmEmited\0\0alarmEmited\0"
    "editEmited\0Inputs&\0input\0saveMe\0"
    "setAlarm\0on\0setup\0_name\0id\0type\0"
    "on_indicator_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Inputs[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    1,   56,    2, 0x06 /* Public */,
       7,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   62,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x2a /* Public | MethodCloned */,
      10,    3,   66,    2, 0x0a /* Public */,
      14,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,

 // slots: parameters
    QMetaType::Bool, QMetaType::Bool,    9,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,   11,   12,   13,
    QMetaType::Void,

       0        // eod
};

void Inputs::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Inputs *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->noAlarmEmited(); break;
        case 1: _t->alarmEmited(); break;
        case 2: _t->editEmited((*reinterpret_cast< Inputs(*)>(_a[1]))); break;
        case 3: _t->saveMe((*reinterpret_cast< Inputs(*)>(_a[1]))); break;
        case 4: { bool _r = _t->setAlarm((*reinterpret_cast< bool(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->setAlarm();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->setup((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->on_indicator_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Inputs::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Inputs::noAlarmEmited)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Inputs::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Inputs::alarmEmited)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Inputs::*)(Inputs & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Inputs::editEmited)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Inputs::*)(Inputs & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Inputs::saveMe)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Inputs::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Inputs.data,
    qt_meta_data_Inputs,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Inputs::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Inputs::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Inputs.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "StateHandler"))
        return static_cast< StateHandler*>(this);
    return QWidget::qt_metacast(_clname);
}

int Inputs::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Inputs::noAlarmEmited()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Inputs::alarmEmited()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Inputs::editEmited(Inputs & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Inputs::saveMe(Inputs & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
