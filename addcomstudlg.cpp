#include "addcomstudlg.h"
#include "ui_addcomstudlg.h"
#include<QMessageBox>
#include<QSqlError>
#include<QSqlQuery>
addcomstudlg::addcomstudlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addcomstudlg)
{
    ui->setupUi(this);

    model_stu = new QSqlTableModel();
    model_stu->setTable("student");
    model_com = new QSqlTableModel();
    model_com->setTable("competition");
    model_comStu = new QSqlTableModel();
    model_comStu->setTable("competition_situation");
}

addcomstudlg::~addcomstudlg()
{
    delete ui;
}

void addcomstudlg::on_pushButton_2_clicked()
{
    close();
}

void addcomstudlg::on_pushButton_clicked()
{
    //参照完整性检查
    QSqlQuery qurry;
    qurry.exec(QString("select * from student where id = '%1'").arg(ui->stuIdLineEdit->text()));
    qurry.next();
    //student表参照
    if(!qurry.isValid())
    {
        QMessageBox::warning(this,"数据添加","不存在该学生");
    }
    else
    {
        //competition参照
        qurry.exec(QString("select * from competition where id = '%1'").arg(ui->comIdLineEdit->text()));
        qurry.next();
        if(!qurry.isValid())
        {
            QMessageBox::warning(this,"数据添加","不存在该竞赛");
        }
        else
        {
            //添加数据
            int rowNum = model_comStu->rowCount();
            model_comStu->insertRow(rowNum);
            model_comStu->setData(model_comStu->index(rowNum,0),ui->stuIdLineEdit->text());
            model_comStu->setData(model_comStu->index(rowNum,1),ui->comIdLineEdit->text());
            model_comStu->setData(model_comStu->index(rowNum,2),ui->gradeComboBox->currentText());
            model_comStu->setData(model_comStu->index(rowNum,3),ui->dateEdit->text());
            if(model_comStu->submitAll())
            {
                QMessageBox::warning(this,"数据添加","数据添加成功");
            }
            else
            {
                QMessageBox::warning(this,"tableModel",tr("数据库错误:%1").arg(model_comStu->lastError().text()));//错误提示
            }
        }
    }

    ui->stuIdLineEdit->clear();
    ui->comIdLineEdit->clear();
    ui->stuIdLineEdit->setFocus();
}
