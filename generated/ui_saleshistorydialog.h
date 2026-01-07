/********************************************************************************
** Form generated from reading UI file 'saleshistorydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALESHISTORYDIALOG_H
#define UI_SALESHISTORYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_SalesHistoryDialog
{
public:

    void setupUi(QDialog *SalesHistoryDialog)
    {
        if (SalesHistoryDialog->objectName().isEmpty())
            SalesHistoryDialog->setObjectName("SalesHistoryDialog");
        SalesHistoryDialog->resize(400, 300);

        retranslateUi(SalesHistoryDialog);

        QMetaObject::connectSlotsByName(SalesHistoryDialog);
    } // setupUi

    void retranslateUi(QDialog *SalesHistoryDialog)
    {
        SalesHistoryDialog->setWindowTitle(QCoreApplication::translate("SalesHistoryDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SalesHistoryDialog: public Ui_SalesHistoryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALESHISTORYDIALOG_H
