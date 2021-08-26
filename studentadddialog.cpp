#include "studentadddialog.h"
#include "ui_studentadddialog.h"

studentAddDialog::studentAddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studentAddDialog)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this);
    model->setTable("student");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    //不显示第二列
    //model->removeColumn(1);

    //查询整张表
    model->select();
    ui->tableView->setModel(model);
}

studentAddDialog::~studentAddDialog()
{
    delete ui;
}

void studentAddDialog::on_pushButton_clicked()
{
    QString no = ui->noLineEdit->text();
    QString name = ui->nameLineEdit_2->text();
    QString age = ui->ageLineEdit_3->text();
    QString major=ui->majorLineEdit_4->text();
    QString student_class= ui->classLineEdit_5->text();
    QString phone=ui->phoneLineEdit_6->text();
    //获取表的行数
    int row = model->rowCount();
    model->insertRow(row);
    model->setData(model->index(row,0),no);
    model->setData(model->index(row,1),name);
    model->setData(model->index(row,2),age);
    model->setData(model->index(row,3),major);
    model->setData(model->index(row,4),student_class);
    model->setData(model->index(row,4),phone);
    model->submitAll();
}
