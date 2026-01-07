// SalesStatisticsDialog.h
#ifndef SALESSTATISTICSDIALOG_H
#define SALESSTATISTICSDIALOG_H

#include <QDialog>
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QPushButton>
#include <QComboBox>
#include <QDateEdit>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class SalesStatisticsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SalesStatisticsDialog(QWidget *parent = nullptr);
    ~SalesStatisticsDialog() override;

private slots:
    void onRefreshClicked();
    void onExportClicked();
    void onAIAnalysisClicked();  // AI分析按钮点击槽函数
    void onAIReplyFinished(QNetworkReply* reply);  // AI API回复处理

private:
    QTableView *tableView;
    QStandardItemModel *salesModel;
//    QComboBox *periodCombo;
//    QDateEdit *startDateEdit;
//    QDateEdit *endDateEdit;

    QPushButton *aiAnalysisBtn;  // AI分析按钮
    QNetworkAccessManager *networkManager;  // 网络管理器
    QString apiKey;  // API密钥

    void loadSalesData();
    void setupUI();
    void performAIAnalysis();  // 执行AI分析
    void setAPIKey(const QString &key);  // 设置API密钥
};

#endif // SALESSTATISTICSDIALOG_H
