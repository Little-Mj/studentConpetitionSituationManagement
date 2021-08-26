#include "studentmainwindow.h"
#include "ui_studentmainwindow.h"
#include <QTableView>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
studentMainWindow::studentMainWindow(QString student_id,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::studentMainWindow)
{
    ui->setupUi(this);
    model = new QSqlQueryModel;
    id=student_id;

    //输出学生学号和姓名
    QSqlQuery qurry;
    qurry.exec(QString("select id,name from student where id='%1'").arg(id));
    qurry.next();
    ui->lineEdit->setText(QString("%1  %2").arg(qurry.value(0).toString(),qurry.value(1).toString()));

//查看user表的数据
//    model->setQuery("select * from users");
//    QTableView *view = new QTableView;
//    view->setModel(model);
//    view->show();

}

studentMainWindow::~studentMainWindow()
{
    delete ui;
}

void studentMainWindow::on_pushButton_clicked()
{
    //查看学生信息
    model->setQuery(QString("select * from student where id = '%1'").arg(id));
    QStringList tables;
    tables <<"学号"<<"姓名"<<"年龄"<<"性别"<<"专业"<<"班级"<<"学院"<<"电话号码";
    for(int i=0;i<tables.count();i++)
        model->setHeaderData(i,Qt::Horizontal,tables[i]);
    QTableView *view = new QTableView;
    view->setModel(model);
    view->show();
}

void studentMainWindow::on_pushButton_2_clicked()
{
    //查看获奖记录
    model->setQuery(QString("select student.id,student.name,student.major,"
                            "competition.name,competition.degree,"
                            "competitiom_situation.grade,competitiom_situation time "
                            " from student,competition,competition_situation "
                            "   where student_id = '%1' and student.id=competitiom_situation.student_id and"
                            "           competitiom_situation.competition_id = competition.id").arg(id));
    QStringList tables;
    tables <<"学生学号"<<"学生姓名"<<"专业"<<"竞赛名称"<<"竞赛级别"<<"获奖情况"<<"获奖时间";
    for(int i=0;i<tables.count();i++)
        model->setHeaderData(i,Qt::Horizontal,tables[i]);
    QTableView *view = new QTableView;
    view->setModel(model);
    view->show();
}

void studentMainWindow::on_pushButton_3_clicked()
{
    //查看竞赛信息
    model->setQuery(QString("select * from competition").arg(id));
    QStringList tables;
    tables <<"竞赛代码"<<"竞赛名称"<<"竞赛级别"<<"竞赛类别";
    for(int i=0;i<tables.count();i++)
        model->setHeaderData(i,Qt::Horizontal,tables[i]);
    QTableView *view = new QTableView;
    view->setModel(model);
    view->show();
}

void studentMainWindow::on_pushButton_4_clicked()
{
    //修改手机号
    model->setQuery(QString("update student set phone = '%1' where id = '%2'").arg(ui->phonelineEdit_3->text(),id));
    if(model->submit())
    {
        QMessageBox::warning(this,"添加数据","修改成功！");
    }
    else
    {
        QMessageBox::warning(this,"tableModel",tr("数据库错误:%1").arg(model->lastError().text()));//错误提示
    }

    ui->phonelineEdit_3->clear();

}

void studentMainWindow::on_pushButton_5_clicked()
{
    //修改密码
    model->setQuery(QString("update users set password = '%1' where id = '%2' and isAdmin = 0").arg(ui->lineEdit_2->text(),id));
    if(model->submit())
    {
        QMessageBox::warning(this,"添加数据","修改成功！");
    }
    else
    {
        QMessageBox::warning(this,"tableModel",tr("数据库错误:%1").arg(model->lastError().text()));//错误提示
    }
    ui->lineEdit_2->clear();
}
