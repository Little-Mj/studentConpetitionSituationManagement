#include "student_mainwindow.h"
#include "ui_student_mainwindow.h"

student_MainWindow::student_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::student_MainWindow)
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

    //设置视图不可编辑
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

student_MainWindow::~student_MainWindow()
{
    delete ui;
}
