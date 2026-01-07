/********************************************************************************
** Form generated from reading UI file 'memberregisterdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMBERREGISTERDIALOG_H
#define UI_MEMBERREGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MemberRegisterDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *phoneEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDateEdit *birthdayEdit;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *registerButton;
    QPushButton *resetButton;
    QPushButton *backButton;

    void setupUi(QDialog *MemberRegisterDialog)
    {
        if (MemberRegisterDialog->objectName().isEmpty())
            MemberRegisterDialog->setObjectName("MemberRegisterDialog");
        MemberRegisterDialog->resize(340, 385);
        verticalLayoutWidget = new QWidget(MemberRegisterDialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(30, 50, 288, 211));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        phoneEdit = new QLineEdit(verticalLayoutWidget);
        phoneEdit->setObjectName("phoneEdit");

        horizontalLayout->addWidget(phoneEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        nameEdit = new QLineEdit(verticalLayoutWidget);
        nameEdit->setObjectName("nameEdit");

        horizontalLayout_2->addWidget(nameEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        birthdayEdit = new QDateEdit(verticalLayoutWidget);
        birthdayEdit->setObjectName("birthdayEdit");
        birthdayEdit->setMinimumSize(QSize(230, 0));

        horizontalLayout_3->addWidget(birthdayEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayoutWidget_4 = new QWidget(MemberRegisterDialog);
        horizontalLayoutWidget_4->setObjectName("horizontalLayoutWidget_4");
        horizontalLayoutWidget_4->setGeometry(QRect(30, 290, 281, 80));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        registerButton = new QPushButton(horizontalLayoutWidget_4);
        registerButton->setObjectName("registerButton");

        horizontalLayout_4->addWidget(registerButton);

        resetButton = new QPushButton(horizontalLayoutWidget_4);
        resetButton->setObjectName("resetButton");

        horizontalLayout_4->addWidget(resetButton);

        backButton = new QPushButton(horizontalLayoutWidget_4);
        backButton->setObjectName("backButton");

        horizontalLayout_4->addWidget(backButton);


        retranslateUi(MemberRegisterDialog);

        QMetaObject::connectSlotsByName(MemberRegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *MemberRegisterDialog)
    {
        MemberRegisterDialog->setWindowTitle(QCoreApplication::translate("MemberRegisterDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MemberRegisterDialog", "\346\211\213\346\234\272\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MemberRegisterDialog", "  \345\247\223\345\220\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MemberRegisterDialog", "  \347\224\237\346\227\245\357\274\232", nullptr));
        registerButton->setText(QCoreApplication::translate("MemberRegisterDialog", "\346\263\250\345\206\214", nullptr));
        resetButton->setText(QCoreApplication::translate("MemberRegisterDialog", "\351\207\215\347\275\256", nullptr));
        backButton->setText(QCoreApplication::translate("MemberRegisterDialog", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MemberRegisterDialog: public Ui_MemberRegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMBERREGISTERDIALOG_H
