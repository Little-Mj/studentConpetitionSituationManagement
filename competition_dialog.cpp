#include "competition_dialog.h"
#include "ui_competition_dialog.h"

competition_dialog::competition_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::competition_dialog)
{
    ui->setupUi(this);

    model = new QSqlTableModel(this);
    model->setTable("competition");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);//对所有修改都会进行缓存，直到submitAll()或者reverAll()
    model->select();

    ui->tableView->setModel(model);
}

competition_dialog::~competition_dialog()
{
    delete ui;
}

void competition_dialog::on_pushButton_7_clicked()
{
    model->setTable("competition");
    model->select();

}
