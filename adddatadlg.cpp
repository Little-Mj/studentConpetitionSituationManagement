#include "adddatadlg.h"
#include "ui_adddatadlg.h"

addDataDlg::addDataDlg(QWidget *parent,, QString *model) :
    QDialog(parent),
    ui(new Ui::addDataDlg)
{
    ui->setupUi(this);

}

addDataDlg::~addDataDlg()
{
    delete ui;
}
