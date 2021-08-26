#ifndef STUDENTMAINWINDOW_H
#define STUDENTMAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
namespace Ui {
class studentMainWindow;
}

class studentMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit studentMainWindow(QString student_id,QWidget *parent = 0);
    ~studentMainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::studentMainWindow *ui;
    QSqlQueryModel *model;
    QString id;//用于指向存放学生登录账号信息的内存
};

#endif // STUDENTMAINWINDOW_H
