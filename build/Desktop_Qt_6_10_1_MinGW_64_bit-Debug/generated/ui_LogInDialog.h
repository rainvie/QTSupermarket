/********************************************************************************
** Form generated from reading UI file 'LogInDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *usernameEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *passwordEdit;
    QPushButton *codeshow;
    QLabel *errorLabel;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Login;
    QPushButton *Register;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName("LoginDialog");
        LoginDialog->resize(650, 480);
        LoginDialog->setAutoFillBackground(false);
        LoginDialog->setSizeGripEnabled(false);
        LoginDialog->setModal(false);
        verticalLayoutWidget = new QWidget(LoginDialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(100, 120, 450, 200));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        usernameEdit = new QLineEdit(verticalLayoutWidget);
        usernameEdit->setObjectName("usernameEdit");
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font.setPointSize(12);
        font.setBold(false);
        usernameEdit->setFont(font);

        horizontalLayout->addWidget(usernameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        passwordEdit = new QLineEdit(verticalLayoutWidget);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setFont(font);

        horizontalLayout_2->addWidget(passwordEdit);

        codeshow = new QPushButton(verticalLayoutWidget);
        codeshow->setObjectName("codeshow");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/LogIn/icon/LogIn/codeshow.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        codeshow->setIcon(icon);
        codeshow->setFlat(true);

        horizontalLayout_2->addWidget(codeshow);


        verticalLayout->addLayout(horizontalLayout_2);

        errorLabel = new QLabel(LoginDialog);
        errorLabel->setObjectName("errorLabel");
        errorLabel->setGeometry(QRect(50, 410, 550, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font1.setPointSize(14);
        font1.setBold(true);
        errorLabel->setFont(font1);
        horizontalLayoutWidget = new QWidget(LoginDialog);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(150, 340, 350, 60));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        Login = new QPushButton(horizontalLayoutWidget);
        Login->setObjectName("Login");
        Login->setMinimumSize(QSize(0, 30));

        horizontalLayout_3->addWidget(Login);

        Register = new QPushButton(horizontalLayoutWidget);
        Register->setObjectName("Register");
        Register->setMinimumSize(QSize(0, 30));

        horizontalLayout_3->addWidget(Register);

        label_3 = new QLabel(LoginDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(200, 30, 250, 70));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font2.setPointSize(20);
        font2.setBold(true);
        label_3->setFont(font2);
        label_3->setMouseTracking(true);
        label_3->setAutoFillBackground(false);
        label_3->setScaledContents(false);
        label_4 = new QLabel(LoginDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 18, 80, 60));
        label_4->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"      image: url(:/LogIn/icon/LogIn/shide.png);\n"
"    }\n"
"    QLabel:hover {\n"
"      image: url(:/LogIn/icon/LogIn/sshow.png);\n"
"    }"));
        label_4->setScaledContents(true);

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QCoreApplication::translate("LoginDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("LoginDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("LoginDialog", "  \345\257\206\347\240\201\357\274\232", nullptr));
        codeshow->setText(QString());
        errorLabel->setText(QString());
        Login->setText(QCoreApplication::translate("LoginDialog", "\347\231\273\345\275\225", nullptr));
        Register->setText(QCoreApplication::translate("LoginDialog", "\346\263\250\345\206\214", nullptr));
        label_3->setText(QCoreApplication::translate("LoginDialog", "<html><head/><body><p>\350\266\205\345\270\202\345\272\223\345\255\230\347\256\241\347\220\206\347\263\273\347\273\237</p></body></html>", nullptr));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
