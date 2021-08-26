#ifndef STUDENTDIALOG_H
#define STUDENTDIALOG_H

#include <QDialog>
#include <QSqlQueryModel>
namespace Ui {
class studentDialog;
}

class studentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit studentDialog(QString student_id,QWidget *parent = 0);
    ~studentDialog();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::studentDialog *ui;
    QSqlQueryModel *model;
    QString id;
};

#endif // STUDENTDIALOG_H
