/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *adminUsernameEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *adminPasswordEdit;
    QPushButton *codeshow;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *usernameEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *passwordEdit;
    QPushButton *codeshow_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *confirmPasswordEdit;
    QPushButton *codeshow_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QComboBox *genderCombo;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_8;
    QSpinBox *ageSpinBox;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *registerButton;
    QPushButton *backButton;
    QFrame *line;
    QFrame *line_2;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName("RegisterDialog");
        RegisterDialog->resize(400, 520);
        RegisterDialog->setMinimumSize(QSize(0, 0));
        verticalLayoutWidget = new QWidget(RegisterDialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 380, 100));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        adminUsernameEdit = new QLineEdit(verticalLayoutWidget);
        adminUsernameEdit->setObjectName("adminUsernameEdit");
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font.setPointSize(12);
        font.setBold(false);
        adminUsernameEdit->setFont(font);

        horizontalLayout->addWidget(adminUsernameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        adminPasswordEdit = new QLineEdit(verticalLayoutWidget);
        adminPasswordEdit->setObjectName("adminPasswordEdit");
        adminPasswordEdit->setFont(font);

        horizontalLayout_2->addWidget(adminPasswordEdit);

        codeshow = new QPushButton(verticalLayoutWidget);
        codeshow->setObjectName("codeshow");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/LogIn/icon/LogIn/codeshow.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        codeshow->setIcon(icon);
        codeshow->setFlat(true);

        horizontalLayout_2->addWidget(codeshow);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayoutWidget_2 = new QWidget(RegisterDialog);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(10, 120, 380, 310));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);

        usernameEdit = new QLineEdit(verticalLayoutWidget_2);
        usernameEdit->setObjectName("usernameEdit");
        usernameEdit->setFont(font);

        horizontalLayout_3->addWidget(usernameEdit);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName("label_6");

        horizontalLayout_5->addWidget(label_6);

        passwordEdit = new QLineEdit(verticalLayoutWidget_2);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setFont(font);

        horizontalLayout_5->addWidget(passwordEdit);

        codeshow_2 = new QPushButton(verticalLayoutWidget_2);
        codeshow_2->setObjectName("codeshow_2");
        codeshow_2->setIcon(icon);
        codeshow_2->setFlat(true);

        horizontalLayout_5->addWidget(codeshow_2);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName("label_5");

        horizontalLayout_4->addWidget(label_5);

        confirmPasswordEdit = new QLineEdit(verticalLayoutWidget_2);
        confirmPasswordEdit->setObjectName("confirmPasswordEdit");
        confirmPasswordEdit->setFont(font);

        horizontalLayout_4->addWidget(confirmPasswordEdit);

        codeshow_3 = new QPushButton(verticalLayoutWidget_2);
        codeshow_3->setObjectName("codeshow_3");
        codeshow_3->setIcon(icon);
        codeshow_3->setFlat(true);

        horizontalLayout_4->addWidget(codeshow_3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_7 = new QLabel(verticalLayoutWidget_2);
        label_7->setObjectName("label_7");

        horizontalLayout_7->addWidget(label_7);

        genderCombo = new QComboBox(verticalLayoutWidget_2);
        genderCombo->addItem(QString());
        genderCombo->addItem(QString());
        genderCombo->addItem(QString());
        genderCombo->setObjectName("genderCombo");
        genderCombo->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(genderCombo->sizePolicy().hasHeightForWidth());
        genderCombo->setSizePolicy(sizePolicy);
        genderCombo->setMinimumSize(QSize(60, 0));
        genderCombo->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_7->addWidget(genderCombo);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_8 = new QLabel(verticalLayoutWidget_2);
        label_8->setObjectName("label_8");

        horizontalLayout_8->addWidget(label_8);

        ageSpinBox = new QSpinBox(verticalLayoutWidget_2);
        ageSpinBox->setObjectName("ageSpinBox");
        sizePolicy.setHeightForWidth(ageSpinBox->sizePolicy().hasHeightForWidth());
        ageSpinBox->setSizePolicy(sizePolicy);
        ageSpinBox->setMinimumSize(QSize(60, 0));
        ageSpinBox->setMaximumSize(QSize(80, 16777215));
        ageSpinBox->setMaximum(120);

        horizontalLayout_8->addWidget(ageSpinBox);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayoutWidget_3 = new QWidget(RegisterDialog);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(10, 440, 380, 60));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        registerButton = new QPushButton(horizontalLayoutWidget_3);
        registerButton->setObjectName("registerButton");
        registerButton->setMinimumSize(QSize(0, 30));

        horizontalLayout_6->addWidget(registerButton);

        backButton = new QPushButton(horizontalLayoutWidget_3);
        backButton->setObjectName("backButton");
        backButton->setMinimumSize(QSize(0, 30));

        horizontalLayout_6->addWidget(backButton);

        line = new QFrame(RegisterDialog);
        line->setObjectName("line");
        line->setGeometry(QRect(10, 110, 380, 16));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(RegisterDialog);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(10, 430, 380, 16));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        retranslateUi(RegisterDialog);

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QCoreApplication::translate("RegisterDialog", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterDialog", "\347\256\241\347\220\206\345\221\230\350\264\246\345\217\267\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterDialog", "\347\256\241\347\220\206\345\221\230\345\257\206\347\240\201\357\274\232", nullptr));
        codeshow->setText(QString());
        label_4->setText(QCoreApplication::translate("RegisterDialog", "\346\224\266\351\223\266\345\221\230\345\220\215\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("RegisterDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        codeshow_2->setText(QString());
        label_5->setText(QCoreApplication::translate("RegisterDialog", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        codeshow_3->setText(QString());
        label_7->setText(QCoreApplication::translate("RegisterDialog", "\346\200\247\345\210\253\357\274\232", nullptr));
        genderCombo->setItemText(0, QCoreApplication::translate("RegisterDialog", "\347\224\267", nullptr));
        genderCombo->setItemText(1, QCoreApplication::translate("RegisterDialog", "\345\245\263", nullptr));
        genderCombo->setItemText(2, QCoreApplication::translate("RegisterDialog", "\345\205\266\344\273\226", nullptr));

        genderCombo->setCurrentText(QCoreApplication::translate("RegisterDialog", "\347\224\267", nullptr));
        label_8->setText(QCoreApplication::translate("RegisterDialog", "\345\271\264\351\276\204\357\274\232", nullptr));
        registerButton->setText(QCoreApplication::translate("RegisterDialog", "\346\263\250\345\206\214", nullptr));
        backButton->setText(QCoreApplication::translate("RegisterDialog", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
