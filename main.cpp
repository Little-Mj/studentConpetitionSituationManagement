#include "mainwindow.h"
#include <QApplication>
#include "logindialog.h"
#include "sqlconnection.h"
#include "studentdialog.h"
#include "studentmainwindow.h"

int main(int argc, char *argv[])
{
    QString id;//登录学生账号时存储账号
    QString id1=id;//用于判断id是否被修改
    QApplication a(argc, argv);

    //创建数据库链接
    if(createConnection()==false)
        return 1;

    // 登录窗口
    LoginDialog log(&id,0);
    if(log.exec() == QDialog::Accepted)
    {
        if(id1!=id)
        {
            //学生界面
            studentMainWindow stu(id,0);
            stu.show();
            return a.exec();
        }
        else
        {
            //管理员界面
            MainWindow w;
            w.show();
            return a.exec();
        }

    }
    else
    {
        return 1;
    }
    // return a.exec();
}
