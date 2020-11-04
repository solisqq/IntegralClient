/****************************************************************************
** Meta object code from reading C++ file 'settingsinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ZalfonIntegral/settingsinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingsinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SETUP__BY_STRING_EDITABLE_t {
    QByteArrayData data[5];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SETUP__BY_STRING_EDITABLE_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SETUP__BY_STRING_EDITABLE_t qt_meta_stringdata_SETUP__BY_STRING_EDITABLE = {
    {
QT_MOC_LITERAL(0, 0, 25), // "SETUP::BY_STRING_EDITABLE"
QT_MOC_LITERAL(1, 26, 12), // "setByQString"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 13), // "valueInString"
QT_MOC_LITERAL(4, 54, 16) // "handlePushButton"

    },
    "SETUP::BY_STRING_EDITABLE\0setByQString\0"
    "\0valueInString\0handlePushButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SETUP__BY_STRING_EDITABLE[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,
       4,    0,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,    3,
    QMetaType::Void,

       0        // eod
};

void SETUP::BY_STRING_EDITABLE::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BY_STRING_EDITABLE *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->setByQString((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->handlePushButton(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SETUP::BY_STRING_EDITABLE::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SETUP__BY_STRING_EDITABLE.data,
    qt_meta_data_SETUP__BY_STRING_EDITABLE,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SETUP::BY_STRING_EDITABLE::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SETUP::BY_STRING_EDITABLE::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SETUP__BY_STRING_EDITABLE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SETUP::BY_STRING_EDITABLE::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_SETUP__SDOUBLE_t {
    QByteArrayData data[4];
    char stringdata0[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SETUP__SDOUBLE_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SETUP__SDOUBLE_t qt_meta_stringdata_SETUP__SDOUBLE = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SETUP::SDOUBLE"
QT_MOC_LITERAL(1, 15, 12), // "setByQString"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 14) // "valueInQString"

    },
    "SETUP::SDOUBLE\0setByQString\0\0"
    "valueInQString"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SETUP__SDOUBLE[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,    3,

       0        // eod
};

void SETUP::SDOUBLE::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SDOUBLE *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->setByQString((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SETUP::SDOUBLE::staticMetaObject = { {
    QMetaObject::SuperData::link<BY_STRING_EDITABLE::staticMetaObject>(),
    qt_meta_stringdata_SETUP__SDOUBLE.data,
    qt_meta_data_SETUP__SDOUBLE,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SETUP::SDOUBLE::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SETUP::SDOUBLE::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SETUP__SDOUBLE.stringdata0))
        return static_cast<void*>(this);
    return BY_STRING_EDITABLE::qt_metacast(_clname);
}

int SETUP::SDOUBLE::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BY_STRING_EDITABLE::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_SETUP__SINT_t {
    QByteArrayData data[4];
    char stringdata0[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SETUP__SINT_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SETUP__SINT_t qt_meta_stringdata_SETUP__SINT = {
    {
QT_MOC_LITERAL(0, 0, 11), // "SETUP::SINT"
QT_MOC_LITERAL(1, 12, 12), // "setByQString"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 14) // "valueInQString"

    },
    "SETUP::SINT\0setByQString\0\0valueInQString"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SETUP__SINT[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,    3,

       0        // eod
};

void SETUP::SINT::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SINT *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->setByQString((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SETUP::SINT::staticMetaObject = { {
    QMetaObject::SuperData::link<BY_STRING_EDITABLE::staticMetaObject>(),
    qt_meta_stringdata_SETUP__SINT.data,
    qt_meta_data_SETUP__SINT,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SETUP::SINT::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SETUP::SINT::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SETUP__SINT.stringdata0))
        return static_cast<void*>(this);
    return BY_STRING_EDITABLE::qt_metacast(_clname);
}

int SETUP::SINT::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BY_STRING_EDITABLE::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_SETUP__SU8INT_t {
    QByteArrayData data[4];
    char stringdata0[43];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SETUP__SU8INT_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SETUP__SU8INT_t qt_meta_stringdata_SETUP__SU8INT = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SETUP::SU8INT"
QT_MOC_LITERAL(1, 14, 12), // "setByQString"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14) // "valueInQString"

    },
    "SETUP::SU8INT\0setByQString\0\0valueInQString"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SETUP__SU8INT[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,    3,

       0        // eod
};

void SETUP::SU8INT::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SU8INT *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->setByQString((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SETUP::SU8INT::staticMetaObject = { {
    QMetaObject::SuperData::link<BY_STRING_EDITABLE::staticMetaObject>(),
    qt_meta_stringdata_SETUP__SU8INT.data,
    qt_meta_data_SETUP__SU8INT,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SETUP::SU8INT::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SETUP::SU8INT::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SETUP__SU8INT.stringdata0))
        return static_cast<void*>(this);
    return BY_STRING_EDITABLE::qt_metacast(_clname);
}

int SETUP::SU8INT::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BY_STRING_EDITABLE::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_SETUP__S8INT_t {
    QByteArrayData data[4];
    char stringdata0[42];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SETUP__S8INT_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SETUP__S8INT_t qt_meta_stringdata_SETUP__S8INT = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SETUP::S8INT"
QT_MOC_LITERAL(1, 13, 12), // "setByQString"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14) // "valueInQString"

    },
    "SETUP::S8INT\0setByQString\0\0valueInQString"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SETUP__S8INT[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,    3,

       0        // eod
};

void SETUP::S8INT::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<S8INT *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->setByQString((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SETUP::S8INT::staticMetaObject = { {
    QMetaObject::SuperData::link<BY_STRING_EDITABLE::staticMetaObject>(),
    qt_meta_stringdata_SETUP__S8INT.data,
    qt_meta_data_SETUP__S8INT,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SETUP::S8INT::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SETUP::S8INT::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SETUP__S8INT.stringdata0))
        return static_cast<void*>(this);
    return BY_STRING_EDITABLE::qt_metacast(_clname);
}

int SETUP::S8INT::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BY_STRING_EDITABLE::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_SETUP__SQSTRING_t {
    QByteArrayData data[4];
    char stringdata0[45];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SETUP__SQSTRING_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SETUP__SQSTRING_t qt_meta_stringdata_SETUP__SQSTRING = {
    {
QT_MOC_LITERAL(0, 0, 15), // "SETUP::SQSTRING"
QT_MOC_LITERAL(1, 16, 12), // "setByQString"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 14) // "valueInQString"

    },
    "SETUP::SQSTRING\0setByQString\0\0"
    "valueInQString"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SETUP__SQSTRING[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,    3,

       0        // eod
};

void SETUP::SQSTRING::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SQSTRING *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->setByQString((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SETUP::SQSTRING::staticMetaObject = { {
    QMetaObject::SuperData::link<BY_STRING_EDITABLE::staticMetaObject>(),
    qt_meta_stringdata_SETUP__SQSTRING.data,
    qt_meta_data_SETUP__SQSTRING,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SETUP::SQSTRING::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SETUP::SQSTRING::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SETUP__SQSTRING.stringdata0))
        return static_cast<void*>(this);
    return BY_STRING_EDITABLE::qt_metacast(_clname);
}

int SETUP::SQSTRING::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BY_STRING_EDITABLE::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_SETUP__SBOOL_t {
    QByteArrayData data[4];
    char stringdata0[42];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SETUP__SBOOL_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SETUP__SBOOL_t qt_meta_stringdata_SETUP__SBOOL = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SETUP::SBOOL"
QT_MOC_LITERAL(1, 13, 12), // "setByQString"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14) // "valueInQString"

    },
    "SETUP::SBOOL\0setByQString\0\0valueInQString"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SETUP__SBOOL[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,    3,

       0        // eod
};

void SETUP::SBOOL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SBOOL *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->setByQString((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SETUP::SBOOL::staticMetaObject = { {
    QMetaObject::SuperData::link<BY_STRING_EDITABLE::staticMetaObject>(),
    qt_meta_stringdata_SETUP__SBOOL.data,
    qt_meta_data_SETUP__SBOOL,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SETUP::SBOOL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SETUP::SBOOL::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SETUP__SBOOL.stringdata0))
        return static_cast<void*>(this);
    return BY_STRING_EDITABLE::qt_metacast(_clname);
}

int SETUP::SBOOL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BY_STRING_EDITABLE::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
