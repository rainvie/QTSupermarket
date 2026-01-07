#ifndef STYLEMANAGER_H
#define STYLEMANAGER_H

#include <QString>

class StyleManager
{
public:
    static StyleManager& instance();

    // Get the complete application style sheet
    QString getApplicationStyle() const;

    // Get specific component styles
    QString getButtonStyle() const;
    QString getTableStyle() const;
    QString getListViewStyle() const;
    QString getLineEditStyle() const;
    QString getComboBoxStyle() const;
    QString getGroupBoxStyle() const;
    QString getDialogStyle() const;

private:
    StyleManager() = default;
    ~StyleManager() = default;
    StyleManager(const StyleManager&) = delete;
    StyleManager& operator=(const StyleManager&) = delete;
};

#endif // STYLEMANAGER_H