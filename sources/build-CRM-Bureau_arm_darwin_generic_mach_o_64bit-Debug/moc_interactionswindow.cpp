/****************************************************************************
** Meta object code from reading C++ file 'interactionswindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CRM/interactionswindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'interactionswindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSInteractionsWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSInteractionsWindowENDCLASS = QtMocHelpers::stringData(
    "InteractionsWindow",
    "rechercherContact",
    "",
    "afficherInteractionsContact",
    "QModelIndex",
    "index",
    "modifierInteraction",
    "ajouterInteraction"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSInteractionsWindowENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[19];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[28];
    char stringdata4[12];
    char stringdata5[6];
    char stringdata6[20];
    char stringdata7[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSInteractionsWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSInteractionsWindowENDCLASS_t qt_meta_stringdata_CLASSInteractionsWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 18),  // "InteractionsWindow"
        QT_MOC_LITERAL(19, 17),  // "rechercherContact"
        QT_MOC_LITERAL(37, 0),  // ""
        QT_MOC_LITERAL(38, 27),  // "afficherInteractionsContact"
        QT_MOC_LITERAL(66, 11),  // "QModelIndex"
        QT_MOC_LITERAL(78, 5),  // "index"
        QT_MOC_LITERAL(84, 19),  // "modifierInteraction"
        QT_MOC_LITERAL(104, 18)   // "ajouterInteraction"
    },
    "InteractionsWindow",
    "rechercherContact",
    "",
    "afficherInteractionsContact",
    "QModelIndex",
    "index",
    "modifierInteraction",
    "ajouterInteraction"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSInteractionsWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x08,    1 /* Private */,
       3,    1,   39,    2, 0x08,    2 /* Private */,
       6,    0,   42,    2, 0x08,    4 /* Private */,
       7,    0,   43,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject InteractionsWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSInteractionsWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSInteractionsWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSInteractionsWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<InteractionsWindow, std::true_type>,
        // method 'rechercherContact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'afficherInteractionsContact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'modifierInteraction'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ajouterInteraction'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void InteractionsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InteractionsWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->rechercherContact(); break;
        case 1: _t->afficherInteractionsContact((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 2: _t->modifierInteraction(); break;
        case 3: _t->ajouterInteraction(); break;
        default: ;
        }
    }
}

const QMetaObject *InteractionsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InteractionsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSInteractionsWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int InteractionsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP