#ifndef ADDPRODUCTDIALOG_H
#define ADDPRODUCTDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QInputDialog>
#include <QSplitter>

class AddProductDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddProductDialog(QWidget *parent = nullptr);
    ~AddProductDialog();

    QString getName() const;
    QString getBarcode() const;
    double getPrice() const;
    int getStock() const;
    int getReorderPoint() const;  // 新增获取补货点
    QString getCategory() const;

private slots:
    void addNewCategory();

private:
    QLineEdit *nameLineEdit;
    QLineEdit *barcodeLineEdit;
    QDoubleSpinBox *priceSpinBox;
    QSpinBox *stockSpinBox;
    QSpinBox *reorderPointSpinBox;  // 新增补货点输入框
    QComboBox *categoryComboBox;
    QPushButton *addCategoryButton;
    QPushButton *okButton;
    QPushButton *cancelButton;
};

#endif // ADDPRODUCTDIALOG_H
