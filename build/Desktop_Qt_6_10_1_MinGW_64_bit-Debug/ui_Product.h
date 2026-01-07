/********************************************************************************
** Form generated from reading UI file 'Product.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCT_H
#define UI_PRODUCT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Product
{
public:
    QAction *Add_Product;
    QAction *Delete_Product;
    QAction *Put_Product;
    QAction *importAction;
    QAction *exportAction;
    QAction *Out_Product;
    QAction *backToLogin;
    QAction *Sale_Action;
    QAction *Modify_Reorder_Point;
    QAction *Inventory_Report;
    QAction *Show_Chart_Action;
    QWidget *centralwidget;
    QTableView *productTableView;
    QComboBox *categoryComboBox;
    QLineEdit *searchLineEdit;
    QPushButton *Search_Product;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Product)
    {
        if (Product->objectName().isEmpty())
            Product->setObjectName("Product");
        Product->resize(662, 466);
        Add_Product = new QAction(Product);
        Add_Product->setObjectName("Add_Product");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/Product/Add.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Add_Product->setIcon(icon);
        Add_Product->setMenuRole(QAction::MenuRole::NoRole);
        Delete_Product = new QAction(Product);
        Delete_Product->setObjectName("Delete_Product");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/Product/Delete.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Delete_Product->setIcon(icon1);
        Delete_Product->setMenuRole(QAction::MenuRole::NoRole);
        Put_Product = new QAction(Product);
        Put_Product->setObjectName("Put_Product");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/Product/Put.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Put_Product->setIcon(icon2);
        Put_Product->setMenuRole(QAction::MenuRole::NoRole);
        importAction = new QAction(Product);
        importAction->setObjectName("importAction");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/Product/NumIn.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        importAction->setIcon(icon3);
        importAction->setMenuRole(QAction::MenuRole::NoRole);
        exportAction = new QAction(Product);
        exportAction->setObjectName("exportAction");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/Product/NumOut.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        exportAction->setIcon(icon4);
        exportAction->setMenuRole(QAction::MenuRole::NoRole);
        Out_Product = new QAction(Product);
        Out_Product->setObjectName("Out_Product");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/Product/Out.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Out_Product->setIcon(icon5);
        Out_Product->setMenuRole(QAction::MenuRole::NoRole);
        backToLogin = new QAction(Product);
        backToLogin->setObjectName("backToLogin");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icon/Product/Exit.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        backToLogin->setIcon(icon6);
        backToLogin->setMenuRole(QAction::MenuRole::NoRole);
        Sale_Action = new QAction(Product);
        Sale_Action->setObjectName("Sale_Action");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icon/Product/Statistics.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Sale_Action->setIcon(icon7);
        Sale_Action->setMenuRole(QAction::MenuRole::NoRole);
        Modify_Reorder_Point = new QAction(Product);
        Modify_Reorder_Point->setObjectName("Modify_Reorder_Point");
        Modify_Reorder_Point->setIcon(icon7);
        Modify_Reorder_Point->setMenuRole(QAction::MenuRole::NoRole);
        Inventory_Report = new QAction(Product);
        Inventory_Report->setObjectName("Inventory_Report");
        Inventory_Report->setIcon(icon7);
        Inventory_Report->setMenuRole(QAction::MenuRole::NoRole);
        Show_Chart_Action = new QAction(Product);
        Show_Chart_Action->setObjectName("Show_Chart_Action");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icon/Product/Chart.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Show_Chart_Action->setIcon(icon8);
        Show_Chart_Action->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(Product);
        centralwidget->setObjectName("centralwidget");
        productTableView = new QTableView(centralwidget);
        productTableView->setObjectName("productTableView");
        productTableView->setGeometry(QRect(0, 20, 661, 391));
        categoryComboBox = new QComboBox(centralwidget);
        categoryComboBox->setObjectName("categoryComboBox");
        categoryComboBox->setGeometry(QRect(0, 0, 101, 21));
        searchLineEdit = new QLineEdit(centralwidget);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setGeometry(QRect(110, 0, 471, 20));
        Search_Product = new QPushButton(centralwidget);
        Search_Product->setObjectName("Search_Product");
        Search_Product->setGeometry(QRect(590, 0, 71, 21));
        Product->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Product);
        statusbar->setObjectName("statusbar");
        Product->setStatusBar(statusbar);
        toolBar = new QToolBar(Product);
        toolBar->setObjectName("toolBar");
        Product->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        toolBar->addAction(Add_Product);
        toolBar->addAction(Delete_Product);
        toolBar->addAction(Put_Product);
        toolBar->addAction(Out_Product);
        toolBar->addAction(Modify_Reorder_Point);
        toolBar->addAction(Inventory_Report);
        toolBar->addAction(Sale_Action);
        toolBar->addAction(Show_Chart_Action);
        toolBar->addAction(importAction);
        toolBar->addAction(exportAction);
        toolBar->addAction(backToLogin);

        retranslateUi(Product);

        QMetaObject::connectSlotsByName(Product);
    } // setupUi

    void retranslateUi(QMainWindow *Product)
    {
        Product->setWindowTitle(QCoreApplication::translate("Product", "MainWindow", nullptr));
        Add_Product->setText(QCoreApplication::translate("Product", "\346\267\273\345\212\240\345\225\206\345\223\201", nullptr));
        Delete_Product->setText(QCoreApplication::translate("Product", "\345\210\240\351\231\244\345\225\206\345\223\201", nullptr));
        Put_Product->setText(QCoreApplication::translate("Product", "\345\225\206\345\223\201\345\205\245\345\272\223", nullptr));
        importAction->setText(QCoreApplication::translate("Product", "\345\257\274\345\205\245\346\225\260\346\215\256", nullptr));
        exportAction->setText(QCoreApplication::translate("Product", "\345\257\274\345\207\272\346\225\260\346\215\256", nullptr));
        Out_Product->setText(QCoreApplication::translate("Product", "\345\225\206\345\223\201\345\207\272\345\272\223", nullptr));
        backToLogin->setText(QCoreApplication::translate("Product", "\350\277\224\345\233\236", nullptr));
        Sale_Action->setText(QCoreApplication::translate("Product", "\351\224\200\345\224\256\347\273\237\350\256\241\347\234\213\346\235\277", nullptr));
        Modify_Reorder_Point->setText(QCoreApplication::translate("Product", "\344\277\256\346\224\271\350\241\245\350\264\247\347\202\271", nullptr));
        Inventory_Report->setText(QCoreApplication::translate("Product", "\345\272\223\345\255\230\346\212\245\345\221\212", nullptr));
        Show_Chart_Action->setText(QCoreApplication::translate("Product", "\345\272\223\345\255\230\345\233\276\350\241\250", nullptr));
        Search_Product->setText(QCoreApplication::translate("Product", "\345\225\206\345\223\201\346\220\234\347\264\242", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("Product", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Product: public Ui_Product {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCT_H
