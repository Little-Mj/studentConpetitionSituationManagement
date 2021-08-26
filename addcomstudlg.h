#ifndef ADDCOMSTUDLG_H
#define ADDCOMSTUDLG_H

#include <QDialog>
#include<QSqlTableModel>
namespace Ui {
class addcomstudlg;
}

class addcomstudlg : public QDialog
{
    Q_OBJECT

public:
    explicit addcomstudlg(QWidget *parent = 0);
    ~addcomstudlg();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::addcomstudlg *ui;
    QSqlTableModel *model_stu;
    QSqlTableModel *model_com;
    QSqlTableModel *model_comStu;
};

#endif // ADDCOMSTUDLG_H
