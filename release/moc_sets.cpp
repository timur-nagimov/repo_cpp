/****************************************************************************
** Meta object code from reading C++ file 'sets.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sets.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sets.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSsetsENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSsetsENDCLASS = QtMocHelpers::stringData(
    "sets",
    "loadExercises",
    "",
    "addSet",
    "deleteSet",
    "setupConnections",
    "loadSets",
    "on_addSet_pushButton_clicked",
    "on_pushButton_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSsetsENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[5];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[7];
    char stringdata4[10];
    char stringdata5[17];
    char stringdata6[9];
    char stringdata7[29];
    char stringdata8[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSsetsENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSsetsENDCLASS_t qt_meta_stringdata_CLASSsetsENDCLASS = {
    {
        QT_MOC_LITERAL(0, 4),  // "sets"
        QT_MOC_LITERAL(5, 13),  // "loadExercises"
        QT_MOC_LITERAL(19, 0),  // ""
        QT_MOC_LITERAL(20, 6),  // "addSet"
        QT_MOC_LITERAL(27, 9),  // "deleteSet"
        QT_MOC_LITERAL(37, 16),  // "setupConnections"
        QT_MOC_LITERAL(54, 8),  // "loadSets"
        QT_MOC_LITERAL(63, 28),  // "on_addSet_pushButton_clicked"
        QT_MOC_LITERAL(92, 21)   // "on_pushButton_clicked"
    },
    "sets",
    "loadExercises",
    "",
    "addSet",
    "deleteSet",
    "setupConnections",
    "loadSets",
    "on_addSet_pushButton_clicked",
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSsetsENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject sets::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSsetsENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSsetsENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSsetsENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<sets, std::true_type>,
        // method 'loadExercises'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addSet'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteSet'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setupConnections'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadSets'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addSet_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void sets::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<sets *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->loadExercises(); break;
        case 1: _t->addSet(); break;
        case 2: _t->deleteSet(); break;
        case 3: _t->setupConnections(); break;
        case 4: _t->loadSets(); break;
        case 5: _t->on_addSet_pushButton_clicked(); break;
        case 6: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *sets::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *sets::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSsetsENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int sets::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
