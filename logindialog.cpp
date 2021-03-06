#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QSqlQuery>


LoginDialog::LoginDialog(QString *student_id,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    id=student_id;
    //    model = new QSqlTableModel();
    //    model->setTable("users");
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_clicked()
{

    //管理员登录
    QSqlQuery qurry;
    QString isAdmin="0";
    if(ui->adminRadioButton->isChecked())//是管理员账户
    {
        isAdmin ="1";
    }
    //查询用户表查看是否有此用户
    qurry.exec(QString("select id,password from users where isAdmin = %1 and id = '%2'").arg(isAdmin,ui->ursLineEdit->text()));
    qurry.next();
    if(qurry.value(0).isNull())
    {
        QMessageBox::warning(this,"用户登录","没有此用户");
        //清除已输入内容并设置光标到用户名
        ui->ursLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->ursLineEdit->setFocus();
    }
    else
    {
        //存在用户，验证密码
        if(ui->pwdLineEdit->text() == qurry.value(1).toString())
        {
            //学生界面
            if(ui->radioButton_2->isChecked())
                *id=ui->ursLineEdit->text();
            return accept();
        }
        else
        {
            QMessageBox::warning(this,"用户登录","密码错误");
            ui->pwdLineEdit->clear();
            ui->pwdLineEdit->setFocus();
        }
    }
}
