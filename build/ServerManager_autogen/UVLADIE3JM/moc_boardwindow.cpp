/****************************************************************************
** Meta object code from reading C++ file 'boardwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../src/boardwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'boardwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_boardwindow_t {
    const uint offsetsAndSize[28];
    char stringdata0[217];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_boardwindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_boardwindow_t qt_meta_stringdata_boardwindow = {
    {
QT_MOC_LITERAL(0, 11), // "boardwindow"
QT_MOC_LITERAL(12, 18), // "initDistributeTask"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 12), // "QList<Task>&"
QT_MOC_LITERAL(45, 7), // "taskArr"
QT_MOC_LITERAL(53, 14), // "timeoutSlot500"
QT_MOC_LITERAL(68, 15), // "timeoutSlot2000"
QT_MOC_LITERAL(84, 19), // "updateTaskChartData"
QT_MOC_LITERAL(104, 19), // "updateTaskChartSlot"
QT_MOC_LITERAL(124, 19), // "updateMemoChartData"
QT_MOC_LITERAL(144, 19), // "updateMemoChartSlot"
QT_MOC_LITERAL(164, 18), // "updateGpuChartData"
QT_MOC_LITERAL(183, 18), // "updateGpuChartSlot"
QT_MOC_LITERAL(202, 14) // "updateDataSlot"

    },
    "boardwindow\0initDistributeTask\0\0"
    "QList<Task>&\0taskArr\0timeoutSlot500\0"
    "timeoutSlot2000\0updateTaskChartData\0"
    "updateTaskChartSlot\0updateMemoChartData\0"
    "updateMemoChartSlot\0updateGpuChartData\0"
    "updateGpuChartSlot\0updateDataSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_boardwindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x08,    1 /* Private */,
       5,    0,   77,    2, 0x08,    3 /* Private */,
       6,    0,   78,    2, 0x08,    4 /* Private */,
       7,    0,   79,    2, 0x08,    5 /* Private */,
       8,    0,   80,    2, 0x08,    6 /* Private */,
       9,    0,   81,    2, 0x08,    7 /* Private */,
      10,    0,   82,    2, 0x08,    8 /* Private */,
      11,    0,   83,    2, 0x08,    9 /* Private */,
      12,    0,   84,    2, 0x08,   10 /* Private */,
      13,    0,   85,    2, 0x08,   11 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void boardwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<boardwindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->initDistributeTask((*reinterpret_cast< std::add_pointer_t<QList<Task>&>>(_a[1]))); break;
        case 1: _t->timeoutSlot500(); break;
        case 2: _t->timeoutSlot2000(); break;
        case 3: _t->updateTaskChartData(); break;
        case 4: _t->updateTaskChartSlot(); break;
        case 5: _t->updateMemoChartData(); break;
        case 6: _t->updateMemoChartSlot(); break;
        case 7: _t->updateGpuChartData(); break;
        case 8: _t->updateGpuChartSlot(); break;
        case 9: _t->updateDataSlot(); break;
        default: ;
        }
    }
}

const QMetaObject boardwindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_boardwindow.offsetsAndSize,
    qt_meta_data_boardwindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_boardwindow_t
, QtPrivate::TypeAndForceComplete<boardwindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QVector<Task> &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *boardwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *boardwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_boardwindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int boardwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
