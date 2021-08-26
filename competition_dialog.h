#ifndef COMPETITION_DIALOG_H
#define COMPETITION_DIALOG_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class competition_dialog;
}

class competition_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit competition_dialog(QWidget *parent = 0);
    ~competition_dialog();

private slots:
    void on_pushButton_7_clicked();

private:
    Ui::competition_dialog *ui;
    QSqlTableModel *model;
};

#endif // COMPETITION_DIALOG_H
