/********************************************************************************
** Form generated from reading UI file 'Check_Mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECK_MAINWINDOW_H
#define UI_CHECK_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Check_Mainwindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_3;
    QWidget *leftWidget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *changebtn;
    QPushButton *deletebtn;
    QPushButton *clearbtn;
    QPushButton *paybtn;
    QPushButton *backbtn;
    QPushButton *addmemberbtn;
    QGroupBox *CartgroupBox;
    QVBoxLayout *verticalLayout_4;
    QWidget *cartWidget;
    QVBoxLayout *verticalLayout_2;
    QTableView *cartlistView;
    QHBoxLayout *horizontalLayout;
    QLabel *totalLabel;
    QGroupBox *productgroupBox;
    QVBoxLayout *verticalLayout;
    QWidget *categoryWidget;
    QHBoxLayout *categoryButtonsLayout;
    QListWidget *productlistWidget;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QPushButton *historyBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Check_Mainwindow)
    {
        if (Check_Mainwindow->objectName().isEmpty())
            Check_Mainwindow->setObjectName("Check_Mainwindow");
        Check_Mainwindow->resize(890, 606);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Check_Mainwindow->sizePolicy().hasHeightForWidth());
        Check_Mainwindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(Check_Mainwindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_3 = new QHBoxLayout(centralwidget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        leftWidget = new QWidget(centralwidget);
        leftWidget->setObjectName("leftWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(leftWidget->sizePolicy().hasHeightForWidth());
        leftWidget->setSizePolicy(sizePolicy1);
        leftWidget->setBaseSize(QSize(0, 0));
        verticalLayout_3 = new QVBoxLayout(leftWidget);
        verticalLayout_3->setSpacing(20);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(-1, 9, -1, -1);
        changebtn = new QPushButton(leftWidget);
        changebtn->setObjectName("changebtn");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(changebtn->sizePolicy().hasHeightForWidth());
        changebtn->setSizePolicy(sizePolicy2);
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font.setPointSize(10);
        changebtn->setFont(font);
        changebtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2196F3;  /* \350\223\235\350\211\262\350\203\214\346\231\257 */\n"
"    border-radius: 10px;        /* 10px\345\234\206\350\247\222 */\n"
"    color: white;               /* \347\231\275\350\211\262\346\226\207\345\255\227 */\n"
"    padding: 6px;               /* \345\206\205\350\276\271\350\267\235 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #0b7dda;  /* \346\202\254\345\201\234\346\227\266\351\242\234\350\211\262\345\217\230\346\267\261 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005daa;  /* \347\202\271\345\207\273\346\227\266\351\242\234\350\211\262\346\233\264\346\267\261 */\n"
"}"));

        verticalLayout_3->addWidget(changebtn);

        deletebtn = new QPushButton(leftWidget);
        deletebtn->setObjectName("deletebtn");
        sizePolicy2.setHeightForWidth(deletebtn->sizePolicy().hasHeightForWidth());
        deletebtn->setSizePolicy(sizePolicy2);
        deletebtn->setFont(font);
        deletebtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2196F3;  /* \350\223\235\350\211\262\350\203\214\346\231\257 */\n"
"    border-radius: 10px;        /* 10px\345\234\206\350\247\222 */\n"
"    color: white;               /* \347\231\275\350\211\262\346\226\207\345\255\227 */\n"
"    padding: 6px;               /* \345\206\205\350\276\271\350\267\235 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #0b7dda;  /* \346\202\254\345\201\234\346\227\266\351\242\234\350\211\262\345\217\230\346\267\261 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005daa;  /* \347\202\271\345\207\273\346\227\266\351\242\234\350\211\262\346\233\264\346\267\261 */\n"
"}"));

        verticalLayout_3->addWidget(deletebtn);

        clearbtn = new QPushButton(leftWidget);
        clearbtn->setObjectName("clearbtn");
        sizePolicy2.setHeightForWidth(clearbtn->sizePolicy().hasHeightForWidth());
        clearbtn->setSizePolicy(sizePolicy2);
        clearbtn->setFont(font);
        clearbtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2196F3;  /* \350\223\235\350\211\262\350\203\214\346\231\257 */\n"
"    border-radius: 10px;        /* 10px\345\234\206\350\247\222 */\n"
"    color: white;               /* \347\231\275\350\211\262\346\226\207\345\255\227 */\n"
"    padding: 6px;               /* \345\206\205\350\276\271\350\267\235 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #0b7dda;  /* \346\202\254\345\201\234\346\227\266\351\242\234\350\211\262\345\217\230\346\267\261 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005daa;  /* \347\202\271\345\207\273\346\227\266\351\242\234\350\211\262\346\233\264\346\267\261 */\n"
"}"));

        verticalLayout_3->addWidget(clearbtn);

        paybtn = new QPushButton(leftWidget);
        paybtn->setObjectName("paybtn");
        sizePolicy2.setHeightForWidth(paybtn->sizePolicy().hasHeightForWidth());
        paybtn->setSizePolicy(sizePolicy2);
        paybtn->setFont(font);
        paybtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2196F3;  /* \350\223\235\350\211\262\350\203\214\346\231\257 */\n"
"    border-radius: 10px;        /* 10px\345\234\206\350\247\222 */\n"
"    color: white;               /* \347\231\275\350\211\262\346\226\207\345\255\227 */\n"
"    padding: 6px;               /* \345\206\205\350\276\271\350\267\235 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #0b7dda;  /* \346\202\254\345\201\234\346\227\266\351\242\234\350\211\262\345\217\230\346\267\261 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005daa;  /* \347\202\271\345\207\273\346\227\266\351\242\234\350\211\262\346\233\264\346\267\261 */\n"
"}"));

        verticalLayout_3->addWidget(paybtn);

        backbtn = new QPushButton(leftWidget);
        backbtn->setObjectName("backbtn");
        sizePolicy2.setHeightForWidth(backbtn->sizePolicy().hasHeightForWidth());
        backbtn->setSizePolicy(sizePolicy2);
        backbtn->setFont(font);
        backbtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2196F3;  /* \350\223\235\350\211\262\350\203\214\346\231\257 */\n"
"    border-radius: 10px;        /* 10px\345\234\206\350\247\222 */\n"
"    color: white;               /* \347\231\275\350\211\262\346\226\207\345\255\227 */\n"
"    padding: 6px;               /* \345\206\205\350\276\271\350\267\235 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #0b7dda;  /* \346\202\254\345\201\234\346\227\266\351\242\234\350\211\262\345\217\230\346\267\261 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005daa;  /* \347\202\271\345\207\273\346\227\266\351\242\234\350\211\262\346\233\264\346\267\261 */\n"
"}"));

        verticalLayout_3->addWidget(backbtn);

        addmemberbtn = new QPushButton(leftWidget);
        addmemberbtn->setObjectName("addmemberbtn");
        sizePolicy2.setHeightForWidth(addmemberbtn->sizePolicy().hasHeightForWidth());
        addmemberbtn->setSizePolicy(sizePolicy2);
        addmemberbtn->setFont(font);
        addmemberbtn->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #2196F3;  /* \350\223\235\350\211\262\350\203\214\346\231\257 */\n"
"    border-radius: 10px;        /* 10px\345\234\206\350\247\222 */\n"
"    color: white;               /* \347\231\275\350\211\262\346\226\207\345\255\227 */\n"
"    padding: 6px;               /* \345\206\205\350\276\271\350\267\235 */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #0b7dda;  /* \346\202\254\345\201\234\346\227\266\351\242\234\350\211\262\345\217\230\346\267\261 */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #005daa;  /* \347\202\271\345\207\273\346\227\266\351\242\234\350\211\262\346\233\264\346\267\261 */\n"
"}"));

        verticalLayout_3->addWidget(addmemberbtn);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 1);
        verticalLayout_3->setStretch(2, 1);
        verticalLayout_3->setStretch(3, 1);
        verticalLayout_3->setStretch(4, 1);
        verticalLayout_3->setStretch(5, 1);

        horizontalLayout_3->addWidget(leftWidget);

        CartgroupBox = new QGroupBox(centralwidget);
        CartgroupBox->setObjectName("CartgroupBox");
        sizePolicy1.setHeightForWidth(CartgroupBox->sizePolicy().hasHeightForWidth());
        CartgroupBox->setSizePolicy(sizePolicy1);
        CartgroupBox->setStyleSheet(QString::fromUtf8("/* \350\264\255\347\211\251\350\275\246\345\210\206\347\273\204\346\241\206\346\240\267\345\274\217 - \346\265\205\347\273\277\350\211\262\347\263\273\357\274\210\344\270\216\350\264\255\347\211\251\350\275\246\350\241\250\346\240\274\351\243\216\346\240\274\345\221\274\345\272\224\357\274\211 */\n"
"QGroupBox#CartgroupBox {\n"
"    border: 1px solid #CCCCCC;\n"
"    border-radius: 4px;\n"
"    margin-top: 8px;\n"
"    background-color: #F8FBF8; /* \346\236\201\346\265\205\347\232\204\347\273\277\350\211\262\350\203\214\346\231\257\357\274\214\344\270\216\350\264\255\347\211\251\350\275\246\350\241\250\346\240\274\347\232\204\346\265\205\347\273\277\351\243\216\346\240\274\345\215\217\350\260\203 */\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(CartgroupBox);
        verticalLayout_4->setObjectName("verticalLayout_4");
        cartWidget = new QWidget(CartgroupBox);
        cartWidget->setObjectName("cartWidget");
        cartWidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(cartWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        cartlistView = new QTableView(cartWidget);
        cartlistView->setObjectName("cartlistView");
        cartlistView->setStyleSheet(QString::fromUtf8("/* \350\264\255\347\211\251\350\275\246\350\241\250\346\240\274\346\225\264\344\275\223\346\240\267\345\274\217 */\n"
"QTableView#cartlistView {\n"
"    background-color: #F5F9F4; \n"
"    gridline-color: #DCE4E2; \n"
"    selection-background-color: #C8E6C9; \n"
"    selection-color: #000000; \n"
"    outline: none; \n"
"    /* \347\241\256\344\277\235\346\211\200\346\234\211\345\215\225\345\205\203\346\240\274\351\203\275\346\234\211\350\203\214\346\231\257\350\211\262 */\n"
"    alternate-background-color: #F5F9F4;\n"
"}\n"
"\n"
"/* \350\241\250\345\244\264\346\240\267\345\274\217 */\n"
"QTableView#cartlistView QHeaderView::section {\n"
"    background-color: #E8F5E9; \n"
"    color: #333333;\n"
"    font-weight: bold;\n"
"    border: 1px solid #DDDDDD; \n"
"    padding: 4px;\n"
"    /* \347\241\256\344\277\235\350\241\250\345\244\264\347\254\254\344\270\200\345\210\227\346\240\267\345\274\217\344\270\200\350\207\264 */\n"
"    border-radius: 0;\n"
"}\n"
"\n"
"/* \350\241\250\346\240\274\345\215\225\345\205"
                        "\203\346\240\274\346\240\267\345\274\217 - \346\211\200\346\234\211\350\241\214\345\222\214\345\210\227 */\n"
"QTableView#cartlistView::item {\n"
"    background-color: #F5F9F4 !important; /* \345\274\272\345\210\266\346\211\200\346\234\211\345\215\225\345\205\203\346\240\274\344\275\277\347\224\250\346\255\244\350\203\214\346\231\257\350\211\262 */\n"
"    padding: 6px; \n"
"    border: none; \n"
"}\n"
"\n"
"/* \351\200\211\344\270\255\350\241\214\347\232\204\345\215\225\345\205\203\346\240\274\346\240\267\345\274\217 */\n"
"QTableView#cartlistView::item:selected {\n"
"    background-color: #C8E6C9 !important; /* \345\274\272\345\210\266\351\200\211\344\270\255\350\241\214\344\275\277\347\224\250\346\255\244\350\203\214\346\231\257\350\211\262 */\n"
"    border: none; \n"
"    outline: none; \n"
"}\n"
"\n"
"/* \347\211\271\345\210\253\345\244\204\347\220\206\347\254\254\344\270\200\345\210\227\357\274\214\347\241\256\344\277\235\345\205\266\346\240\267\345\274\217\344\270\200\350\207\264 */\n"
"QTableView#car"
                        "tlistView::item:column(0) {\n"
"    background-color: #F5F9F4 !important; /* \347\241\256\344\277\235\347\254\254\344\270\200\345\210\227\346\211\200\346\234\211\345\215\225\345\205\203\346\240\274\344\275\277\347\224\250\346\255\244\350\203\214\346\231\257\350\211\262 */\n"
"}"));
        cartlistView->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        cartlistView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        cartlistView->horizontalHeader()->setVisible(false);
        cartlistView->horizontalHeader()->setDefaultSectionSize(57);

        verticalLayout_2->addWidget(cartlistView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        totalLabel = new QLabel(cartWidget);
        totalLabel->setObjectName("totalLabel");
        QFont font1;
        font1.setBold(true);
        totalLabel->setFont(font1);
        totalLabel->setStyleSheet(QString::fromUtf8("#totalLabel {\n"
"    color: #1B5E20;  /* \344\270\273\350\211\262\350\260\203\347\232\204\346\267\261\350\211\262\357\274\214\347\252\201\345\207\272\351\207\221\351\242\235 */\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"}"));

        horizontalLayout->addWidget(totalLabel);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 4);
        verticalLayout_2->setStretch(1, 1);

        verticalLayout_4->addWidget(cartWidget);


        horizontalLayout_3->addWidget(CartgroupBox);

        productgroupBox = new QGroupBox(centralwidget);
        productgroupBox->setObjectName("productgroupBox");
        sizePolicy1.setHeightForWidth(productgroupBox->sizePolicy().hasHeightForWidth());
        productgroupBox->setSizePolicy(sizePolicy1);
        productgroupBox->setMinimumSize(QSize(400, 0));
        productgroupBox->setAutoFillBackground(false);
        productgroupBox->setStyleSheet(QString::fromUtf8("/* \345\225\206\345\223\201\345\214\272\345\210\206\347\273\204\346\241\206\346\240\267\345\274\217 - \346\265\205\350\223\235\350\211\262\347\263\273\357\274\210\344\270\216\345\225\206\345\223\201\345\210\227\350\241\250\351\243\216\346\240\274\345\221\274\345\272\224\357\274\211 */\n"
"QGroupBox#productgroupBox {\n"
"    border: 1px solid #CCCCCC;\n"
"    border-radius: 4px;\n"
"    margin-top: 8px;\n"
"    background-color: #F5F9FD; /* \346\236\201\346\265\205\347\232\204\350\223\235\350\211\262\350\203\214\346\231\257\357\274\214\344\270\216\345\225\206\345\223\201\345\210\227\350\241\250\347\232\204\350\223\235\350\211\262\351\243\216\346\240\274\345\215\217\350\260\203 */\n"
"}"));
        verticalLayout = new QVBoxLayout(productgroupBox);
        verticalLayout->setObjectName("verticalLayout");
        categoryWidget = new QWidget(productgroupBox);
        categoryWidget->setObjectName("categoryWidget");
        sizePolicy1.setHeightForWidth(categoryWidget->sizePolicy().hasHeightForWidth());
        categoryWidget->setSizePolicy(sizePolicy1);
        categoryButtonsLayout = new QHBoxLayout(categoryWidget);
        categoryButtonsLayout->setObjectName("categoryButtonsLayout");

        verticalLayout->addWidget(categoryWidget);

        productlistWidget = new QListWidget(productgroupBox);
        productlistWidget->setObjectName("productlistWidget");
        sizePolicy1.setHeightForWidth(productlistWidget->sizePolicy().hasHeightForWidth());
        productlistWidget->setSizePolicy(sizePolicy1);
        productlistWidget->setStyleSheet(QString::fromUtf8("/* \345\225\206\345\223\201\346\265\217\350\247\210\345\214\272\346\225\264\344\275\223\346\240\267\345\274\217\357\274\210\346\265\205\350\223\235\345\272\225\350\211\262\357\274\211 */\n"
"QListWidget#productlistWidget {\n"
"    background-color: #E3F2FD;  /* \346\234\200\346\265\205\347\232\204\350\223\235\350\211\262\350\203\214\346\231\257\357\274\210\345\210\227\350\241\250\345\272\225\350\211\262\357\274\211 */\n"
"    border: none;\n"
"    padding: 0;\n"
"    margin: 0px;\n"
"    outline: none;\n"
"}\n"
"\n"
"/* \345\215\225\344\270\252\345\225\206\345\223\201\346\240\274\346\240\267\345\274\217\357\274\210\346\257\224\345\210\227\350\241\250\346\267\261\344\270\200\345\272\246\347\232\204\350\223\235\350\211\262\357\274\211 */\n"
"QListWidget#productlistWidget::item {\n"
"    background-color: #BBDEFB;  /* \345\225\206\345\223\201\345\272\225\350\211\262\357\274\210\346\257\224\345\210\227\350\241\250\346\267\261\357\274\214\346\257\224\346\226\207\345\255\227\346\265\205\357\274\211 */\n"
"    border"
                        "-radius: 4px;\n"
"    padding: 15px 5px;\n"
"    min-width: 120px;\n"
"    min-height: 140px;\n"
"    text-align: center;\n"
"    font-family: \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    font-size: 12px;\n"
"    color: #1565C0;  /* \346\267\261\350\223\235\350\211\262\346\226\207\345\255\227\357\274\210\346\234\200\346\267\261\357\274\214\347\241\256\344\277\235\346\270\205\346\231\260\357\274\211 */\n"
"    margin: 0px;\n"
"    border: 1px solid transparent;\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234\346\225\210\346\236\234\357\274\210\346\233\264\346\267\261\347\232\204\350\223\235\350\211\262\357\274\211 */\n"
"QListWidget#productlistWidget::item:hover {\n"
"    background-color: #90CAF9;  /* \346\202\254\345\201\234\346\227\266\346\257\224\345\225\206\345\223\201\345\272\225\350\211\262\346\267\261 */\n"
"    border-color: #64B5F6;\n"
"}\n"
"\n"
"/* \351\200\211\344\270\255\346\225\210\346\236\234\357\274\210\346\234\200\346\267\261\347\232\204\350\223\235\350\211\262"
                        "\357\274\214\347\252\201\345\207\272\351\200\211\344\270\255\347\212\266\346\200\201\357\274\211 */\n"
"QListWidget#productlistWidget::item:selected {\n"
"    background-color: #64B5F6;  /* \351\200\211\344\270\255\346\227\266\346\257\224\346\202\254\345\201\234\346\233\264\346\267\261 */\n"
"    color: #0D47A1;  /* \351\200\211\344\270\255\346\227\266\346\226\207\345\255\227\351\242\234\350\211\262\345\212\240\346\267\261\357\274\214\344\277\235\346\214\201\345\257\271\346\257\224\345\272\246 */\n"
"    border-color: #42A5F5;\n"
"    outline: none;\n"
"}\n"
"\n"
"/* \347\246\201\347\224\250\347\204\246\347\202\271\346\214\207\347\244\272\345\231\250 */\n"
"QListWidget#productlistWidget::item:focus {\n"
"    outline: none;\n"
"    border-color: #42A5F5;\n"
"}"));
        productlistWidget->setTextElideMode(Qt::TextElideMode::ElideNone);
        productlistWidget->setResizeMode(QListView::ResizeMode::Adjust);
        productlistWidget->setGridSize(QSize(96, 96));
        productlistWidget->setViewMode(QListView::ViewMode::IconMode);
        productlistWidget->setUniformItemSizes(true);
        productlistWidget->setWordWrap(true);

        verticalLayout->addWidget(productlistWidget);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        historyBtn = new QPushButton(productgroupBox);
        historyBtn->setObjectName("historyBtn");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/LogIn/icon/LogIn/history.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        historyBtn->setIcon(icon);
        historyBtn->setFlat(true);

        horizontalLayout_7->addWidget(historyBtn);


        verticalLayout->addLayout(horizontalLayout_7);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 7);

        horizontalLayout_3->addWidget(productgroupBox);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 3);
        horizontalLayout_3->setStretch(2, 3);
        Check_Mainwindow->setCentralWidget(centralwidget);
        productgroupBox->raise();
        CartgroupBox->raise();
        leftWidget->raise();
        menubar = new QMenuBar(Check_Mainwindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 890, 22));
        Check_Mainwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(Check_Mainwindow);
        statusbar->setObjectName("statusbar");
        Check_Mainwindow->setStatusBar(statusbar);

        retranslateUi(Check_Mainwindow);

        QMetaObject::connectSlotsByName(Check_Mainwindow);
    } // setupUi

    void retranslateUi(QMainWindow *Check_Mainwindow)
    {
        Check_Mainwindow->setWindowTitle(QCoreApplication::translate("Check_Mainwindow", "MainWindow", nullptr));
        changebtn->setText(QCoreApplication::translate("Check_Mainwindow", "\346\224\271\346\225\260", nullptr));
        deletebtn->setText(QCoreApplication::translate("Check_Mainwindow", "\345\210\240\351\231\244", nullptr));
        clearbtn->setText(QCoreApplication::translate("Check_Mainwindow", "\346\270\205\347\251\272", nullptr));
        paybtn->setText(QCoreApplication::translate("Check_Mainwindow", "\346\224\257\344\273\230", nullptr));
        backbtn->setText(QCoreApplication::translate("Check_Mainwindow", "\350\277\224\345\233\236", nullptr));
        addmemberbtn->setText(QCoreApplication::translate("Check_Mainwindow", "\346\267\273\345\212\240\344\274\232\345\221\230", nullptr));
        CartgroupBox->setTitle(QString());
        totalLabel->setText(QString());
        productgroupBox->setTitle(QString());
#if QT_CONFIG(tooltip)
        historyBtn->setToolTip(QCoreApplication::translate("Check_Mainwindow", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class Check_Mainwindow: public Ui_Check_Mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECK_MAINWINDOW_H
