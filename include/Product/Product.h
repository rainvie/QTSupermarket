#ifndef PRODUCT_H
#define PRODUCT_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QLineEdit>
#include <QComboBox>
#include <QList>
#include <QMap>

// 引入数据库接口
#include "LogIn/dbmanager.h"

// 引入图表功能
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

QT_BEGIN_NAMESPACE
namespace Ui { class Product; }
QT_END_NAMESPACE

class Product : public QMainWindow
{
    Q_OBJECT

public:
    explicit Product(QString name,QWidget *parent = nullptr);
    ~Product() override;

private slots:
    void onAddProductClicked();       // 对应addAction
    void onDeleteProductClicked();    // 对应deleteAction
    void onPutProductClicked();       // 对应putAction
    void onSearchProductClicked();    // 搜索按钮（非Action）
    void onImportDataClicked();       // 对应importAction
    void onExportDataClicked();       // 对应exportAction
    void onTakeProductClicked();
    void onBackToLoginTriggered();
    void onViewSalesStatisticsClicked();
    void onModifyReorderPointClicked();  // 新增修改补货点
    void onGenerateInventoryReport();    // 新增生成库存报告
    void onShowInventoryChartsClicked(); // 新增显示库存图表
    void onGenerateReportStatistics();    // 新增生成报表统计

signals:
    void backToLogin();

private:
    Ui::Product *ui;                  // UI Designer生成的界面对象
    DBManager *dbManager;             // 数据库管理器（单例）
    QStandardItemModel *productModel; // 表格数据模型

    // 关联UI控件（保持原有名称）
    QLineEdit *searchLineEdit;        // 搜索文本框（外部）
    QComboBox *categoryComboBox;      // 分类组合框（外部）

    // 图表相关成员变量
    QChart *inventoryChart;           // 库存图表
    QChart *warningChart;             // 库存预警图表
    QChart *bestSellingChart;         // 畅销商品图表
    QChartView *chartView;            // 图表视图

    // 辅助函数
    void initUI();                    // 初始化UI关联
    void setupConnections();          // 连接信号与槽
    void loadProducts();              // 加载商品数据
    void updateCategoryComboBox();    // 更新分类下拉框
    void searchProducts(const QString &keyword, const QString &category); // 搜索商品
    void updateStatusBarStats();      // 更新状态栏统计信息

    QString name;

    void showLowStockProducts(const QList<QMap<QString, QVariant>>& lowStockProducts);      // 显示库存不足的商品提示框

    // 图表相关函数
    void showInventoryCharts();       // 显示库存图表
    void createInventoryChart();      // 创建库存水平图表
    void createWarningChart();        // 创建库存预警图表
    void createBestSellingChart();    // 创建畅销商品图表

    bool exportDataToCSV(const QString& filePath);
    bool importDataFromCSV(const QString& filePath);
};

#endif // PRODUCT_H
