#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void student_Search();
    void competition_Search();
    void competionSituation_Search();
    void setTable_student();
    void setTable_competition();
    void setTable_competionSituation();
    void show_competition_situation();
    ~MainWindow();

private slots:


    void on_stuRadioButton_clicked(bool checked);

    void on_comRadioButton_clicked(bool checked);

    void on_pushButton_13_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();


    void on_radioButton_clicked(bool checked);

    void on_pushButton_14_clicked();

    void on_pushButton_12_clicked();


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;
    QString student;
    QString competition;
    QString competition_situation;
};

#endif // MAINWINDOW_H
