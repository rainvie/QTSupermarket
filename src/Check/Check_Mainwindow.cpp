#include "Check/Check_Mainwindow.h"
#include "ui_Check_Mainwindow.h"
#include "LogIn/LoginDialog.h"
#include "LogIn/SalesHistoryDialog.h"
#include "Style/StyleManager.h"

Check_Mainwindow::Check_Mainwindow(QString username,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Check_Mainwindow)
    , username(username)
{
    if (!DBManager::instance().initialize()) {
        QMessageBox::critical(this, "数据库错误", "无法初始化数据库，请检查配置");
        exit(1); // 数据库初始化失败则退出
    }

    //通过 username 查询 user_id
    cashierID = DBManager::instance().getUserIdByName(username);
    if (cashierID == -1) {
        QMessageBox::warning(this, "警告", "未找到当前用户信息");
    }

    ui->setupUi(this);

    // Apply the global application style
    setStyleSheet(StyleManager::instance().getApplicationStyle());

    setupUI();
    setWindowTitle("超市库存管理系统 - 收银模式");
    initcategory();
}

Check_Mainwindow::~Check_Mainwindow()
{
    delete ui;
}


void Check_Mainwindow::setupUI(){
    m_cartModel=new QStandardItemModel(0, 4, this);                             //初始化购物车模型
    m_cartModel->setHorizontalHeaderLabels({"商品", "单价", "数量", "小计"});     //设置购物车条目的标题

    ui->cartlistView->setModel(m_cartModel);                                   //关联模型和视图



    setWindowTitle(QString("超市库存管理系统 - 当前用户：%1").arg(username));


    // 查找 productgroupBox 并检查有效性
    QGroupBox* productGroupBox = findChild<QGroupBox*>("productgroupBox");
    if (!productGroupBox) {
        qCritical() << "无法找到 productgroupBox!";
        return;
    }

    // 检查布局是否存在且有效
    QLayout* groupLayout = productGroupBox->layout();
    if (!groupLayout || groupLayout->count() == 0) {
        qCritical() << "productgroupBox 布局为空或无效!";
        return;
    }


    QWidget* leftWidget = findChild<QWidget*>("leftWidget");       // 左侧按钮区
    QWidget* cartWidget = findChild<QWidget*>("cartWidget");       // 中间购物车区
    categoryWidget = findChild<QWidget*>("categoryWidget");        //分类按钮


    //设置按钮区
    QVBoxLayout* leftLayout = qobject_cast<QVBoxLayout*>(leftWidget->layout());
    if (leftLayout) {
        leftLayout->addStretch(); // 按钮居上，下方留白
    }


    //设置购物车区
    QVBoxLayout* cartLayout = qobject_cast<QVBoxLayout*>(cartWidget->layout());
    if (cartLayout) {
        ui->cartlistView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);   //设置购物车区域商品条目占满视图宽度
    }


    //设置商品区分类按钮+列表
    QWidget* categoryWidget = findChild<QWidget*>("categoryWidget");
    QHBoxLayout* categoryLayout = qobject_cast<QHBoxLayout*>(categoryWidget->layout());
    if (categoryLayout) {
        for (QPushButton* btn : m_categoryButtons) {
            categoryLayout->addWidget(btn);
        }
    }

    // 添加显示所有商品的复选框和AI分析按钮
    if (productGroupBox) {  // 使用已声明的productGroupBox变量
        QVBoxLayout* productLayout = qobject_cast<QVBoxLayout*>(productGroupBox->layout());
        if (productLayout) {
            // 创建一个水平布局来放置复选框和AI按钮
            QHBoxLayout* topControlsLayout = new QHBoxLayout();

            // 创建复选框
            m_showAllProductsCheckBox = new QCheckBox("显示所有商品", productGroupBox);
            m_showAllProductsCheckBox->setChecked(true);  // 默认选中，显示所有商品
            m_showAllProductsCheckBox->setStyleSheet("QCheckBox {"
                                                   "    color: #1565C0;"      // 深蓝色文字
                                                   "    font-size: 16px;"     // 字体大小
                                                   "    font-weight: bold;"   // 加粗
                                                   "    spacing: 5px;"        // 间距
                                                   "}"
                                                   "QCheckBox::indicator {"
                                                   "    width: 16px;"         // 指示器宽度
                                                   "    height: 16px;"        // 指示器高度
                                                   "}"
                                                   "QCheckBox::indicator:unchecked {"
                                                   "    border: 2px solid #1565C0;"  // 未选中时边框
                                                   "    background: white;"          // 未选中时背景
                                                   "}"
                                                   "QCheckBox::indicator:checked {"
                                                   "    border: 2px solid #1565C0;"  // 选中时边框
                                                   "    background: #1565C0;"        // 选中时背景
                                                   "}");

            // 创建AI分析按钮
            m_aiAnalysisBtn = new QPushButton("🤖 AI分析", productGroupBox);
            m_aiAnalysisBtn->setStyleSheet("QPushButton {"
                                         "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                         "                                    stop: 0 #FF5722, stop: 1 #E64A19);"  // 渐变橙红色背景
                                         "    border: 2px solid #B71C1C;"      // 红色边框
                                         "    color: white;"                   // 白色文字
                                         "    padding: 8px 12px;"              // 内边距
                                         "    text-align: center;"             // 文字居中
                                         "    font-size: 16px;"                // 字体大小
                                         "    font-weight: bold;"              // 加粗字体
                                         "    border-radius: 6px;"             // 圆角
                                         "}"
                                         "QPushButton:hover {"
                                         "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                         "                                    stop: 0 #FF7043, stop: 1 #D84315);"  // 悬停时的渐变色
                                         "}"
                                         "QPushButton:pressed {"
                                         "    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
                                         "                                    stop: 0 #E64A19, stop: 1 #BF360C);"  // 按下时的渐变色
                                         "    border: 2px solid #8E0E00;"      // 按下时更深的边框
                                         "    padding: 7px 11px;"              // 按下时稍微缩小内边距，产生按下效果
                                         "}");
            m_aiAnalysisBtn->setMinimumSize(80, 35);  // 设置最小尺寸

            // 将复选框和AI按钮添加到水平布局
            topControlsLayout->addWidget(m_showAllProductsCheckBox);
            topControlsLayout->addStretch();  // 添加伸缩空间
            topControlsLayout->addWidget(m_aiAnalysisBtn);  // 将AI按钮放在右侧

            // 将这个布局插入到分类按钮和商品列表之间
            productLayout->insertLayout(0, topControlsLayout);  // 插入到索引0位置

            // 连接复选框状态改变信号
            connect(m_showAllProductsCheckBox, &QCheckBox::checkStateChanged,
                   this, [this](Qt::CheckState state) {
                       // 根据复选框状态决定是否显示所有商品
                       // 这里可以实现商品筛选逻辑
                       // 如果选中（state == Qt::Checked），显示所有商品
                       // 如果未选中（state == Qt::Unchecked），可以实现其他筛选逻辑
                       // 比如只显示有库存的商品等

                       // 重新加载商品列表，根据复选框状态进行筛选
                       if (state == Qt::Checked) {
                           // 显示所有商品，重新加载当前分类的商品
                           updateProduct();  // 重新调用更新商品函数
                       } else {
                           // 可以实现其他筛选逻辑，比如只显示有库存的商品
                           // 这里暂时也显示所有商品，您可以根据需要修改筛选逻辑
                           updateProduct();  // 重新调用更新商品函数
                       }
                   });

            // 连接AI分析按钮点击信号
            connect(m_aiAnalysisBtn, &QPushButton::clicked, this, [this]() {
                // 显示一个简单的信息对话框，说明AI功能
                QMessageBox::information(this, "AI分析",
                                       "AI分析功能正在开发中...\n"
                                       "此功能将分析销售数据并提供商业洞察。\n"
                                       "API密钥可在设置中配置。");
            });
        }
    }

    ui->productlistWidget->setDragDropMode(QAbstractItemView::NoDragDrop); //           禁用商品区拖放
    ui->productlistWidget->setSelectionMode(QAbstractItemView::SingleSelection); //     限制商品区单选


    //这里我（lbr-lbl）修改了一下，限制了商品图标大小，不决定最终效果
    // 设置商品列表为网格视图
    ui->productlistWidget->setViewMode(QListView::IconMode);
    ui->productlistWidget->setGridSize(QSize(80, 80));
    ui->productlistWidget->setIconSize(QSize(80, 80));
    ui->productlistWidget->setResizeMode(QListView::Adjust);
    //修正了购物车标题栏无法显示，不代表最终效果
    if (QTableView* tableView = qobject_cast<QTableView*>(ui->cartlistView)) {
        // 确保标题可见
        tableView->horizontalHeader()->setVisible(true);

        // 设置合理的列宽策略
        tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch); // 商品列拉伸
        tableView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch); // 单价列拉伸
        tableView->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch); // 数量列拉伸
        tableView->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch); // 小计列拉伸

        // 设置最小行高
        tableView->verticalHeader()->setDefaultSectionSize(36);
    }




    //在状态栏添加收银员和日期

    QLabel* cashierLabel = new QLabel(this);         // 创建收银员标签（左侧）
    cashierLabel->setText(QString("当前操作员：%1").arg(username));
    cashierLabel->setStyleSheet("color: black; margin-left: 10px;");  //设置字体颜色为黑色，左侧留边距


    QLabel* dateLabel = new QLabel(this);           //创建日期标签（右侧）
    QDate currentDate = QDate::currentDate();  //获取当前日期
    dateLabel->setText(currentDate.toString("当前日期：yyyy-MM-dd"));  //格式化日期为"年-月-日"
    dateLabel->setStyleSheet("color: black; margin-right: 10px;");  //设置字体颜色为黑色，右侧留边距

    //添加到状态栏
    statusBar()->addWidget(cashierLabel);  // 左侧添加，随窗口缩放左移
    statusBar()->addPermanentWidget(dateLabel);  // 右侧添加，固定在右边

    // 确保状态栏可见（发送一个空的临时消息）
    statusBar()->showMessage("");






    //连接信号与槽
    connect(ui->productlistWidget, &QListWidget::itemDoubleClicked,this, &Check_Mainwindow::chooselistWidgetitemDoubleClicked);
    connect(ui->changebtn, &QPushButton::clicked,this, &Check_Mainwindow::changebtnclicked);
    connect(ui->deletebtn, &QPushButton::clicked,this, &Check_Mainwindow::deletebtnclicked);
    connect(ui->clearbtn, &QPushButton::clicked,this, &Check_Mainwindow::clearbtnclicked);
    connect(ui->paybtn, &QPushButton::clicked,this, &Check_Mainwindow::paybtnclicked);
    connect(ui->backbtn,&QPushButton::clicked,this,&Check_Mainwindow::backbtnclicked);
    connect(ui->addmemberbtn,&QPushButton::clicked,this,&Check_Mainwindow::addmemberclicked);



    if (!ui) {
        qCritical() << "ui 未初始化!";
        return;
    }
    if (!ui->cartlistView || !ui->changebtn || !ui->deletebtn) {
        qCritical() << "UI 控件缺失，请检查 .ui 文件!";
        return;
    }

}


//获取所有商品分类
QStringList Check_Mainwindow::getcategory() {
    QStringList categories;
    categories << "全部";                         //默认显示全部


    //调用getAllProducts() 获取所有商品的ID
    const auto& allProducts = DBManager::instance().getAllProducts();
    QSet<int> productIds;                                 //存储所有商品的ID同时去重
    for (auto it = allProducts.begin(); it != allProducts.end(); ++it) {
        const auto& product = *it;
        productIds.insert(product["id"].toInt());
    }

    //遍历每个商品ID，调用getProductById获取分类
    QSet<QString> categorySet;  //分类的去重
    for (int productId : productIds) {
        QMap<QString, QVariant> product = DBManager::instance().getProductById(productId);  //调用getProductById 获取单个商品信息
        if (product.isEmpty()) continue;              //跳过无效商品

        QString category = product["category"].toString();
        if (!category.isEmpty()) {                    //只收集非空分类
            categorySet.insert(category);
        }
    }

    //将去重后的分类添加到列表
    for (const QString& category : categorySet) {
        categories.append(category);
    }

    return categories;
}


//获取商品分类并创建分类按钮(动态生成按钮）
void Check_Mainwindow::initcategory(){

    QStringList categories = getcategory();                                    //查找布局
    QHBoxLayout* categoriesLayout = findChild<QHBoxLayout*>("categoryButtonsLayout");
    if (!categoriesLayout) {
        qCritical() << "未找到分类按钮布局 categoryButtonsLayout!";
        return;
    }



    for (auto it = categories.begin(); it != categories.end(); ++it) {
        const QString& category = *it;
        QPushButton* btn = new QPushButton(category,categoryWidget);
        btn->setCheckable(true);                                //设置为单选按钮
        if (category == "全部") btn->setChecked(true);          //默认选中“全部”分类

        //修改一下按钮的样式
        btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding); //宽度随着窗口扩展，高度在大于最小值的情况下随着窗口扩展
        btn->setStyleSheet(""
                           "min-width: 60px;"   //最小宽度，避免过窄
                           "min-height: 40px;"  //最小高度，确保可点击
                           "padding: 6px;"      //内边距，增加点击区域
                           );
        btn->setStyleSheet("text-align: center;");  // 确保文字居中

        m_categoryButtons.push_back(btn);                      //把按钮存入容器
        categoriesLayout->addWidget(btn);                      //把每个按钮添加到布局中

        // 连接按钮点击事件
        connect(btn, &QPushButton::clicked, this, [this, btn]() {      //实现单选效果：遍历所有按钮，只选中当前点击的按钮
            for (QPushButton* otherBtn : m_categoryButtons) {
                otherBtn->setChecked(otherBtn == btn);
            }
            updateProduct(btn->text());                                //更新商品列表
        });
    }

    // 初始显示全部商品
    updateProduct();

}


//根据不同分类来更新商品列表
void Check_Mainwindow::updateProduct(const QString& category){
    ui->productlistWidget->clear();
    QList<QMap<QString, QVariant>> products;

    if (category == "全部") {
        products = DBManager::instance().getAllProducts();                //全部商品，调用getAllProducts接口
    } else {
        products = DBManager::instance().getProductsByCategory(category); //指定分类，调用getProductsByCategory接口
    }



    for (auto it = products.begin(); it != products.end(); ++it) {
        const auto& productData = *it;
        PRoduct product(
            productData["id"].toInt(),
            productData["name"].toString(),
            "",
            productData["price"].toDouble(),
            productData["stock"].toInt(),
            productData["category"].toString(),
            productData["monthly_sales"].toInt()

            );

        QListWidgetItem* item = new QListWidgetItem;
        item->setText(QString("%1\n%2元\n库存: %3")
                          .arg(product.name())
                          .arg(product.price(), 0, 'f', 2)
                          .arg(product.stock()));                         //给productlistWidget创建列表项并设置文本


        item->setData(Qt::UserRole, product.id());                        //设置商品ID作为标识
        item->setIcon(QIcon::fromTheme("package-x-generic", QIcon(":/icons/product.png")));   //设置商品图片

        ui->productlistWidget->addItem(item);
    }


}


//更新购物车的总价
void Check_Mainwindow::updateCarttotal(){
    double total=0;
    for (const auto &item:m_cartItems) {                                              //历遍购物车，累加总价
        total+=item.getTotalPrice();
    }
    ui->totalLabel->setText(QString("总计：%1元").arg(total, 0, 'f', 2));              //显示总价
}


//更新购物车
void Check_Mainwindow::updateCartview(){
    m_cartModel->removeRows(0, m_cartModel->rowCount());                              //清空购物车界面的旧显示（从第0行删到总行）

    for (const CartItem& item:m_cartItems) {                                          //逐个处理m_cartItems中的商品条目
        const PRoduct& product=item.product();                                        //获取商品信息

        QList<QStandardItem*> rowItems;                                               //把商品信息转化为QStandardItem类型的单元格数据，每行有四个单元格
        rowItems<<new QStandardItem(product.name());
        rowItems<<new QStandardItem(QString::number(product.price(), 'f', 2));
        rowItems<<new QStandardItem(QString::number(item.quantity()));
        rowItems<<new QStandardItem(QString::number(item.getTotalPrice(), 'f', 2));

        rowItems[0]->setData(product.id(),Qt::UserRole);                              //存储商品ID便于后续操作

        m_cartModel->appendRow(rowItems);                                             //把数据加到模型中
    }

    updateCarttotal();
}


//双击商品弹出选择数量的对话框，随后将商品加入购物车
void Check_Mainwindow::chooselistWidgetitemDoubleClicked(QListWidgetItem *item){
    if (!item) return;                                                 //确保选中有效商品

    int productId = item->data(Qt::UserRole).toInt();                  //获取选中的商品ID

    QMap<QString, QVariant> productData = DBManager::instance().getProductById(productId);      //调用getProductById接口查询商品详情
    if (productData.isEmpty()) {
        QMessageBox::warning(this, "错误", "商品信息不存在");
        return;
    }

    PRoduct product(
        productId,
        productData["name"].toString(),
        "",
        productData["price"].toDouble(),
        productData["stock"].toInt()
        );

    if (product.stock() <= 0) {                                           //检查商品库存
        QMessageBox::warning(this, "库存不足", "该商品已售罄");
        return;
    }


    //弹出模态的数量选择对话框
    QuantityDialog dialog(product.stock(), this);
    if (dialog.exec() != QDialog::Accepted) {
        return; //用户取消选择，直接返回
    }
    int addQuantity = dialog.getQuantity();  //新添商品数量

    //检查购物车中该商品的已有数量
    int existingQuantity = 0;
    bool found = false;
    for (auto it = m_cartItems.begin(); it != m_cartItems.end(); ++it) {
        const auto& cartItem = *it;
        if (cartItem.product().id() == productId) {
            existingQuantity = cartItem.quantity();
            found = true;
            break;
        }
    }

    //计算已有数量+新添数量是否超过库存，超过就return
    if (existingQuantity + addQuantity > product.stock()) {
        QMessageBox::warning(this, "库存不足",
                             QString("当前库存仅%1个，无法添加%2个（购物车中已有%3个）")
                                 .arg(product.stock())
                                 .arg(addQuantity)
                                 .arg(existingQuantity));
        return; //不执行添加操作
    }

    //若未超过库存，则更新购物车
    if (found) {
        //若购物车中已有该商品，就更新数量
        for (auto it = m_cartItems.begin(); it != m_cartItems.end(); ++it) {
            auto& cartItem = *it;
            if (cartItem.product().id() == productId) {
                cartItem.setQuantity(existingQuantity + addQuantity);
                break;
            }
        }
    } else {
        //若购物车中没有该商品，就新加商品
        m_cartItems.emplace_back(product, addQuantity);
    }

    updateCartview(); // 刷新购物车显示


}


//改数键
void Check_Mainwindow::changebtnclicked()
{   QModelIndex index=ui->cartlistView->currentIndex();                                 //获取购物车项目索引
    if (!index.isValid()) {                                                             //如果没有索引就给出提示
        QMessageBox::warning(this, "提示", "请先选择要修改的商品");
        return;
    }

    int row = index.row();                                                              //获取行号，商品ID和商品数量
    int productId=m_cartModel->item(row, 0)->data(Qt::UserRole).toInt();
    int currentQuantity=m_cartModel->item(row, 2)->text().toInt();

    QMap<QString, QVariant> productData = DBManager::instance().getProductById(productId);  //调用getProductById接口查询商品库存
    if (productData.isEmpty()) return;
    int maxStock = productData["stock"].toInt();

    QuantityDialog dialog(maxStock, this);                                              //弹出修改数量对话框
    dialog.setWindowTitle("修改数量");
    dialog.findChild<QSpinBox*>()->setValue(currentQuantity);                           //把弹出的修改数量对话框初始值改为当前的商品数量

    if (dialog.exec()==QDialog::Accepted) {                                             //当用户点击确定时，将商品数量更改为确定的值
        int newQuantity=dialog.getQuantity();

        for (auto &item:m_cartItems) {                                                  //更新购物车
            if (item.product().id()==productId) {
                item.setQuantity(newQuantity);
                break;
            }
        }
        updateCartview();
    }

}



//删除键
void Check_Mainwindow::deletebtnclicked()
{   QModelIndex index=ui->cartlistView->currentIndex();                             //获取选中项的模型索引
    if (!index.isValid()) {                                                         //检查索引是否有效
        QMessageBox::warning(this, "提示", "请先选择要删除的商品");
        return;
    }

    int productId = m_cartModel->item(index.row(), 0)->data(Qt::UserRole).toInt();   //通过索引获取商品ID
    for (auto it = m_cartItems.begin(); it != m_cartItems.end(); ++it) {             //历遍购物车，检查获得的商品ID是否与要删除的商品ID一致
        if (it->product().id() == productId) {
            m_cartItems.erase(it);
            break;
        }
    }
    updateCartview();                                                                 //更新购物车
}



//清空键
void Check_Mainwindow::clearbtnclicked()
{
    if (m_cartItems.empty()) {                                                         //检查购物车是否为空
        QMessageBox::information(this, "提示", "购物车已经是空的");
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(                         //确认对话框
        this, "确认清空", "确定要清空购物车中的所有商品吗？",
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {

        m_cartItems.clear();

        updateCartview();                                                                //更新购物车显示

        QMessageBox::information(this, "成功", "购物车已清空");
    }
}


//支付键
void Check_Mainwindow::paybtnclicked()
{
    //检查购物车是否为空
    if (m_cartItems.empty()) {
        QMessageBox::information(this, "提示", "购物车为空，无需支付");
        return;
    }


    // 计算总金额
    double total = 0;
    for (const auto &item : m_cartItems) {
        total += item.getTotalPrice();
    }


    //会员折扣处理

    QString memberPhone;
    double discount = 1.0; // 默认无折扣
    int pointsEarned = static_cast<int>(total); // 1元=1积分
    bool isBirthday = false; //生日标志
    bool hasmember = false;  //会员标志

    //弹出对话框询问用户是否有会员
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "会员", "是否使用会员折扣?",
        QMessageBox::Yes | QMessageBox::No             //点击yes进入会员流程，点击no正常结算
        );

    if (reply == QMessageBox::Yes) {

        bool ok;
        memberPhone = QInputDialog::getText(                 //储存用户输入的手机号
            this, "会员", "请输入会员手机号:",
            QLineEdit::Normal, "", &ok
            );
        if (ok && !memberPhone.isEmpty()) {                  //点击ok且输入的手机号不是空的
            DBManager& db = DBManager::instance();
            QMap<QString, QVariant> member = db.getMemberByPhone(memberPhone);  //从数据库查询手机号信息（以判断是否是会员）

            //若会员存在则进行折扣计算
            if (!member.empty()) {
                hasmember = true;      //标记为有效会员

                // 生日判断（对比会员生日与当天的日期）
                QString birthdayStr = member["birthday"].toString();
                QDate birthday = QDate::fromString(birthdayStr, "yyyy-MM-dd");
                QDate today = QDate::currentDate();
                isBirthday = (birthday.month() == today.month() && birthday.day() == today.day());

                // 折扣计算：生日优先，再取会员折扣与积分折扣的最小值
                if (isBirthday) {
                    discount = 0.85; // 生日专属折扣
                } else {
                    double baseDiscount = db.getMemberDiscount(memberPhone);     //会员等级对应的基础折扣
                    int currentPoints = db.getMemberPoints(memberPhone);         //会员当前的积分
                    double pointsDiscount = db.calculateDiscountByPoints(currentPoints);      //积分对应的折扣
                    discount = qMin(baseDiscount, pointsDiscount);               //取基础折扣和积分折扣中的最优折扣
                }

                // 积分更新（生日双倍）
                int pointsToAdd = isBirthday ? pointsEarned * 2 : pointsEarned;                       //计算新积分
                db.updateMemberPoints(memberPhone, db.getMemberPoints(memberPhone) + pointsToAdd);    //累加积分到数据库

            }

            //若会员不存在则提示原价支付
            else {
                QMessageBox::warning(this, "提示", "该手机号不是会员，将按原价支付");
            }
        }
    }


    //计算折扣后最终金额
    double finalTotal = total * discount;            //计算应付金额
    double originalTotal = total;                    //保存原价（用于展示节省金额）
    double savedAmount = originalTotal - finalTotal; // 计算节省的金额

    //让用户输入实付金额
    bool ok;
    double payment = QInputDialog::getDouble(
        this, "支付",
        QString("应付金额: %1元\n请输入实付金额:").arg(finalTotal),        //显示应付金额
        finalTotal, 0, 1000000, 2, &ok                                   //默认值为应付金额，精度保留2位小数
        );

    //验证实付金额（取消输入或金额不足则支付失败）
    if (!ok || payment < finalTotal) {
        QMessageBox::warning(this, "支付失败", "实付金额不足或取消支付");
        return;
    }
    double change = payment - finalTotal;    //计算找零



    //用getProductById记录原始库存
    QMap<int, int> originalStock;

    for (auto it = m_cartItems.begin(); it != m_cartItems.end(); ++it) {
        const auto& cartItem = *it;
        int productId = cartItem.product().id();
        QMap<QString, QVariant> product = DBManager::instance().getProductById(productId);

        if (product.isEmpty()) {
            QMessageBox::critical(this, "错误", QString("获取商品(ID:%1)库存失败").arg(productId));
            return;
        } else {
            originalStock[productId] = product["stock"].toInt();          //查询每个商品的库存信息，并存储到originalStock中
        }
    }

    //扣减库存
    bool stockDeductionSuccess = true;

    for (auto it = m_cartItems.begin(); it != m_cartItems.end(); ++it) {
        const auto& cartItem = *it;
        int productId = cartItem.product().id();
        int buyQuantity = cartItem.quantity();

        QSqlQuery query;
        query.prepare("UPDATE products SET stock = stock - ? WHERE id = ? AND stock >= ?");     //确保库存够才进行减扣
        query.addBindValue(buyQuantity);
        query.addBindValue(productId);
        query.addBindValue(buyQuantity);

        if (!query.exec() || query.numRowsAffected() == 0) {
            stockDeductionSuccess = false;
            qCritical() << "库存更新失败，可能库存不足:" << query.lastError().text();
            break;
        }
    }

    if (!stockDeductionSuccess) {
        //若库存扣减失败，回滚到库存快照值
        for (auto it = originalStock.begin(); it != originalStock.end(); ++it) {
            QSqlQuery restoreQuery;
            restoreQuery.prepare("UPDATE products SET stock = ? WHERE id = ?");
            restoreQuery.addBindValue(it.value());
            restoreQuery.addBindValue(it.key());
            restoreQuery.exec();
        }
        QMessageBox::critical(this, "支付失败", "库存不足，支付已取消");
        return;
    }





    //将购物车商品转化为销售明细列表，准备插入数据库
    QList<QVariantMap> saleItems;
    for (auto it = m_cartItems.begin(); it != m_cartItems.end(); ++it) {
        const auto& cartItem = *it;
        QVariantMap itemData;
        itemData["product_id"] = cartItem.product().id();      //商品ID
        itemData["quantity"] = cartItem.quantity();            //购买数量
        itemData["price"] = cartItem.product().price();        //商品单价（原价）
        saleItems.append(itemData);
    }


    //如果库存扣减成功，继续调用addSale
    DBManager& db = DBManager::instance();
    bool success = db.addSale(
        cashierID,
        finalTotal,
        payment,
        saleItems,
        hasmember ? memberPhone : ""                 //是会员就记录手机号，不是就记为空
        );


    //处理支付结果
    if (success) {
        // 构建支付成功信息
        QString message = QString("支付金额: %1元\n").arg(payment);  //显示实付金额
        message += QString("应付金额: %1元\n").arg(finalTotal);       //显示应付金额
        message += QString("找零: %1元\n\n").arg(change);            //显示找零

        if (discount < 1.0) {
            message += QString("原价: %1元\n节省: %2元\n")
                           .arg(originalTotal).arg(savedAmount);
            if (hasmember) {
                message += isBirthday ? "折扣详情: 生日85折\n"
                                      : QString("折扣详情: 会员折扣(%1折)\n")
                                            .arg(discount * 10);
            }
        }
        if (hasmember) {
            message += QString("获得积分: %1").arg(pointsEarned);
            if (isBirthday) {
                message += " (生日双倍积分)";
            }
        }

            // 显示结果并刷新界面
            QMessageBox::information(
                this,
                isBirthday ? "生日快乐！支付成功" : "支付成功",    //会员生日与普通支付的提示
                message
                );
            m_cartItems.clear();         //清空购物车数据
            updateCartview();            //更新购物车界面
            updateProduct("全部");       //刷新商品列表
        }
    else {                                 //如果失败，回滚事务，并取消已执行SQL的操作
        //销售记录添加失败，恢复库存
        for (auto it = originalStock.begin(); it != originalStock.end(); ++it) {
            QSqlQuery restoreQuery;
            restoreQuery.prepare("UPDATE products SET stock = ? WHERE id = ?");                //将商品直接设置为快照中的值
            restoreQuery.addBindValue(it.value());               //原始库存
            restoreQuery.addBindValue(it.key());                 //商品ID
            if (!restoreQuery.exec()) {
                qCritical() << "恢复库存失败（商品ID:" << it.key() << "）：" << restoreQuery.lastError().text();
            }
        }
        QMessageBox::critical(this, "支付失败", "添加销售记录失败，已恢复库存");
     }

}

//返回键
void Check_Mainwindow::backbtnclicked(){
    //询问用户是否确认返回
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "确认返回", "返回登录界面将清空当前购物车，是否继续？",
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::Yes) {
        //清空购物车
        m_cartItems.clear();
        updateCartview();

        emit backToLogin();  //发送返回登录的信号
        this->close();       //关闭当前收银窗口

    }
}


//添加会员键
void Check_Mainwindow::addmemberclicked(){
    //获取用户输入的手机号
    bool ok;
    QString phone = QInputDialog::getText(
        this, "添加会员", "请输入会员手机号:",
        QLineEdit::Normal, "", &ok
        );

    if (!ok || phone.isEmpty()) return; // 用户取消或输入为空

    //验证手机号格式（11位数字）
    if (!phone.startsWith("1") || phone.length() != 11 || !phone.toLongLong()) {
        QMessageBox::warning(this, "错误", "请输入有效的11位手机号");
        return;
    }

    //检查手机号是否已注册
    DBManager& db = DBManager::instance();
    QMap<QString, QVariant> member = db.getMemberByPhone(phone);
    if (!member.isEmpty()) {
        QMessageBox::information(this, "提示", "该手机号已注册为会员");
        return;
    }


    //输入会员信息（包含姓名和生日）
    QDialog dialog(this);                 //创建模态对话框
    dialog.setWindowTitle("添加会员");
    dialog.setMinimumWidth(300);

    QFormLayout layout(&dialog);         //自动对齐标签和输入框

    QLineEdit* nameEdit = new QLineEdit(&dialog);     //输入会员姓名
    QLineEdit* birthdayEdit = new QLineEdit(&dialog); //输入会员生日
    birthdayEdit->setPlaceholderText("YYYY-MM-DD");

    layout.addRow("姓名:", nameEdit);
    layout.addRow("生日:", birthdayEdit);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &dialog);
    layout.addRow(&buttonBox);

    connect(&buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(&buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() != QDialog::Accepted) return;

    QString name = nameEdit->text().trimmed();             //去除无效的空白字符
    QString birthdayStr = birthdayEdit->text().trimmed();

    // 验证生日是否正确
    QDate birthday;
    if (!birthdayStr.isEmpty()) {
        birthday = QDate::fromString(birthdayStr, "yyyy-MM-dd");
        if (!birthday.isValid()) {
            QMessageBox::warning(this, "错误", "生日格式不正确，请使用 YYYY-MM-DD 格式");
            return;
        }
    }
    if (birthday > QDate::currentDate()) {
        QMessageBox::warning(this, "错误", "你小子还没出生就来超市购物是吧");
        return;
    }

    // 创建会员（默认折扣0.95，初始积分为0）
    bool success = db.addMember(
        phone,             //手机号
        name,              //姓名
        0.95,              //固定95折
        birthdayStr,       //生日
        0                  //初始积分
        );

    if (success) {
        QMessageBox::information(this, "成功", "会员添加成功！默认折扣95折");
    } else {
        QMessageBox::critical(this, "失败", "添加会员失败，请重试");
    }

}


void Check_Mainwindow::on_historyBtn_clicked()
{
    if (cashierID == -1) {
        QMessageBox::warning(this, "警告", "未找到当前收银员信息");
        return;
    }

    SalesHistoryDialog dialog(cashierID, this);
    dialog.exec();
}
