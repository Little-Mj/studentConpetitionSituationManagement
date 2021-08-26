#ifndef SQLCONNECTION_H
#define SQLCONNECTION_H
#include<QSqlDatabase>
#include<QSqlQuery>
static bool createConnection()
{
    //创建一个Sqlite连接
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("my.db");
    if(!db.open())
    {

        return false;
    }
    QSqlQuery qurry;
//    qurry.exec("drop table users");
//    qurry.exec("create table users (id char(11) primary key,password varchar(20),isAdmin int)");
//    qurry.exec("insert into users values('admin','admin',1),('1','1',0)");
    //    qurry.exec("drop table competition_situation");
    //    qurry.exec("create table competition_situation (student_id int,"
    //               "competition_id int,"
    //               "grade varchar(20) not null,time varchar(20) not null,"
    //               "primary key(student_id,competition_id),"
    //               "FOREIGN KEY(student_id) REFERENCES student(id))");
//    qurry.exec("drop table student");
//    qurry.exec("create table student (id int primary key,"
//               "name varchar(50),age int,sex char(2),major varchar(50),class varchar(50),college varchar(30),phone char(11))");
    //    qurry.exec("create table competition (id int primary key,name varchar(50),degree varchar(20),quality varchar(20))");
    return true;
}


#endif // SQLCONNECTION_H
