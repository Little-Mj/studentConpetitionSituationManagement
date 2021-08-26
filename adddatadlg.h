#ifndef ADDDATADLG_H
#define ADDDATADLG_H

#include <QDialog>

namespace Ui {
class addDataDlg;
}

class addDataDlg : public QDialog
{
    Q_OBJECT

public:
    explicit addDataDlg(QWidget *parent = 0, QString *model);
    ~addDataDlg();

private:
    Ui::addDataDlg *ui;
};

#endif // ADDDATADLG_H
