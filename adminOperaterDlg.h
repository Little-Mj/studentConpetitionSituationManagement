#ifndef STUDENTDIALOG_H
#define STUDENTDIALOG_H

#include <QDialog>
#include <QSqlTableModel>
namespace Ui {
class adminOperaterDlg;
}

class adminOperaterDlg : public QDialog
{
    Q_OBJECT

public:
    explicit adminOperaterDlg(QWidget *parent = 0);
    ~adminOperaterDlg();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::adminOperaterDlg *ui;
private:
    QSqlTableModel *model;
};

#endif // STUDENTDIALOG_H
