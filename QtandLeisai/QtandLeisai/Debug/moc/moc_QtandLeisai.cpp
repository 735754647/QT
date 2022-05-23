/****************************************************************************
** Meta object code from reading C++ file 'QtandLeisai.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../QtandLeisai.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QtandLeisai.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtandLeisai_t {
    QByteArrayData data[12];
    char stringdata0[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtandLeisai_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtandLeisai_t qt_meta_stringdata_QtandLeisai = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QtandLeisai"
QT_MOC_LITERAL(1, 12, 22), // "on_Bt_CardLint_clicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 20), // "on_Bt_AxisEn_clicked"
QT_MOC_LITERAL(4, 57, 24), // "on_Bt_AxisRestEn_clicked"
QT_MOC_LITERAL(5, 82, 24), // "on_Bt_AxisJOGAdd_clicked"
QT_MOC_LITERAL(6, 107, 24), // "on_Bt_AxisJOGSub_clicked"
QT_MOC_LITERAL(7, 132, 21), // "on_Bt_AxisRun_clicked"
QT_MOC_LITERAL(8, 154, 22), // "on_Bt_AxisStop_clicked"
QT_MOC_LITERAL(9, 177, 24), // "on_Bt_AxisGoHome_clicked"
QT_MOC_LITERAL(10, 202, 26), // "onchB_MoveOri_stateChanged"
QT_MOC_LITERAL(11, 229, 3) // "arg"

    },
    "QtandLeisai\0on_Bt_CardLint_clicked\0\0"
    "on_Bt_AxisEn_clicked\0on_Bt_AxisRestEn_clicked\0"
    "on_Bt_AxisJOGAdd_clicked\0"
    "on_Bt_AxisJOGSub_clicked\0on_Bt_AxisRun_clicked\0"
    "on_Bt_AxisStop_clicked\0on_Bt_AxisGoHome_clicked\0"
    "onchB_MoveOri_stateChanged\0arg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtandLeisai[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    1,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void QtandLeisai::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QtandLeisai *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Bt_CardLint_clicked(); break;
        case 1: _t->on_Bt_AxisEn_clicked(); break;
        case 2: _t->on_Bt_AxisRestEn_clicked(); break;
        case 3: _t->on_Bt_AxisJOGAdd_clicked(); break;
        case 4: _t->on_Bt_AxisJOGSub_clicked(); break;
        case 5: _t->on_Bt_AxisRun_clicked(); break;
        case 6: _t->on_Bt_AxisStop_clicked(); break;
        case 7: _t->on_Bt_AxisGoHome_clicked(); break;
        case 8: _t->onchB_MoveOri_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QtandLeisai::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_QtandLeisai.data,
    qt_meta_data_QtandLeisai,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QtandLeisai::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtandLeisai::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtandLeisai.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int QtandLeisai::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
