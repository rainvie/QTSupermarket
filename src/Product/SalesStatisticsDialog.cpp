#include "Product/SalesStatisticsDialog.h"
#include "LogIn/dbmanager.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
#include <QHeaderView>
#include <QMessageBox>
#include <QInputDialog>
#include <QTextEdit>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrl>

SalesStatisticsDialog::SalesStatisticsDialog(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("商品销量统计");
    setMinimumSize(900, 650);  // 增加最小窗口大小以确保按钮可见

    // 初始化成员变量
    apiKey = "9ced0c1f6db04aaab3de49bf33817915.jCBugszEYIAfLN6D";  // 初始化API密钥

    setupUI();
    loadSalesData();
}

SalesStatisticsDialog::~SalesStatisticsDialog()
{
}

void SalesStatisticsDialog::setupUI()
{
    // 创建模型和视图
    salesModel = new QStandardItemModel(0, 4, this);
    salesModel->setHorizontalHeaderLabels({"商品ID", "商品名称", "销量", "销售额"});

    tableView = new QTableView(this);
    tableView->setModel(salesModel);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    tableView->setSortingEnabled(true);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    tableView->verticalHeader()->setVisible(false);

    // 过滤控件
//    QGroupBox *filterGroup = new QGroupBox("统计时段", this);
//    QHBoxLayout *filterLayout = new QHBoxLayout(filterGroup);

//    periodCombo = new QComboBox(this);
//    periodCombo->addItem("当月", "month");
//    periodCombo->addItem("当季", "quarter");
//    periodCombo->addItem("当年", "year");
//    periodCombo->addItem("自定义", "custom");

//    startDateEdit = new QDateEdit(this);
//    startDateEdit->setDate(QDate::currentDate().addMonths(-1));
//    startDateEdit->setCalendarPopup(true);
//    startDateEdit->setDisplayFormat("yyyy-MM-dd");

//    endDateEdit = new QDateEdit(this);
//    endDateEdit->setDate(QDate::currentDate());
//    endDateEdit->setCalendarPopup(true);
//    endDateEdit->setDisplayFormat("yyyy-MM-dd");

//    QLabel *toLabel = new QLabel("至", this);

//    filterLayout->addWidget(new QLabel("时段:", this));
//    filterLayout->addWidget(periodCombo);
//    filterLayout->addSpacing(20);
//    filterLayout->addWidget(new QLabel("开始日期:", this));
//    filterLayout->addWidget(startDateEdit);
//    filterLayout->addWidget(toLabel);
//    filterLayout->addWidget(endDateEdit);
//    filterLayout->addStretch();

    // 按钮
    QPushButton *refreshBtn = new QPushButton("刷新", this);
    QPushButton *exportBtn = new QPushButton("导出CSV", this);
    aiAnalysisBtn = new QPushButton("🤖 AI分析", this);  // 添加表情符号使其更显眼
    aiAnalysisBtn->setStyleSheet("QPushButton {"
                                "    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF5722, stop: 1 #E64A19);"  // 渐变橙红色背景
                                "    border: 2px solid #B71C1C;"      // 红色边框
                                "    color: white;"                   // 白色文字
                                "    padding: 12px 24px;"             // 更大的內边距
                                "    text-align: center;"             // 文字居中
                                "    font-size: 18px;"               // 更大的字体
                                "    font-weight: bold;"              // 加粗字体
                                "    border-radius: 8px;"             // 更大的圆角
                                "    min-width: 120px;"               // 设置最小宽度
                                "    min-height: 45px;"               // 设置最小高度
                                "}"
                                "QPushButton:hover {"
                                "    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FF7043, stop: 1 #D84315);"  // 悬停时的渐变色
                                "}"
                                "QPushButton:pressed {"
                                "    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #E64A19, stop: 1 #BF360C);"  // 按下时的渐变色
                                "    border: 2px solid #8E0E00;"      // 按下时更深的边框
                                "    padding: 11px 23px;"             // 按下时稍微缩小内边距，产生按下效果
                                "}");
    aiAnalysisBtn->setMinimumSize(120, 50);  // 设置更大的最小尺寸以确保按钮显眼
    aiAnalysisBtn->setMaximumWidth(150);     // 限制最大宽度

    connect(refreshBtn, &QPushButton::clicked, this, &SalesStatisticsDialog::onRefreshClicked);
    connect(exportBtn, &QPushButton::clicked, this, &SalesStatisticsDialog::onExportClicked);
    connect(aiAnalysisBtn, &QPushButton::clicked, this, &SalesStatisticsDialog::onAIAnalysisClicked);

    // 初始化网络管理器
    networkManager = new QNetworkAccessManager(this);

    // 主布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
//    mainLayout->addWidget(filterGroup);
    mainLayout->addWidget(tableView);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(refreshBtn);
    buttonLayout->addWidget(exportBtn);
    buttonLayout->addWidget(aiAnalysisBtn);  // 将AI分析按钮放在导出按钮旁边
    buttonLayout->addStretch();  // 添加伸缩空间到末尾

    mainLayout->addLayout(buttonLayout);
}

void SalesStatisticsDialog::loadSalesData()
{
    salesModel->removeRows(0, salesModel->rowCount());

    QList<QMap<QString, QVariant>> salesData = DBManager::instance().getMonthlyProductSales();

    // 使用列表存储所有销售数据用于排序
    QList<QPair<int, double>> salesList; // <rowIndex, salesValue>

    // 添加以下两行声明总销量和总销售额变量
    double totalSales = 0.0;
    double totalRevenue = 0.0;

    // 第一部分：处理商品数据
    for (int i = 0; i < salesData.size(); ++i) {
        const auto& sale = salesData[i];
        int id = sale["id"].toInt();
        QString name = sale["name"].toString();
        int quantity = sale["total_sales"].toInt();
        double revenue = quantity * DBManager::instance().getProductById(id)["price"].toDouble();

        // 累加总销量和总销售额
        totalSales += quantity;
        totalRevenue += revenue;

        QList<QStandardItem*> items;

        // 商品ID - 存储为数值
        QStandardItem* idItem = new QStandardItem();
        idItem->setData(id, Qt::DisplayRole);
        items.append(idItem);

        // 商品名称 - 字符串
        items.append(new QStandardItem(name));

        // 销量 - 存储为数值
        QStandardItem* quantityItem = new QStandardItem();
        quantityItem->setData(quantity, Qt::DisplayRole);
        items.append(quantityItem);

        // 销售额 - 存储为数值
        QStandardItem* revenueItem = new QStandardItem();
        revenueItem->setData(revenue, Qt::DisplayRole);
        items.append(revenueItem);

        // 设置单元格属性
        foreach (QStandardItem* item, items) {
            item->setEditable(false);
            item->setTextAlignment(Qt::AlignCenter);
        }

        salesModel->appendRow(items);

        // 保存销量值用于后续高亮处理
        salesList.append(qMakePair(i, static_cast<double>(quantity)));
    }

    // 按销量排序（降序）
    std::sort(salesList.begin(), salesList.end(),
        [](const QPair<int, double>& a, const QPair<int, double>& b) {
            return a.second > b.second;
        });
    // 高亮销量前三的商品
    for (int rank = 0; rank < qMin(3, salesList.size()); ++rank) {
        int row = salesList[rank].first;
        for (int col = 0; col < salesModel->columnCount(); ++col) {
            QStandardItem* item = salesModel->item(row, col);
            item->setBackground(QColor(255, 255, 200)); // 浅黄色背景
        }
    }

    // 第二部分：添加汇总行（数值存储）
    QList<QStandardItem*> totalItems;

    // 第一列：文本
    QStandardItem* totalLabel = new QStandardItem("汇总");
    totalLabel->setEditable(false);
    totalLabel->setTextAlignment(Qt::AlignCenter);
    totalLabel->setBackground(QColor(230, 230, 250));
    QFont font = totalLabel->font();
    font.setBold(true);
    totalLabel->setFont(font);
    totalItems.append(totalLabel);

    // 第二列：空
    QStandardItem* emptyItem = new QStandardItem();
    emptyItem->setEditable(false);
    emptyItem->setBackground(QColor(230, 230, 250));
    totalItems.append(emptyItem);

    // 第三列：总销量（数值）
    QStandardItem* totalSalesItem = new QStandardItem();
    totalSalesItem->setData(totalSales, Qt::DisplayRole);  // 现在totalSales已定义
    totalSalesItem->setEditable(false);
    totalSalesItem->setTextAlignment(Qt::AlignCenter);
    totalSalesItem->setBackground(QColor(230, 230, 250));
    totalSalesItem->setFont(font);
    totalItems.append(totalSalesItem);

    // 第四列：总销售额（数值）
    QStandardItem* totalRevenueItem = new QStandardItem();
    totalRevenueItem->setData(totalRevenue, Qt::DisplayRole);  // 现在totalRevenue已定义
    totalRevenueItem->setEditable(false);
    totalRevenueItem->setTextAlignment(Qt::AlignCenter);
    totalRevenueItem->setBackground(QColor(230, 230, 250));
    totalRevenueItem->setFont(font);
    totalItems.append(totalRevenueItem);

    salesModel->appendRow(totalItems);
}

void SalesStatisticsDialog::onRefreshClicked()
{
    loadSalesData();
}

void SalesStatisticsDialog::onExportClicked()
{
    QString filePath = QFileDialog::getSaveFileName(
        this, "导出销售数据", "", "CSV文件 (*.csv);;所有文件 (*)"
    );

    if (filePath.isEmpty()) return;

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "错误", "无法创建文件");
        return;
    }

    QTextStream out(&file);
    out << "商品ID,商品名称,销量,销售额\n";

    for (int row = 0; row < salesModel->rowCount(); ++row) {
        QStringList rowData;
        for (int col = 0; col < salesModel->columnCount(); ++col) {
            QStandardItem* item = salesModel->item(row, col);

            // 特殊处理数值列
            if (col == 0 || col == 2 || col == 3) { // ID, 销量, 销售额列
                QVariant data = item->data(Qt::DisplayRole);

                // 检查是否是数值类型
                if (data.typeId() == QMetaType::Int || data.typeId() == QMetaType::Double) {
                    rowData << data.toString();
                } else {
                    rowData << item->text();
                }
            } else {
                rowData << item->text();
            }
        }
        out << rowData.join(",") << "\n";
    }

    file.close();
    QMessageBox::information(this, "导出完成", "销售数据已成功导出");
}

void SalesStatisticsDialog::onAIAnalysisClicked()
{
    // 首先检查是否设置了API密钥
    if (apiKey.isEmpty()) {
        // 提示用户输入API密钥
        bool ok;
        QString key = QInputDialog::getText(this, "设置API密钥",
                                          "请输入AI API密钥:",
                                          QLineEdit::Password,
                                          "",
                                          &ok);
        if (ok && !key.isEmpty()) {
            setAPIKey(key);
        } else {
            QMessageBox::warning(this, "警告", "未设置API密钥，无法进行AI分析");
            return;
        }
    }

    // 执行AI分析
    performAIAnalysis();
}

void SalesStatisticsDialog::performAIAnalysis()
{
    // 禁用按钮以防止重复点击
    aiAnalysisBtn->setEnabled(false);
    aiAnalysisBtn->setText("分析中...");

    // 从表格中收集销售数据
    QString salesData = "商品销售统计分析:\n";
    salesData += "商品ID,商品名称,销量,销售额\n";

    for (int row = 0; row < salesModel->rowCount() - 1; ++row) { // -1 to exclude total row
        QStringList rowData;
        for (int col = 0; col < salesModel->columnCount(); ++col) {
            QStandardItem* item = salesModel->item(row, col);
            rowData << item->text();
        }
        salesData += rowData.join(",") + "\n";
    }

    // 创建AI分析的提示
    QString prompt = QString("请分析以下销售数据并提供商业洞察：\n%1\n\n"
                           "请提供以下分析：\n"
                           "1. 销量最高的商品及其原因分析\n"
                           "2. 销量较低的商品及改进建议\n"
                           "3. 整体销售趋势分析\n"
                           "4. 商品组合优化建议\n"
                           "5. 未来销售预测").arg(salesData);

    // 创建API请求 - 使用智谱AI API
    QUrl url("https://open.bigmodel.cn/api/paas/v4/chat/completions");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", QString("Bearer %1").arg(apiKey).toUtf8());

    // 准备请求体 - 使用智谱AI的参数格式
    QJsonObject jsonBody;
    jsonBody["model"] = "glm-4.7"; // 使用智谱AI的GLM-4.7模型
    QJsonArray messages;

    // 添加系统提示
    QJsonObject systemMessage;
    systemMessage["role"] = "system";
    systemMessage["content"] = "你是一名专业的销售数据分析专家，擅长分析商品销售数据并提供商业洞察。";
    messages.append(systemMessage);

    // 添加用户请求
    QJsonObject userMessage;
    userMessage["role"] = "user";
    userMessage["content"] = prompt;
    messages.append(userMessage);

    jsonBody["messages"] = messages;
    jsonBody["temperature"] = 1.0; // 智谱AI推荐的温度值
    jsonBody["max_tokens"] = 65536; // 设置最大token数

    // 添加thinking参数（如果智谱AI支持）
    QJsonObject thinking;
    thinking["type"] = "enabled";
    jsonBody["thinking"] = thinking;

    QJsonDocument jsonDoc(jsonBody);
    QByteArray data = jsonDoc.toJson();

    // 发送请求
    QNetworkReply* reply = networkManager->post(request, data);

    // 连接完成信号
    connect(reply, &QNetworkReply::finished,
            this, [this, reply]() {
                onAIReplyFinished(reply);
            });
}

void SalesStatisticsDialog::onAIReplyFinished(QNetworkReply* reply)
{
    // 恢复按钮状态
    aiAnalysisBtn->setEnabled(true);
    aiAnalysisBtn->setText("AI分析");

    // 检查是否有错误
    if (reply->error() != QNetworkReply::NoError) {
        QMessageBox::critical(this, "错误",
                             QString("AI分析请求失败: %1").arg(reply->errorString()));
        reply->deleteLater();
        return;
    }

    // 读取响应数据
    QByteArray response = reply->readAll();
    QJsonDocument jsonResponse = QJsonDocument::fromJson(response);

    if (jsonResponse.isObject()) {
        QJsonObject obj = jsonResponse.object();
        if (obj.contains("choices") && obj["choices"].isArray()) {
            QJsonArray choices = obj["choices"].toArray();
            if (!choices.isEmpty()) {
                QJsonObject choice = choices[0].toObject();
                QJsonObject message = choice["message"].toObject();
                QString content = message["content"].toString();

                // 显示AI分析结果
                QDialog *resultDialog = new QDialog(this);
                resultDialog->setWindowTitle("AI分析结果");
                resultDialog->resize(800, 600);

                QVBoxLayout *layout = new QVBoxLayout(resultDialog);

                QTextEdit *textEdit = new QTextEdit(resultDialog);
                textEdit->setPlainText(content);
                textEdit->setReadOnly(true);

                QPushButton *closeBtn = new QPushButton("关闭", resultDialog);
                connect(closeBtn, &QPushButton::clicked, resultDialog, &QDialog::accept);

                layout->addWidget(textEdit);
                layout->addWidget(closeBtn);

                resultDialog->show();
                resultDialog->exec();
            } else {
                QMessageBox::warning(this, "警告", "AI分析未返回结果");
            }
        } else {
            // 检查是否有错误信息
            if (obj.contains("error")) {
                QJsonObject errorObj = obj["error"].toObject();
                QString errorMsg = errorObj["message"].toString();
                QMessageBox::critical(this, "API错误",
                                     QString("AI分析API返回错误: %1").arg(errorMsg));
            } else {
                QMessageBox::warning(this, "警告", "AI分析返回格式不正确");
            }
        }
    } else {
        QMessageBox::warning(this, "警告", "AI分析返回格式不正确");
    }

    reply->deleteLater();
}

void SalesStatisticsDialog::setAPIKey(const QString &key)
{
    apiKey = key; // 设置AI分析API密钥
}
