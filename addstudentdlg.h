#ifndef ADDSTUDENTDLG_H
#define ADDSTUDENTDLG_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class addstudentdlg;
}

class addstudentdlg : public QDialog
{
    Q_OBJECT

public:
    explicit addstudentdlg(QWidget *parent = 0);
    ~addstudentdlg();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::addstudentdlg *ui;
    QSqlTableModel *model_stu;
    QSqlTableModel *model_user;
};

#endif // ADDSTUDENTDLG_H
