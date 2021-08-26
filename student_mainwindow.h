#ifndef STUDENT_MAINWINDOW_H
#define STUDENT_MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
namespace Ui {
class student_MainWindow;
}

class student_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit student_MainWindow(QWidget *parent = 0);
    ~student_MainWindow();

private:
    Ui::student_MainWindow *ui;
private:
    QSqlTableModel *model;
};

#endif // STUDENT_MAINWINDOW_H
