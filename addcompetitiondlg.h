#ifndef ADDCOMPETITIONDLG_H
#define ADDCOMPETITIONDLG_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class addcompetitiondlg;
}

class addcompetitiondlg : public QDialog
{
    Q_OBJECT

public:
    explicit addcompetitiondlg(QWidget *parent = 0);
    ~addcompetitiondlg();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::addcompetitiondlg *ui;
    QSqlTableModel *model;
};

#endif // ADDCOMPETITIONDLG_H
