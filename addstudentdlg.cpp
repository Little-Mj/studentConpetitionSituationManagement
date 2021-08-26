#include "addstudentdlg.h"
#include "ui_addstudentdlg.h"
#include <QMessageBox>
#include <QSqlError>
addstudentdlg::addstudentdlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addstudentdlg)
{
    ui->setupUi(this);
    
    model_stu = new QSqlTableModel();
    model_user = new QSqlTableModel();
    model_stu->setTable("student");
    model_user->setTable("users");
}

addstudentdlg::~addstudentdlg()
{
    delete ui;
}

void addstudentdlg::on_pushButton_clicked()
{
    //添加学生信息
    if(ui->idLineEdit->text().isEmpty()||ui->nameLineEdit_2->text().isEmpty())
        QMessageBox::warning(this,"数据缺失","请输入学号和姓名");
    else
    {
        int rowNum = model_stu->rowCount();
        model_stu->insertRow(rowNum);
        model_stu->setData(model_stu->index(rowNum,0),ui->idLineEdit->text());
        model_stu->setData(model_stu->index(rowNum,1),ui->nameLineEdit_2->text());
        model_stu->setData(model_stu->index(rowNum,2),ui->spinBox->text());
        if(ui->maleRadioButton->isChecked())
            model_stu->setData(model_stu->index(rowNum,3),"男");
        else
            model_stu->setData(model_stu->index(rowNum,3),"女");
        model_stu->setData(model_stu->index(rowNum,4),ui->majorLineEdit_4->text());
        model_stu->setData(model_stu->index(rowNum,5),ui->classLineEdit_5->text());
        model_stu->setData(model_stu->index(rowNum,6),ui->comboBox->currentText());
        model_stu->setData(model_stu->index(rowNum,7),ui->phoneLineEdit_6->text());
        if(model_stu->submitAll())
        {
            QMessageBox::warning(this,"添加数据","数据添加成功！");
        }
        else
        {
             QMessageBox::warning(this,"tableModel",tr("数据库错误:%1").arg(model_stu->lastError().text()));//错误提示
        }
        //添加用户
        rowNum = model_user->rowCount();
        model_user->insertRow(rowNum);
        model_user->setData(model_user->index(rowNum,0),ui->idLineEdit->text());
        model_user->setData(model_user->index(rowNum,1),ui->idLineEdit->text());
        model_user->setData(model_user->index(rowNum,2),"0");
        model_user->submitAll();

    }
    //清除已经输入的数据
    ui->idLineEdit->clear();
    ui->nameLineEdit_2->clear();
    ui->spinBox->clear();
    ui->majorLineEdit_4->clear();
    ui->classLineEdit_5->clear();
    ui->phoneLineEdit_6->clear();
    ui->idLineEdit->setFocus();

}

void addstudentdlg::on_pushButton_2_clicked()
{
    close();
}
