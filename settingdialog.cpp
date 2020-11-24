#include "settingdialog.h"
#include "ui_settingdialog.h"


SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
    //默认参数初始化
    setting_file_path = QString("../settings2.txt");
    button_num = 6;
    //其余参数初始化
    log = "";
    buttons_name = QVector<QString>(button_num,"");
    buttons_command = QVector<QString>(button_num,"");
    //刷新设置
    fresh_settings();
}

SettingDialog::~SettingDialog()
{
    delete ui;
}


/**
 * @brief mainWidget::fresh_settings：根据设置文件刷新设置
 */
void SettingDialog::fresh_settings(){
    //读取现有txt，如果没有就创建一个
    QFile file(setting_file_path);
    if(file.open(QIODevice::ReadOnly)){
        //读文件
        ip_str = delete_enter(QString::fromLocal8Bit(file.readLine()));
        com_str = delete_enter(QString::fromLocal8Bit(file.readLine()));
        for (int i = 0;i<button_num;i++) {
            buttons_name[i] = delete_enter(QString::fromLocal8Bit(file.readLine()));
        }
        for (int i = 0;i<button_num;i++) {
            buttons_command[i] = delete_enter(QString::fromLocal8Bit(file.readLine()));
        }
        file.close();
    }else{
        file.close();
        //直接赋默认值
        ip_str = "192.168.31.1";
        com_str = "8888";
        for (int i = 0;i<button_num;i++) {
            buttons_name[i] = QString::fromLocal8Bit("功能")+QString::number(i);
        }
        for (int i = 0;i<button_num;i++) {
            buttons_command[i] = QString::number(i);
        }
        //写文件
        if(file.open(QIODevice::WriteOnly)){
            file.write((ip_str+'\n').toLocal8Bit());
            file.write((com_str+'\n').toLocal8Bit());
            for (int i = 0;i<button_num;i++) {
                file.write((buttons_name[i]+'\n').toLocal8Bit());
            }
            for (int i = 0;i<button_num;i++) {
                file.write((buttons_command[i]+'\n').toLocal8Bit());
            }
        }
        file.close();
    }
    //更新显示
    ui->ip->setText(ip_str);
    ui->com->setText(com_str);
    ui->name0->setText(buttons_name[0]);
    ui->name1->setText(buttons_name[1]);
    ui->name2->setText(buttons_name[2]);
    ui->name3->setText(buttons_name[3]);
    ui->name4->setText(buttons_name[4]);
    ui->name5->setText(buttons_name[5]);
    ui->command0->setText(buttons_command[0]);
    ui->command1->setText(buttons_command[1]);
    ui->command2->setText(buttons_command[2]);
    ui->command3->setText(buttons_command[3]);
    ui->command4->setText(buttons_command[4]);
    ui->command5->setText(buttons_command[5]);
}


QString SettingDialog::delete_enter(QString str){
    int i=0;
    while (i<str.size()) {
        if(str[i]=='\n'||str[i]=='\r')str.remove(i,1);
        else i++;
    }
    return str;
}



void SettingDialog::on_buttonBox_accepted()
{
//    qDebug()<<"ddd";
    //保存设置到文件
    ip_str = ui->ip->text();
//    qDebug()<<ip_str;
    com_str = ui->com->text();
    buttons_name[0] = ui->name0->text();
    buttons_name[1] = ui->name1->text();
    buttons_name[2] = ui->name2->text();
    buttons_name[3] = ui->name3->text();
    buttons_name[4] = ui->name4->text();
    buttons_name[5] = ui->name5->text();
    buttons_command[0] = ui->command0->text();
    buttons_command[1] = ui->command1->text();
    buttons_command[2] = ui->command2->text();
    buttons_command[3] = ui->command3->text();
    buttons_command[4] = ui->command4->text();
    buttons_command[5] = ui->command5->text();


    //写文件
    QFile file(setting_file_path);
    if(file.open(QIODevice::WriteOnly)){
        file.write((ip_str+'\n').toLocal8Bit());
        file.write((com_str+'\n').toLocal8Bit());
        for (int i = 0;i<button_num;i++) {
            file.write((buttons_name[i]+'\n').toLocal8Bit());
        }
        for (int i = 0;i<button_num;i++) {
            file.write((buttons_command[i]+'\n').toLocal8Bit());
        }
    }
    file.close();
    //发送信号
    emit refresh();


}
