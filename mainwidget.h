#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "settingdialog.h"
#include <QFile>
#include <QDebug>
#include <QDateTime>
#include <QDir>
#include <QTcpSocket>
#include <QHostAddress>



QT_BEGIN_NAMESPACE
namespace Ui { class mainWidget; }
QT_END_NAMESPACE

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = nullptr);
    ~mainWidget();

    void fresh_settings();
    void log_print_and_record(QString tmp_log);



private slots:
    void on_b_setting_clicked();


    void on_b_log_keeping_clicked();

    void on_b_clear_clicked();

    void on_b0_clicked();

    void on_b_connect_clicked();

private:
    Ui::mainWidget *ui;

    QString setting_file_path;
    QString ip_str;
    QString com_str;
    QVector<QString> buttons_name;
    QVector<QString> buttons_command;
    int button_num;
    QString log;
    SettingDialog setting_dialog;
    QTcpSocket *tcpSocket;

    QString delete_enter(QString str);

};
#endif // MAINWIDGET_H
