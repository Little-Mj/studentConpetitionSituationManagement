#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQueryModel>
#include "addstudentdlg.h"
#include "addcompetitiondlg.h"
#include "addcomstudlg.h"
#include <QTableView>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化表名
    student  = "\"student\"";
    competition = "\"competition\"";
    competition_situation = "\"competition_situation\"";

    //初始化model
    model = new QSqlTableModel(this);
    on_stuRadioButton_clicked(1);//默认先输出学生信息
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();//设置自动缩放
}

void MainWindow::student_Search()
{
    //学生信息查询

    QString attribute;//属性名
    QString curAtr;//当前属性名
    if(ui->comboBox->currentIndex()==0)
        attribute="id";
    if(ui->comboBox->currentIndex()==1)
        attribute="name";
    if(ui->comboBox->currentIndex()==2)
        attribute="age";
    if(ui->comboBox->currentIndex()==3)
        attribute="major";
    if(ui->comboBox->currentIndex()==4)
        attribute="class";
    if(ui->comboBox->currentIndex()==5)
        attribute="phone";
    curAtr = ui->lineEdit->text();
    model->setFilter(QString("%1='%2'").arg(attribute,curAtr));
    if(model->rowCount()==0)
    {
        model->select();//恢复tableview
        QMessageBox::warning(this,"数据查询","未查询到相应数据");
    }
    //ui->lineEdit->setText(attribute);
}

void MainWindow::competition_Search()
{
    //学生信息查询
    QString attribute;//属性名
    QString curAtr;//当前属性名

    if(ui->comboBox->currentIndex()==0)
        attribute="id";
    if(ui->comboBox->currentIndex()==1)
        attribute="name";
    if(ui->comboBox->currentIndex()==2)
        attribute="degree";
    if(ui->comboBox->currentIndex()==3)
        attribute="quality";

    curAtr = ui->lineEdit->text();
    model->setFilter(QString("%1='%2'").arg(attribute,curAtr));
    if(model->rowCount()==0)
    {
        model->select();//恢复tableview
        QMessageBox::warning(this,"数据查询","未查询到相应数据");
    }
    //ui->lineEdit->setText(attribute);
}

void MainWindow::competionSituation_Search()
{
    //学生信息查询
    QString attribute;//属性名
    QString curAtr;//当前属性名

    if(ui->comboBox->currentIndex()==0)
        attribute="student_id";
    if(ui->comboBox->currentIndex()==1)
        attribute="competition_id";
    if(ui->comboBox->currentIndex()==2)
        attribute="grade";
    if(ui->comboBox->currentIndex()==3)
        attribute="time";

    curAtr = ui->lineEdit->text();
    model->setFilter(QString("%1='%2'").arg(attribute,curAtr));
    if(model->rowCount()==0)
    {
        model->select();//恢复tableview
        QMessageBox::warning(this,"数据查询","未查询到相应数据");
    }
    //ui->lineEdit->setText(attribute);
}

void MainWindow::setTable_student()
{
    //学生信息管理--选择学生表输出
    model->setTable(student);
    model->select();
    QStringList tables;
    tables <<"学号"<<"姓名"<<"年龄"<<"性别"<<"专业"<<"班级"<<"学院"<<"电话号码";
    for(int i=0;i<tables.count();i++)
        model->setHeaderData(i,Qt::Horizontal,tables[i]);
    //ui->tableView->setModel(model);
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();//设置自动缩放

}

void MainWindow::setTable_competition()
{
    //竞赛信息管理--选择表输出
    model->setTable(competition);
    model->select();
    QStringList tables;
    tables <<"竞赛代码"<<"竞赛名称"<<"竞赛级别"<<"竞赛类别";
    for(int i=0;i<tables.count();i++)
        model->setHeaderData(i,Qt::Horizontal,tables[i]);
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();//设置自动缩放
}

void MainWindow::setTable_competionSituation()
{



    //设置获奖情况表
    model->setTable(competition_situation);
    QStringList tables;
    tables <<"学生学号"<<"竞赛代码"<<"获奖情况"<<"获奖时间";
    model->select();
    for(int i=0;i<tables.count();i++)
        model->setHeaderData(i,Qt::Horizontal,tables[i]);
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();//设置自动缩放

}

void MainWindow::show_competition_situation()
{
    QSqlQueryModel *query = new QSqlQueryModel;
    query->setQuery("select * from competition_situation");
    QTableView *view = new QTableView;
    view->setModel(query);
    view->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_stuRadioButton_clicked(bool checked)
{
    setTable_student();//设置学生表输出

    //设置combox
    ui->comboBox->clear();
    ui->sortComboBox_2->clear();
    QStringList strlist;
    strlist<<"学号"<<"姓名"<<"年龄"<<"专业"<<"班级"<<"电话号码";
    ui->comboBox->addItems(strlist);
    ui->sortComboBox_2->addItems(strlist);
}

void MainWindow::on_comRadioButton_clicked(bool checked)
{
    //设置竞赛表
    setTable_competition();

    ui->comboBox->clear();
    ui->sortComboBox_2->clear();
    QStringList strlist;
    strlist<<"代码"<<"名称"<<"级别"<<"性质";
    ui->comboBox->addItems(strlist);
    ui->sortComboBox_2->addItems(strlist);
}

void MainWindow::on_pushButton_13_clicked()
{
    if(ui->stuRadioButton->isChecked())
        setTable_student();
    else if (ui->comRadioButton->isChecked())
        setTable_competition();
    else
        setTable_competionSituation();
}

void MainWindow::on_pushButton_9_clicked()
{
    //提交修改
    model->database().transaction();//开始事物操作
    if(model->submitAll())
    {
        model->database().commit();//提交
        QMessageBox::warning(this,"tableModel","修改成功");//提示
    }
    else
    {
        model->database().rollback();
        QMessageBox::warning(this,"tableModel",tr("数据库错误:%1").arg(model->lastError().text()));//错误提示
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    model->revertAll();
    QMessageBox::warning(this,"tableModel","撤销成功");//提示
}

void MainWindow::on_pushButton_11_clicked()
{
    int curRow = ui->tableView->currentIndex().row();

    //删除该行
    model->removeRow(curRow);

    int ok = QMessageBox::warning(this,"删除当前行！","你确定删除当前行吗？",QMessageBox::Yes,QMessageBox::No);
    if(ok==QMessageBox::No)
    {
        model->revertAll();//不删除,撤销
    }
    else
    {
        model->submitAll();
    }
}

void MainWindow::on_radioButton_clicked(bool checked)
{
    //设置获奖表
    setTable_competionSituation();

    //设置combox选项
    ui->comboBox->clear();
    ui->sortComboBox_2->clear();
    QStringList strlist;
    strlist<<"学生学号"<<"竞赛代码"<<"奖项"<<"时间";
    ui->comboBox->addItems(strlist);
    ui->sortComboBox_2->addItems(strlist);
}

void MainWindow::on_pushButton_14_clicked()
{
    //三合一查询
    if(ui->stuRadioButton->isChecked())
        student_Search();
    else if(ui->comRadioButton->isChecked())
        competition_Search();
    else
        competionSituation_Search();

}

void MainWindow::on_pushButton_12_clicked()
{
    if(ui->stuRadioButton->isChecked())
    {
        addstudentdlg stu;
        stu.exec();
    }
    else if(ui->comRadioButton->isChecked())
    {
        addcompetitiondlg com;
        com.exec();
    }
    else
    {
        addcomstudlg comStu;
        comStu.exec();
    }
}



void MainWindow::on_pushButton_clicked()
{
    model->sort(ui->sortComboBox_2->currentIndex(),Qt::AscendingOrder);
    model->select();
}

void MainWindow::on_pushButton_2_clicked()
{
    model->sort(ui->sortComboBox_2->currentIndex(),Qt::DescendingOrder);
    model->select();
}

void MainWindow::on_pushButton_3_clicked()
{
    //查询详细获奖信息
    //show_competition_situation();
    QSqlQueryModel *query = new QSqlQueryModel;
    //对student，competition,competition_stutation 表进行联合查询
    query->setQuery("select student.id,student.name,student.major,"
                    " competition.name,competition.degree,"
                    " competition_situation.grade,competition_situation.time "
                    "   from student,competition,competition_situation "
                    "       where student.id=competition_situation.student_id and"
                    "               competition_situation.competition_id = competition.id");
    QStringList tables;
    //设置数据表头
    tables <<"学生学号"<<"学生姓名"<<"专业"<<"竞赛名称"<<"竞赛级别"<<"获奖情况"<<"获奖时间";
    for(int i=0;i<tables.count();i++)
        query->setHeaderData(i,Qt::Horizontal,tables[i]);
    QTableView *view = new QTableView;
    view->setModel(query);
    view->show();
}
