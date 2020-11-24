#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include <QFile>
#include <QDebug>

namespace Ui {
class SettingDialog;
}

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = nullptr);
    ~SettingDialog();

    void fresh_settings();


signals:
    void refresh();

private slots:

    void on_buttonBox_accepted();

private:
    Ui::SettingDialog *ui;

    QString setting_file_path;
    QString ip_str;
    QString com_str;
    QVector<QString> buttons_name;
    QVector<QString> buttons_command;
    int button_num;
    QString log;

    QString delete_enter(QString str);
};

#endif // SETTINGDIALOG_H
