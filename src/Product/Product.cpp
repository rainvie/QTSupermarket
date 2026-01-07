#include "Product/Product.h"
#include "qtimer.h"
#include "ui_Product.h"
#include "Product/AddProductDialog.h"
#include "Product/StockDialog.h"
#include "Product/SalesStatisticsDialog.h"
#include "Style/StyleManager.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QHeaderView>
#include <QStandardItem>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QTextEdit>
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QTabWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>

Product::Product(QString name, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Product),
    dbManager(&DBManager::instance()),
    name(name)
{
    ui->setupUi(this);
    initUI();
    setupConnections();
    loadProducts();
    setWindowTitle(QString("超市库存管理系统 - 当前用户: %1").arg(name));

    // 设置窗口默认大小以确保内容完整显示
    resize(1200, 700);
    // 设置窗口最小尺寸，确保标题栏内容完整显示
    setMinimumSize(1000, 600);

    // Apply the global application style instead of hardcoded styling
    setStyleSheet(StyleManager::instance().getApplicationStyle());
}

Product::~Product()
{
    delete ui;
}

void Product::initUI()
{
    setWindowTitle("超市库存管理系统");

    // 创建中央部件和主布局
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // 主垂直布局
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(10, 10, 10, 10);
    mainLayout->setSpacing(10);

    // 搜索区域布局
    QHBoxLayout *searchLayout = new QHBoxLayout();
    searchLayout->setSpacing(5);

    // 关联UI控件
    searchLineEdit = ui->searchLineEdit;
    categoryComboBox = ui->categoryComboBox;

    // 设置搜索框和下拉框的最小宽度
    searchLineEdit->setMinimumWidth(200);
    categoryComboBox->setMinimumWidth(120);

    // 添加搜索区域控件到布局
    searchLayout->addWidget(new QLabel("分类:", this));
    searchLayout->addWidget(categoryComboBox);
    searchLayout->addWidget(new QLabel("搜索:", this));
    searchLayout->addWidget(searchLineEdit);
    searchLayout->addWidget(ui->Search_Product);
    searchLayout->addStretch(); // 让搜索区域控件靠左排列，右侧填充空白

    // 初始化表格模型
    productModel = new QStandardItemModel(0, 7, this);
    productModel->setHorizontalHeaderLabels({"ID", "商品名称", "条码", "价格", "库存", "补货点", "分类"});

    // 表格视图设置
    ui->productTableView->setModel(productModel);
    ui->productTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->productTableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->productTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->productTableView->setSortingEnabled(true);

    // 优化表格列宽显示 - 确保内容完全显示
    QHeaderView *header = ui->productTableView->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Interactive); // 允许手动调整列宽
    header->setSectionResizeMode(0, QHeaderView::ResizeToContents); // ID列自适应
    header->setSectionResizeMode(1, QHeaderView::Stretch);         // 商品名称列拉伸填充
    header->setSectionResizeMode(2, QHeaderView::ResizeToContents); // 条码列自适应
    header->setSectionResizeMode(3, QHeaderView::ResizeToContents); // 价格列自适应
    header->setSectionResizeMode(4, QHeaderView::ResizeToContents); // 库存列自适应
    header->setSectionResizeMode(5, QHeaderView::ResizeToContents); // 补货点列自适应
    header->setSectionResizeMode(6, QHeaderView::ResizeToContents); // 分类列自适应
    
    // 设置默认列宽，确保内容显示完整
    header->setDefaultSectionSize(100);
    ui->productTableView->setColumnWidth(1, 150); // 商品名称列宽设置更大
    
    ui->productTableView->setAlternatingRowColors(true);

    // 设置表格的拉伸策略
    ui->productTableView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // 将搜索区域和表格添加到主布局
    mainLayout->addLayout(searchLayout);
    mainLayout->addWidget(ui->productTableView, 1); // 表格占据主要空间

    // 状态栏设置
    QLabel* adminLabel = new QLabel(QString("当前操作员：%1").arg(name), this);
    adminLabel->setMargin(5);
    // 设置文本颜色以确保可见性，使用更具体的样式
    adminLabel->setStyleSheet("QLabel { color: black; }");

    QLabel* dateLabel = new QLabel(this);
    QDate currentDate = QDate::currentDate();
    const QStringList weekDays = {"", "一", "二", "三", "四", "五", "六", "日"};
    int weekNum = qBound(1, currentDate.dayOfWeek(), 7); // 防止数组越界
    QString weekStr = weekDays[weekNum];

    QString dateText = QString("当前日期：%1 星期%2")
                           .arg(currentDate.toString("yyyy-MM-dd"))
                           .arg(weekStr);
    dateLabel->setText(dateText);
    dateLabel->setMargin(5);
    // 设置文本颜色以确保可见性，使用更具体的样式
    dateLabel->setStyleSheet("QLabel { color: black; }");

    // 添加库存统计信息（初始值为0，后续在loadProducts中更新）
    QLabel* inventoryStats = new QLabel("商品总数: 0 | 低库存商品: 0", this);
    inventoryStats->setMargin(5);
    // 设置文本颜色以确保可见性，使用更具体的样式
    inventoryStats->setStyleSheet("QLabel { color: black; }");

    statusBar()->addWidget(adminLabel);
    statusBar()->addWidget(inventoryStats);
    statusBar()->addPermanentWidget(dateLabel);
}

// 连接信号与槽（关联Action和控件事件）
void Product::setupConnections()
{
    // 工具栏中的Action（UI中Action对象名需与以下一致）
    connect(ui->Add_Product, &QAction::triggered, this, &Product::onAddProductClicked);
    connect(ui->Delete_Product, &QAction::triggered, this, &Product::onDeleteProductClicked);
    connect(ui->Put_Product, &QAction::triggered, this, &Product::onPutProductClicked);
    connect(ui->Out_Product, &QAction::triggered, this, &Product::onTakeProductClicked);
    connect(ui->Modify_Reorder_Point, &QAction::triggered, this, &Product::onModifyReorderPointClicked);  // 新增修改补货点
    connect(ui->Inventory_Report, &QAction::triggered, this, &Product::onGenerateInventoryReport);  // 新增库存报告
    connect(ui->importAction, &QAction::triggered, this, &Product::onImportDataClicked);
    connect(ui->exportAction, &QAction::triggered, this, &Product::onExportDataClicked);

    // 外部搜索按钮（非Action，UI中按钮对象名为Search_Product）
    connect(ui->Search_Product, &QPushButton::clicked, this, &Product::onSearchProductClicked);
    // 文本框回车触发搜索
    connect(searchLineEdit, &QLineEdit::returnPressed, this, &Product::onSearchProductClicked);

    connect(ui->backToLogin, &QAction::triggered, this, &Product::onBackToLoginTriggered);

    // 新增：连接查看销售统计的Action
    connect(ui->Sale_Action, &QAction::triggered, this, &Product::onViewSalesStatisticsClicked);

    // 新增：连接显示库存图表的Action
    connect(ui->Show_Chart_Action, &QAction::triggered, this, &Product::onShowInventoryChartsClicked);

    // 新增：创建并连接报表统计Action
    // 创建一个新的Action用于报表统计
    QAction* reportStatsAction = new QAction("报表统计", this);
    reportStatsAction->setStatusTip("生成报表统计信息");
    connect(reportStatsAction, &QAction::triggered, this, &Product::onGenerateReportStatistics);

    // 尝试添加到工具栏，如果存在的话
    // 遍历现有的工具栏并添加到其中一个
    QList<QToolBar*> toolBars = findChildren<QToolBar*>();
    if (!toolBars.isEmpty()) {
        toolBars.first()->addAction(reportStatsAction);
    }
}

// 加载商品数据
void Product::loadProducts()
{
    productModel->removeRows(0, productModel->rowCount());

    // 设置模型使用数值排序
    productModel->setSortRole(Qt::UserRole + 1); // 使用自定义排序角色

    // 从数据库获取所有商品
    QList<QMap<QString, QVariant>> products = dbManager->getAllProducts();

    QList<QMap<QString, QVariant>> lowStockProducts; // 存储库存不足的商品

    for (const auto& product : products) {
        int id = product["id"].toInt();
        QString name = product["name"].toString();
        QString barcode = product["barcode"].toString();
        double price = product["price"].toDouble();
        int stock = product["stock"].toInt();
        QString category = product["category"].toString();

        QList<QStandardItem*> items;

        // ID 列 - 数值
        QStandardItem* idItem = new QStandardItem();
        idItem->setData(id, Qt::DisplayRole);         // 显示值
        idItem->setData(id, Qt::UserRole + 1);        // 排序值
        items.append(idItem);

        // 商品名称 - 字符串
        items.append(new QStandardItem(name));

        // 条码 - 字符串
        items.append(new QStandardItem(barcode));

        // 价格列 - 数值
        QStandardItem* priceItem = new QStandardItem();
        priceItem->setData(QString::number(price, 'f', 2), Qt::DisplayRole); // 显示格式化文本
        priceItem->setData(price, Qt::UserRole + 1);  // 排序值
        priceItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter); // 右对齐
        items.append(priceItem);

        // 库存列 - 数值
        QStandardItem* stockItem = new QStandardItem();
        stockItem->setData(stock, Qt::DisplayRole);   // 显示值
        stockItem->setData(stock, Qt::UserRole + 1);  // 排序值
        stockItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter); // 右对齐

        // 库存不足时标红（低于补货点）
        int reorderPoint = product["reorder_point"].toInt();
        if (stock < reorderPoint) {
            stockItem->setForeground(Qt::red);
            lowStockProducts.append(product); // 添加到库存不足的商品列表
        }
        items.append(stockItem);

        // 补货点列 - 数值
        QStandardItem* reorderItem = new QStandardItem();
        reorderItem->setData(reorderPoint, Qt::DisplayRole);   // 显示值
        reorderItem->setData(reorderPoint, Qt::UserRole + 1);  // 排序值
        reorderItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter); // 右对齐
        items.append(reorderItem);

        // 分类 - 字符串
        items.append(new QStandardItem(category));

        // 设置单元格不可编辑
        foreach (QStandardItem* item, items) {
            item->setEditable(false);
        }

        productModel->appendRow(items);
    }

    updateCategoryComboBox();

    // 关键修改：使用QTimer延迟提示框，确保页面先显示
    // 0毫秒延迟表示"当前事件循环结束后执行"，此时页面已完成绘制
    QTimer::singleShot(0, this, [this, lowStockProducts]() {
        showLowStockProducts(lowStockProducts);
    });

    // 更新状态栏统计信息
    updateStatusBarStats();
}

// 更新状态栏统计信息
void Product::updateStatusBarStats()
{
    // 查找状态栏中的库存统计标签
    QList<QLabel*> labels = statusBar()->findChildren<QLabel*>();
    QLabel* inventoryStats = nullptr;
    for (QLabel* label : labels) {
        if (label->text().contains("商品总数") || label->text().contains("低库存商品")) {
            inventoryStats = label;
            break;
        }
    }

    if (inventoryStats) {
        int totalProducts = productModel->rowCount();
        int lowStockCount = 0;
        for (int i = 0; i < productModel->rowCount(); ++i) {
            int stock = productModel->item(i, 4)->text().toInt();  // 库存列
            int reorderPoint = productModel->item(i, 5)->text().toInt();  // 补货点列
            if (stock < reorderPoint) {
                lowStockCount++;
            }
        }
        inventoryStats->setText(QString("商品总数: %1 | 低库存商品: %2").arg(totalProducts).arg(lowStockCount));
    }
}

// 更新分类下拉框
void Product::updateCategoryComboBox()
{
    QString currentCategory = categoryComboBox->currentText();
    categoryComboBox->clear();
    categoryComboBox->addItem("全部");

    QSet<QString> categories;
    for (int i = 0; i < productModel->rowCount(); ++i) {
        categories.insert(productModel->item(i, 6)->text());
    }

    categoryComboBox->addItems(categories.values());

    // 恢复之前的选择
    int index = categoryComboBox->findText(currentCategory);
    if (index != -1) {
        categoryComboBox->setCurrentIndex(index);
    }
}

// 添加商品
void Product::onAddProductClicked()
{
    AddProductDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString name = dialog.getName();
        QString barcode = dialog.getBarcode();
        double price = dialog.getPrice();
        int stock = dialog.getStock();
        int reorderPoint = dialog.getReorderPoint();
        QString category = dialog.getCategory();

        if (dbManager->addProduct(name, barcode, price, stock, category, reorderPoint)) {
            QMessageBox::information(this, "成功", "商品添加成功！");
            loadProducts();
        } else {
            QMessageBox::critical(this, "失败", "商品添加失败！可能是条码已存在。");
        }
    }
}

// 删除商品
void Product::onDeleteProductClicked()
{
    QModelIndexList selectedRows = ui->productTableView->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "警告", "请先选择要删除的商品！");
        return;
    }

    if (QMessageBox::question(this, "确认删除",
                              QString("确定要删除选中的 %1 个商品吗？").arg(selectedRows.size()),
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::No) {
        return;
    }

    // 按行号降序删除，避免索引错乱
    QList<int> rowsToDelete;
    foreach (const QModelIndex &index, selectedRows) {
        rowsToDelete.append(index.row());
    }
    std::sort(rowsToDelete.begin(), rowsToDelete.end(), std::greater<int>());

    // 执行删除
    foreach (int row, rowsToDelete) {
        int productId = productModel->item(row, 0)->text().toInt();
        if (dbManager->deleteProduct(productId)) {
            productModel->removeRow(row);
        } else {
            QMessageBox::critical(this, "失败", "删除商品失败！");
        }
    }

    updateCategoryComboBox();
}

// 商品入库
void Product::onPutProductClicked()
{
    // 获取表格中选中的行
    QModelIndexList selectedRows = ui->productTableView->selectionModel()->selectedRows();

    // 校验选中状态
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "警告", "请先选择要入库的商品！");
        return;
    }
    if (selectedRows.size() > 1) {
        QMessageBox::warning(this, "警告", "一次只能对一个商品进行入库操作！");
        return;
    }

    // 获取选中商品的信息（从表格中提取）
    QModelIndex index = selectedRows.first(); // 获取第一行选中项
    int row = index.row();                    // 选中行的行号

    // 从表格模型中提取商品ID、名称、当前库存
    int productId = productModel->item(row, 0)->text().toInt();       // ID在第0列
    QString productName = productModel->item(row, 1)->text();          // 名称在第1列
    int currentStock = productModel->item(row, 4)->text().toInt();     // 库存在第4列

    StockDialog dialog(StockOperation::In, productName, currentStock, this);
    if (dialog.exec() == QDialog::Accepted) {
        int amount = dialog.getChangeAmount();
        // 修正：调用正确的函数名
        if (dbManager->updateProductStock(productId, amount)) {
            QMessageBox::information(this, "成功", "商品入库成功！");
            loadProducts();
        } else {
            QMessageBox::critical(this, "失败", "商品入库失败！");
        }
    }
}

// 商品出库
void Product::onTakeProductClicked()
{
    QModelIndexList selectedRows = ui->productTableView->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "警告", "请先选择要出库的商品！");
        return;
    }
    if (selectedRows.size() > 1) {
        QMessageBox::warning(this, "警告", "一次只能对一个商品进行出库操作！");
        return;
    }

    QModelIndex index = selectedRows.first();
    int row = index.row();
    int productId = productModel->item(row, 0)->text().toInt();
    QString productName = productModel->item(row, 1)->text();
    int currentStock = productModel->item(row, 4)->text().toInt();

    StockDialog dialog(StockOperation::Out, productName, currentStock, this);
    if (dialog.exec() == QDialog::Accepted) {
        int amount = dialog.getChangeAmount();
        if (dbManager->updateProductStock(productId, -amount)) {
            QMessageBox::information(this, "成功", "商品出库成功！");
            loadProducts();
        } else {
            QMessageBox::critical(this, "失败", "商品出库失败！");
        }
    }
}

// 修改补货点
void Product::onModifyReorderPointClicked()
{
    QModelIndexList selectedRows = ui->productTableView->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "警告", "请先选择要修改补货点的商品！");
        return;
    }
    if (selectedRows.size() > 1) {
        QMessageBox::warning(this, "警告", "一次只能对一个商品进行补货点修改操作！");
        return;
    }

    QModelIndex index = selectedRows.first();
    int row = index.row();
    int productId = productModel->item(row, 0)->text().toInt();
    QString productName = productModel->item(row, 1)->text();
    int currentStock = productModel->item(row, 4)->text().toInt();
    int currentReorderPoint = productModel->item(row, 5)->text().toInt();  // 补货点在第5列

    StockDialog dialog(productName, currentStock, currentReorderPoint, this);
    if (dialog.exec() == QDialog::Accepted) {
        int newReorderPoint = dialog.getReorderPointChange();
        if (dbManager->updateProductReorderPoint(productId, newReorderPoint)) {
            QMessageBox::information(this, "成功", "商品补货点修改成功！");
            loadProducts();
        } else {
            QMessageBox::critical(this, "失败", "商品补货点修改失败！");
        }
    }
}

// 生成库存报告
void Product::onGenerateInventoryReport()
{
    QList<QMap<QString, QVariant>> products = dbManager->getAllProducts();

    if (products.isEmpty()) {
        QMessageBox::information(this, "提示", "当前没有商品数据，无法生成报告！");
        return;
    }

    QString report = "库存报告\n";
    report += QString("生成时间: %1\n\n").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
    report += "商品ID\t商品名称\t\t\t条码\t\t\t价格\t\t库存\t补货点\t分类\n";
    report += QString("=").repeated(120) + "\n";

    int totalValue = 0;  // 总库存价值
    int lowStockCount = 0;  // 低库存商品数量
    int totalStock = 0;  // 总库存数量

    for (const auto& product : products) {
        int id = product["id"].toInt();
        QString name = product["name"].toString();
        QString barcode = product["barcode"].toString();
        double price = product["price"].toDouble();
        int stock = product["stock"].toInt();
        int reorderPoint = product["reorder_point"].toInt();
        QString category = product["category"].toString();

        report += QString("%1\t%2\t\t%3\t\t%4\t%5\t%6\t%7\n")
                      .arg(id)
                      .arg(name.left(15).leftJustified(15, ' '))  // 限制名称长度并右对齐
                      .arg(barcode.leftJustified(15, ' '))
                      .arg(QString::number(price, 'f', 2).leftJustified(8, ' '))
                      .arg(QString::number(stock).leftJustified(6, ' '))
                      .arg(QString::number(reorderPoint).leftJustified(6, ' '))
                      .arg(category);

        // 统计信息
        totalValue += static_cast<int>(price * stock);
        totalStock += stock;
        if (stock < reorderPoint) {
            lowStockCount++;
        }
    }

    report += QString("\n" + QString("=").repeated(120) + "\n");
    report += QString("统计信息:\n");
    report += QString("总商品种类: %1\n").arg(products.size());
    report += QString("总库存数量: %1\n").arg(totalStock);
    report += QString("总库存价值: %1元\n").arg(totalValue);
    report += QString("低库存商品: %1种\n").arg(lowStockCount);

    // 显示报告
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("库存报告");
    dialog->setMinimumSize(800, 600);

    QVBoxLayout *layout = new QVBoxLayout(dialog);

    QTextEdit *textEdit = new QTextEdit(dialog);
    textEdit->setPlainText(report);
    textEdit->setReadOnly(true);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *exportBtn = new QPushButton("导出报告", dialog);
    QPushButton *closeBtn = new QPushButton("关闭", dialog);

    buttonLayout->addStretch();
    buttonLayout->addWidget(exportBtn);
    buttonLayout->addWidget(closeBtn);

    layout->addWidget(textEdit);
    layout->addLayout(buttonLayout);

    connect(exportBtn, &QPushButton::clicked, this, [this, report]() {
        QString filePath = QFileDialog::getSaveFileName(this, "导出库存报告", "", "文本文件 (*.txt);;所有文件 (*)");
        if (!filePath.isEmpty()) {
            QFile file(filePath);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                out << report;
                file.close();
                QMessageBox::information(this, "成功", "库存报告已导出成功！");
            } else {
                QMessageBox::critical(this, "错误", "无法保存文件！");
            }
        }
    });

    connect(closeBtn, &QPushButton::clicked, dialog, &QDialog::accept);

    dialog->setLayout(layout);
    dialog->exec();
    dialog->deleteLater();
}

// 新增生成报表统计功能
void Product::onGenerateReportStatistics()
{
    QList<QMap<QString, QVariant>> products = dbManager->getAllProducts();

    if (products.isEmpty()) {
        QMessageBox::information(this, "提示", "当前没有商品数据，无法生成报表统计！");
        return;
    }

    QString report = "报表统计\n";
    report += QString("生成时间: %1\n\n").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

    // 统计信息
    int totalProducts = products.size();
    int totalStock = 0;
    int totalValue = 0;
    int lowStockCount = 0;
    int outOfStockCount = 0;
    double avgPrice = 0.0;

    // 按分类统计
    QMap<QString, int> categoryCount;
    QMap<QString, int> categoryStock;

    for (const auto& product : products) {
        QString name = product["name"].toString();
        QString category = product["category"].toString();
        double price = product["price"].toDouble();
        int stock = product["stock"].toInt();
        int reorderPoint = product["reorder_point"].toInt();

        totalStock += stock;
        totalValue += static_cast<int>(price * stock);

        if (stock == 0) {
            outOfStockCount++;
        } else if (stock < reorderPoint) {
            lowStockCount++;
        }

        // 分类统计
        categoryCount[category]++;
        categoryStock[category] += stock;

        avgPrice += price;
    }

    if (totalProducts > 0) {
        avgPrice /= totalProducts;
    }

    // 生成详细报告
    report += "=== 总体统计 ===\n";
    report += QString("总商品种类: %1\n").arg(totalProducts);
    report += QString("总库存数量: %1\n").arg(totalStock);
    report += QString("总库存价值: %1元\n").arg(totalValue);
    report += QString("平均商品价格: %1元\n").arg(QString::number(avgPrice, 'f', 2));
    report += QString("缺货商品: %1种\n").arg(outOfStockCount);
    report += QString("低库存商品: %1种\n").arg(lowStockCount);
    report += QString("库存充足商品: %1种\n\n").arg(totalProducts - lowStockCount - outOfStockCount);

    report += "=== 分类统计 ===\n";
    for (auto it = categoryCount.begin(); it != categoryCount.end(); ++it) {
        QString category = it.key();
        int count = it.value();
        int stock = categoryStock[category];
        report += QString("%1: %2种商品, 总库存%3\n").arg(category).arg(count).arg(stock);
    }

    // 显示报表统计
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle("报表统计");
    dialog->setMinimumSize(800, 600);

    QVBoxLayout *layout = new QVBoxLayout(dialog);

    QTextEdit *textEdit = new QTextEdit(dialog);
    textEdit->setPlainText(report);
    textEdit->setReadOnly(true);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *exportBtn = new QPushButton("导出报表", dialog);
    QPushButton *closeBtn = new QPushButton("关闭", dialog);

    buttonLayout->addStretch();
    buttonLayout->addWidget(exportBtn);
    buttonLayout->addWidget(closeBtn);

    layout->addWidget(textEdit);
    layout->addLayout(buttonLayout);

    connect(exportBtn, &QPushButton::clicked, this, [this, report]() {
        QString filePath = QFileDialog::getSaveFileName(this, "导出报表统计", "", "文本文件 (*.txt);;所有文件 (*)");
        if (!filePath.isEmpty()) {
            QFile file(filePath);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                out << report;
                file.close();
                QMessageBox::information(this, "成功", "报表统计已导出成功！");
            } else {
                QMessageBox::critical(this, "错误", "无法保存文件！");
            }
        }
    });

    connect(closeBtn, &QPushButton::clicked, dialog, &QDialog::accept);

    dialog->setLayout(layout);
    dialog->exec();
    dialog->deleteLater();
}

// 在 Product.cpp 中实现数据导出函数
void Product::onExportDataClicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "导出商品数据", "", "CSV文件 (*.csv);;所有文件 (*)");
    if (filePath.isEmpty()) return;

    if (exportDataToCSV(filePath)) {
        QMessageBox::information(this, "导出成功", "商品数据已成功导出");
    } else {
        QMessageBox::critical(this, "导出失败", "商品数据导出失败");
    }
}

bool Product::exportDataToCSV(const QString& filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream out(&file);
    // 写入表头
    for (int i = 0; i < productModel->columnCount(); ++i) {
        out << productModel->headerData(i, Qt::Horizontal).toString();
        if (i < productModel->columnCount() - 1) {
            out << ",";
        }
    }
    out << "\n";

    // 写入数据
    for (int row = 0; row < productModel->rowCount(); ++row) {
        for (int col = 0; col < productModel->columnCount(); ++col) {
            QStandardItem* item = productModel->item(row, col);
            if (item) {
                out << item->text();
            }
            if (col < productModel->columnCount() - 1) {
                out << ",";
            }
        }
        out << "\n";
    }

    file.close();
    return true;
}

// 在 Product.cpp 中实现数据导入函数
void Product::onImportDataClicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "导入商品数据", "", "CSV文件 (*.csv);;所有文件 (*)");
    if (filePath.isEmpty()) return;

    if (importDataFromCSV(filePath)) {
        QMessageBox::information(this, "导入成功", "商品数据已成功导入");
        loadProducts(); // 重新加载商品数据
    } else {
        QMessageBox::critical(this, "导入失败", "商品数据导入失败");
    }
}

// Product.cpp
bool Product::importDataFromCSV(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false; // 文件打开失败
    }

    QTextStream in(&file);
    in.readLine(); // 跳过CSV表头（假设表头是：ID,商品名称,条码,价格,库存,分类）

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(","); // 按逗号分割CSV字段
        if (fields.size() != 6) continue; // 字段数量不对则跳过

        // 解析CSV字段（注意索引对应表头顺序）
        QString prodName = fields[1];      // 商品名称（关键匹配项）
        QString barcode = fields[2];       // 条码
        double price = fields[3].toDouble();// 价格
        int importStock = fields[4].toInt();// 导入的库存数量（需要合并的值）
        QString category = fields[5];      // 分类

        // 核心逻辑：检查数据库中是否存在同名商品
        QMap<QString, QVariant> existingProd = dbManager->getProductByName(prodName);
        if (!existingProd.isEmpty()) {
            // 存在同名商品：更新库存（原库存 + 导入库存）
            int existingId = existingProd["id"].toInt(); // 已有商品的ID
            // 调用updateProductStock更新库存（第二个参数是库存变化量，此处为导入的数量）
            if (!dbManager->updateProductStock(existingId, importStock)) {
                file.close();
                return false; // 更新失败则整体导入失败
            }
        } else {
            // 不存在同名商品：直接新增
            if (!dbManager->addProduct(prodName, barcode, price, importStock, category)) {
                file.close();
                return false; // 新增失败则整体导入失败
            }
        }
    }

    file.close();
    return true;
}

// 搜索商品
void Product::onSearchProductClicked()
{
    QString keyword = searchLineEdit->text().trimmed();
    QString category = categoryComboBox->currentText();

    productModel->removeRows(0, productModel->rowCount());

    QList<QMap<QString, QVariant>> products;
    if (category == "全部") {
        products = dbManager->searchProducts(keyword);
    } else {
        QList<QMap<QString, QVariant>> allProducts = dbManager->searchProducts(keyword);
        for (const auto& product : allProducts) {
            if (product["category"].toString() == category) {
                products.append(product);
            }
        }
    }

    for (const auto& product : products) {
        int id = product["id"].toInt();
        QString name = product["name"].toString();
        QString barcode = product["barcode"].toString();
        double price = product["price"].toDouble();
        int stock = product["stock"].toInt();
        QString category = product["category"].toString();

        QList<QStandardItem*> items;

        // ID 列 - 数值
        QStandardItem* idItem = new QStandardItem();
        idItem->setData(id, Qt::DisplayRole);         // 显示值
        idItem->setData(id, Qt::UserRole + 1);        // 排序值
        items.append(idItem);

        // 商品名称 - 字符串
        items.append(new QStandardItem(name));

        // 条码 - 字符串
        items.append(new QStandardItem(barcode));

        // 价格列 - 数值
        QStandardItem* priceItem = new QStandardItem();
        priceItem->setData(QString::number(price, 'f', 2), Qt::DisplayRole); // 显示格式化文本
        priceItem->setData(price, Qt::UserRole + 1);  // 排序值
        priceItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter); // 右对齐
        items.append(priceItem);

        // 库存列 - 数值
        QStandardItem* stockItem = new QStandardItem();
        stockItem->setData(stock, Qt::DisplayRole);   // 显示值
        stockItem->setData(stock, Qt::UserRole + 1);  // 排序值
        stockItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter); // 右对齐

        // 库存不足时标红（低于补货点）
        int reorderPoint = product["reorder_point"].toInt();
        if (stock < reorderPoint) {
            stockItem->setForeground(Qt::red);
        }
        items.append(stockItem);

        // 补货点列 - 数值
        QStandardItem* reorderItem = new QStandardItem();
        reorderItem->setData(reorderPoint, Qt::DisplayRole);   // 显示值
        reorderItem->setData(reorderPoint, Qt::UserRole + 1);  // 排序值
        reorderItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter); // 右对齐
        items.append(reorderItem);

        // 分类 - 字符串
        items.append(new QStandardItem(category));

        // 设置单元格不可编辑
        foreach (QStandardItem* item, items) {
            item->setEditable(false);
        }

        productModel->appendRow(items);
    }

    // 更新状态栏统计信息
    updateStatusBarStats();
}

// 返回登录界面
void Product::onBackToLoginTriggered()
{
    emit backToLogin();
}

// 显示库存图表
void Product::showInventoryCharts()
{
    // 创建一个对话框来显示图表
    QDialog *chartDialog = new QDialog(this);
    chartDialog->setWindowTitle("库存统计图表");
    chartDialog->resize(1200, 800);

    // 创建主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(chartDialog);

    // 创建选项卡控件来显示不同的图表
    QTabWidget *tabWidget = new QTabWidget(chartDialog);

    // 创建库存水平图表
    createInventoryChart();
    if (inventoryChart) {
        QChartView *inventoryChartView = new QChartView(inventoryChart, chartDialog);
        inventoryChartView->setRenderHint(QPainter::Antialiasing);
        tabWidget->addTab(inventoryChartView, "库存水平");
    }

    // 创建库存预警图表
    createWarningChart();
    if (warningChart) {
        QChartView *warningChartView = new QChartView(warningChart, chartDialog);
        warningChartView->setRenderHint(QPainter::Antialiasing);
        tabWidget->addTab(warningChartView, "库存预警");
    }

    // 创建畅销商品图表
    createBestSellingChart();
    if (bestSellingChart) {
        QChartView *bestSellingChartView = new QChartView(bestSellingChart, chartDialog);
        bestSellingChartView->setRenderHint(QPainter::Antialiasing);
        tabWidget->addTab(bestSellingChartView, "畅销商品");
    }

    // 添加选项卡到主布局
    mainLayout->addWidget(tabWidget);

    // 添加关闭按钮
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    QPushButton *closeButton = new QPushButton("关闭", chartDialog);
    buttonLayout->addWidget(closeButton);
    mainLayout->addLayout(buttonLayout);

    // 连接关闭按钮
    connect(closeButton, &QPushButton::clicked, chartDialog, &QDialog::close);

    // 显示对话框
    chartDialog->setLayout(mainLayout);
    chartDialog->exec();
    chartDialog->deleteLater();
}

// 创建库存水平图表
void Product::createInventoryChart()
{
    // 获取所有商品数据
    QList<QMap<QString, QVariant>> products = dbManager->getAllProducts();

    // 创建柱状序列
    QBarSeries *series = new QBarSeries();

    // 创建数据点
    QBarSet *stockSet = new QBarSet("当前库存");
    QBarSet *reorderSet = new QBarSet("补货点");

    // 限制显示的商品数量以避免图表过于拥挤
    int count = 0;
    const int MAX_ITEMS = 10; // 最多显示10个商品

    for (const auto& product : products) {
        if (count >= MAX_ITEMS) break;

        QString name = product["name"].toString();
        int stock = product["stock"].toInt();
        int reorderPoint = product["reorder_point"].toInt();

        *stockSet << stock;
        *reorderSet << reorderPoint;

        count++;
    }

    series->append(stockSet);
    series->append(reorderSet);

    // 创建图表
    inventoryChart = new QChart();
    inventoryChart->addSeries(series);
    inventoryChart->setTitle("库存水平对比图");
    inventoryChart->setAnimationOptions(QChart::SeriesAnimations);

    // 创建并设置坐标轴
    QStringList categories;
    int maxStock = 0;
    count = 0;
    for (const auto& product : products) {
        if (count >= MAX_ITEMS) break;
        categories << product["name"].toString().left(8); // 只显示前8个字符避免标签过长

        // 记录最大库存值用于设置Y轴范围
        int stock = product["stock"].toInt();
        int reorderPoint = product["reorder_point"].toInt();
        int maxValue = std::max(stock, reorderPoint);
        if (maxValue > maxStock) maxStock = maxValue;

        count++;
    }

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    inventoryChart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0, maxStock > 0 ? maxStock * 1.1 : 100); // 根据实际数据调整范围，增加10%余量
    inventoryChart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    inventoryChart->legend()->setVisible(true);
    inventoryChart->legend()->setAlignment(Qt::AlignBottom);
}

// 创建库存预警图表
void Product::createWarningChart()
{
    // 获取库存不足的商品
    QList<QMap<QString, QVariant>> products = dbManager->getAllProducts();

    QPieSeries *series = new QPieSeries();
    int lowStockCount = 0;
    int normalStockCount = 0;

    for (const auto& product : products) {
        int stock = product["stock"].toInt();
        int reorderPoint = product["reorder_point"].toInt();

        if (stock < reorderPoint) {
            lowStockCount++;
        } else {
            normalStockCount++;
        }
    }

    // 添加数据到饼图
    if (lowStockCount > 0) {
        series->append("库存不足", lowStockCount);
    }
    if (normalStockCount > 0) {
        series->append("库存正常", normalStockCount);
    }

    // 设置饼图切片颜色
    if (series->count() > 0) {
        QPieSlice *lowStockSlice = series->slices().first();
        if (lowStockCount > 0) {
            lowStockSlice->setColor(Qt::red);
            lowStockSlice->setLabel("库存不足");
        }
    }
    if (series->count() > 1) {
        QPieSlice *normalStockSlice = series->slices().at(1);
        normalStockSlice->setColor(Qt::green);
        normalStockSlice->setLabel("库存正常");
    }

    // 创建图表
    warningChart = new QChart();
    warningChart->addSeries(series);
    warningChart->setTitle("库存预警状态");
    warningChart->setAnimationOptions(QChart::AllAnimations);
    warningChart->legend()->setVisible(true);
    warningChart->legend()->setAlignment(Qt::AlignRight);
}

// 创建畅销商品图表
void Product::createBestSellingChart()
{
    // 由于当前系统可能没有销售记录表，我们基于商品的库存周转率来估算畅销程度
    // 这里使用一个更合理的模拟方法，考虑商品的初始库存和当前库存
    QList<QMap<QString, QVariant>> products = dbManager->getAllProducts();

    std::vector<std::pair<QString, int>> salesEstimateList;
    for (const auto& product : products) {
        QString name = product["name"].toString();
        int stock = product["stock"].toInt();
        int reorderPoint = product["reorder_point"].toInt();

        // 估算销售热度：库存越接近补货点，可能越不畅销；库存远低于补货点，可能越畅销
        // 这里使用一个简单的算法：(补货点 - 当前库存) 作为销售热度指标
        int salesEstimate = reorderPoint - stock;
        if (salesEstimate < 0) salesEstimate = 0; // 确保不为负数

        salesEstimateList.push_back(std::make_pair(name, salesEstimate));
    }

    // 按销售热度排序
    std::sort(salesEstimateList.begin(), salesEstimateList.end(),
              [](const std::pair<QString, int>& a, const std::pair<QString, int>& b) {
                  return a.second > b.second;
              });

    // 创建柱状序列
    QBarSeries *series = new QBarSeries();
    QBarSet *bestSellingSet = new QBarSet("销售热度");

    // 只显示前10个商品
    int count = 0;
    const int MAX_ITEMS = 10;
    QStringList categories;

    for (const auto& item : salesEstimateList) {
        if (count >= MAX_ITEMS) break;

        *bestSellingSet << item.second;
        categories << item.first.left(8); // 只显示前8个字符
        count++;
    }

    series->append(bestSellingSet);

    // 创建图表
    bestSellingChart = new QChart();
    bestSellingChart->addSeries(series);
    bestSellingChart->setTitle("畅销商品排行榜");
    bestSellingChart->setAnimationOptions(QChart::SeriesAnimations);

    // 设置坐标轴
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    bestSellingChart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("销售热度");
    bestSellingChart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    bestSellingChart->legend()->setVisible(false);
}

// 查看销售统计
void Product::onViewSalesStatisticsClicked()
{
    SalesStatisticsDialog dialog(this);
    dialog.exec();
}

// 显示库存图表槽函数
void Product::onShowInventoryChartsClicked()
{
    showInventoryCharts();
}

// 显示库存不足的商品提示框
void Product::showLowStockProducts(const QList<QMap<QString, QVariant>>& lowStockProducts)
{
    if (!lowStockProducts.isEmpty()) {
        QString message = "以下商品库存低于补货点：\n";
        for (const auto& product : lowStockProducts) {
            int stock = product["stock"].toInt();
            int reorderPoint = product["reorder_point"].toInt();
            message += QString("ID: %1, 名称: %2, 库存: %3, 补货点: %4\n")
                           .arg(product["id"].toString())
                           .arg(product["name"].toString())
                           .arg(stock)
                           .arg(reorderPoint);
        }
        QMessageBox::warning(this, "库存不足警告", message);
    }
}
