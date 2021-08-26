#include "addcompetitiondlg.h"
#include "ui_addcompetitiondlg.h"
#include <QMessageBox>
#include<QSqlError>
addcompetitiondlg::addcompetitiondlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addcompetitiondlg)
{
    ui->setupUi(this);

    model = new QSqlTableModel();
    model->setTable("competition");
}

addcompetitiondlg::~addcompetitiondlg()
{
    delete ui;
}

void addcompetitiondlg::on_pushButton_2_clicked()
{
    close();
}

void addcompetitiondlg::on_pushButton_clicked()
{
    if(ui->idLineEdit->text().isEmpty()||ui->nameLineEdit_2->text().isEmpty())
        QMessageBox::warning(this,"数据缺失","请填写完整！");
    else
    {
        int curRow = model->rowCount();
        model->insertRow(curRow);
        model->setData(model->index(curRow,0),ui->idLineEdit->text());
        model->setData(model->index(curRow,1),ui->nameLineEdit_2->text());
        model->setData(model->index(curRow,2),ui->degreeComboBox->currentText());
        model->setData(model->index(curRow,3),ui->qualityComboBox_2->currentText());
        if(model->submitAll())
        {
            QMessageBox::warning(this,"数据添加","数据添加成功");
        }
        else
        {
            QMessageBox::warning(this,"tableModel",tr("数据库错误:%1").arg(model->lastError().text()));//错误提示
        }
    }
    ui->idLineEdit->clear();
    ui->nameLineEdit_2->clear();
    ui->idLineEdit->setFocus();
}
