/****************************************************************************
** Meta object code from reading C++ file 'todoswindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../CRM/todoswindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'todoswindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSTodosWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSTodosWindowENDCLASS = QtMocHelpers::stringData(
    "TodosWindow",
    "rechercherContact",
    "",
    "afficherInteractionsContact",
    "QModelIndex",
    "index",
    "modifierTodo",
    "ajouterTodo"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTodosWindowENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[12];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[28];
    char stringdata4[12];
    char stringdata5[6];
    char stringdata6[13];
    char stringdata7[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTodosWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTodosWindowENDCLASS_t qt_meta_stringdata_CLASSTodosWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "TodosWindow"
        QT_MOC_LITERAL(12, 17),  // "rechercherContact"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 27),  // "afficherInteractionsContact"
        QT_MOC_LITERAL(59, 11),  // "QModelIndex"
        QT_MOC_LITERAL(71, 5),  // "index"
        QT_MOC_LITERAL(77, 12),  // "modifierTodo"
        QT_MOC_LITERAL(90, 11)   // "ajouterTodo"
    },
    "TodosWindow",
    "rechercherContact",
    "",
    "afficherInteractionsContact",
    "QModelIndex",
    "index",
    "modifierTodo",
    "ajouterTodo"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTodosWindowENDCLASS[] = {

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

Q_CONSTINIT const QMetaObject TodosWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSTodosWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTodosWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTodosWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TodosWindow, std::true_type>,
        // method 'rechercherContact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'afficherInteractionsContact'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'modifierTodo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ajouterTodo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void TodosWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TodosWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->rechercherContact(); break;
        case 1: _t->afficherInteractionsContact((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 2: _t->modifierTodo(); break;
        case 3: _t->ajouterTodo(); break;
        default: ;
        }
    }
}

const QMetaObject *TodosWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TodosWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTodosWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TodosWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
