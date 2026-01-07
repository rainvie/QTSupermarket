/****************************************************************************
** Meta object code from reading C++ file 'StockDialog.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/Product/StockDialog.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StockDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.1. It"
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
struct qt_meta_tag_ZN11StockDialogE_t {};
} // unnamed namespace

template <> constexpr inline auto StockDialog::qt_create_metaobjectdata<qt_meta_tag_ZN11StockDialogE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "StockDialog",
        "onOkButtonClicked",
        "",
        "onCategoryChanged",
        "category",
        "onProductChanged",
        "productText",
        "onAddToTableClicked",
        "onRemoveFromTableClicked",
        "onClearTableClicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'onOkButtonClicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onCategoryChanged'
        QtMocHelpers::SlotData<void(const QString &)>(3, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Slot 'onProductChanged'
        QtMocHelpers::SlotData<void(const QString &)>(5, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 6 },
        }}),
        // Slot 'onAddToTableClicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onRemoveFromTableClicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onClearTableClicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<StockDialog, qt_meta_tag_ZN11StockDialogE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject StockDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11StockDialogE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11StockDialogE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11StockDialogE_t>.metaTypes,
    nullptr
} };

void StockDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<StockDialog *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->onOkButtonClicked(); break;
        case 1: _t->onCategoryChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->onProductChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->onAddToTableClicked(); break;
        case 4: _t->onRemoveFromTableClicked(); break;
        case 5: _t->onClearTableClicked(); break;
        default: ;
        }
    }
}

const QMetaObject *StockDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StockDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11StockDialogE_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int StockDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
