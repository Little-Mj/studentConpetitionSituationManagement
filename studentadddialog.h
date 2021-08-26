#ifndef STUDENTADDDIALOG_H
#define STUDENTADDDIALOG_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class studentAddDialog;
}

class studentAddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit studentAddDialog(QWidget *parent = 0);
    ~studentAddDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::studentAddDialog *ui;
private:
    QSqlTableModel *model;
};

#endif // STUDENTADDDIALOG_H
