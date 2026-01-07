#include "Style/StyleManager.h"

StyleManager& StyleManager::instance()
{
    static StyleManager instance;
    return instance;
}

QString StyleManager::getApplicationStyle() const
{
    return R"(
        /* Global Application Styles */
        * {
            font-family: "Microsoft YaHei", "Segoe UI", Arial, sans-serif;
            font-size: 10pt;
        }

        QMainWindow {
            background-color: #f5f7fa;
            border: none;
            padding: 0px;
        }

        QWidget {
            background-color: #f5f7fa;
            color: #2c3e50;
        }

        QMenuBar {
            background-color: #34495e;
            color: white;
            border: none;
            padding: 4px;
        }

        QMenuBar::item {
            background: transparent;
            padding: 8px 16px;
            border-radius: 8px;
        }

        QMenuBar::item:selected {
            background: #3d566e;
        }

        QMenuBar::item:pressed {
            background: #2c3e50;
        }

        QToolBar {
            background-color: #34495e;
            border: none;
            padding: 6px;
            spacing: 4px;
        }

        QStatusBar {
            background-color: #34495e;
            color: white;
            border: none;
            padding: 6px;
        }

        QStatusBar QLabel {
            color: white;
        }

        QGroupBox {
            font-weight: bold;
            border: none;
            border-radius: 10px;
            margin-top: 1ex;
            padding: 12px;
            background-color: #ffffff;
        }

        QGroupBox::title {
            subcontrol-origin: margin;
            left: 12px;
            padding: 0 8px 0 8px;
            color: #3498db;
            font-size: 11pt;
        }

        QFrame {
            border: none;
            border-radius: 8px;
        }

        /* Include component styles */
    )" + getButtonStyle() + getTableStyle() + getLineEditStyle() + getComboBoxStyle() + getListViewStyle() + getDialogStyle();
}

QString StyleManager::getButtonStyle() const
{
    return R"(
        /* Button Styles */
        QPushButton {
            background-color: #3498db;
            color: white;
            border: none;
            border-radius: 15px;
            padding: 8px 16px;
            font-weight: bold;
            min-height: 30px;
            font-size: 9pt;
        }

        QPushButton:hover {
            background-color: #2980b9;
        }

        QPushButton:pressed {
            background-color: #21618c;
        }

        QPushButton:disabled {
            background-color: #bdc3c7;
            color: #7f8c8d;
        }

        /* Password visibility buttons (flat buttons with icons) */
        QPushButton[flat="true"] {
            min-width: 24px;
            min-height: 24px;
            padding: 2px;
            border-radius: 3px;
        }

        QPushButton[flat="true"]:hover {
            background-color: #e0e0e0;
        }

        /* Special button styles */
        QPushButton#deletebtn, QPushButton#clearbtn {
            background-color: #e74c3c;
        }

        QPushButton#deletebtn:hover, QPushButton#clearbtn:hover {
            background-color: #c0392b;
        }

        QPushButton#deletebtn:pressed, QPushButton#clearbtn:pressed {
            background-color: #a93226;
        }

        QPushButton#paybtn {
            background-color: #2ecc71;
        }

        QPushButton#paybtn:hover {
            background-color: #27ae60;
        }

        QPushButton#paybtn:pressed {
            background-color: #219653;
        }

        QPushButton#backbtn {
            background-color: #95a5a6;
        }

        QPushButton#backbtn:hover {
            background-color: #7f8c8d;
        }

        QPushButton#backbtn:pressed {
            background-color: #6c7a89;
        }

        /* Category buttons */
        QPushButton:checked {
            background-color: #f39c12;
        }

        QPushButton:checked:hover {
            background-color: #e67e22;
        }
    )";
}

QString StyleManager::getTableStyle() const
{
    return R"(
        /* Table View Styles */
        QTableView {
            background-color: #ffffff;
            alternate-background-color: #f8f9fa;
            border: 1px solid #dcdfe6;
            border-radius: 6px;
            gridline-color: #e4e7ed;
            selection-background-color: #e3f2fd;
            selection-color: #2c3e50;
            font-size: 10pt;
            padding: 4px;
        }

        QTableView::item {
            padding: 8px 12px;
            border: none;
            selection-background-color: #e3f2fd;
        }

        QTableView::item:selected {
            background-color: #bbdefb;
            color: #2c3e50;
            border: 1px solid #90caf9;
        }

        QTableView::item:hover {
            background-color: #e1f5fe;
        }

        QHeaderView::section {
            background-color: #34495e;
            color: white;
            padding: 10px;
            border: none;
            font-weight: bold;
            font-size: 10pt;
        }

        QHeaderView::section:horizontal {
            border-right: 1px solid #2c3e50;
        }

        QHeaderView::section:vertical {
            border-bottom: 1px solid #2c3e50;
        }

        QTableCornerButton::section {
            background-color: #34495e;
            border: 1px solid #2c3e50;
        }
    )";
}

QString StyleManager::getListViewStyle() const
{
    return R"(
        /* List View Styles */
        QListWidget {
            background-color: #ffffff;
            border: 1px solid #dcdfe6;
            border-radius: 6px;
            padding: 8px;
            font-size: 10pt;
        }

        QListWidget::item {
            background-color: #f8f9fa;
            border: 1px solid #e4e7ed;
            border-radius: 8px;
            padding: 12px;
            margin: 6px;
            font-size: 10pt;
            min-height: 50px;
        }

        QListWidget::item:selected {
            background-color: #e3f2fd;
            border: 2px solid #3498db;
            color: #2c3e50;
        }

        QListWidget::item:hover {
            background-color: #e1f5fe;
        }

        QListWidget::item:focus {
            outline: none;
        }
    )";
}

QString StyleManager::getLineEditStyle() const
{
    return R"(
        /* Line Edit Styles */
        QLineEdit {
            background-color: #ffffff;
            border: 1px solid #dcdfe6;
            border-radius: 6px;
            padding: 10px;
            color: #2c3e50;
            selection-background-color: #3498db;
            selection-color: white;
            font-size: 10pt;
        }

        QLineEdit:focus {
            border: 2px solid #3498db;
            outline: none;
        }

        QLineEdit:disabled {
            background-color: #ecf0f1;
            color: #95a5a6;
        }
    )";
}

QString StyleManager::getComboBoxStyle() const
{
    return R"(
        /* Combo Box Styles */
        QComboBox {
            background-color: #ffffff;
            border: 1px solid #dcdfe6;
            border-radius: 6px;
            padding: 10px 25px 10px 12px;
            min-height: 36px;
            color: #2c3e50;
            font-size: 10pt;
        }

        QComboBox:focus {
            border: 2px solid #3498db;
        }

        QComboBox::drop-down {
            subcontrol-origin: padding;
            subcontrol-position: top right;
            width: 25px;
            border-left: 1px solid #dcdfe6;
            border-top-right-radius: 6px;
            border-bottom-right-radius: 6px;
        }

        QComboBox::down-arrow {
            image: url(:/icon/down_arrow.png);
        }

        QComboBox QAbstractItemView {
            background-color: #ffffff;
            border: 1px solid #dcdfe6;
            border-radius: 4px;
            selection-background-color: #3498db;
            selection-color: white;
            outline: none;
        }
    )";
}

QString StyleManager::getGroupBoxStyle() const
{
    return R"(
        /* Group Box Styles */
        QGroupBox {
            font-weight: bold;
            border: 1px solid #bdc3c7;
            border-radius: 6px;
            margin-top: 1ex;
            padding-top: 10px;
            background-color: #ffffff;
        }
        
        QGroupBox::title {
            subcontrol-origin: margin;
            left: 10px;
            padding: 0 5px 0 5px;
            color: #3498db;
        }
    )";
}

QString StyleManager::getDialogStyle() const
{
    return R"(
        /* Dialog Styles */
        QDialog {
            background-color: #f5f7fa;
            border-radius: 10px;
            padding: 10px;
        }

        QDialog QLabel {
            color: #2c3e50;
        }

        QDialog QGroupBox {
            background-color: #ffffff;
        }
    )";
}