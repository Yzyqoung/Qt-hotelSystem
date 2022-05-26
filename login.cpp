/*登录界面*/
#include "login.h"
#include "ui_login.h"
#include <QSqlRecord>
#include <QPainter>
#include <QMouseEvent>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    //去窗口边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    ui->txtUserNum->setAttribute(Qt::WA_InputMethodEnabled,false);//设置账户框输入时，输入法自动转化为英文
    ui->txtUserPwd->setAttribute(Qt::WA_InputMethodEnabled,false);//设置密码框输入时，输入法自动转化为英文

}

Login::~Login()
{
    delete ui;
}

/*
 *函数功能：暂存当前登录用户的信息
 *输入参数：
 *说明：
*/
void Login::saveLoginUser(QString user_num)
{
    QSqlQuery query;
    query.prepare("select * from user where user_num = :user_num");
    query.bindValue(":user_num",user_num);
    query.exec();
    QSqlRecord rec = query.record();
    while(query.next())
    {
        int usernum = rec.indexOf("user_num");
        int username = rec.indexOf("user_name");
        int usertype = rec.indexOf("user_type");
        QString value1 = query.value(usernum).toString();
        QString value2 = query.value(username).toString();
        QString value3 = query.value(usertype).toString();
        save.setUserFormation(value1,value2,value3);
    }
}

/*
 *函数功能：保存当前用户名和密码
 *输入参数：数据表名，用户名，用户密码
 *说明：在插入时总会先判断，若有数值，进行删除在插入
*/
void Login::WriteCurrentUser(QString usernum,QString userpwd)
{
    qDebug()<<"方法使用成功";
    if(FindTableIsEmpty("currentuser") != 0)
    {
        //deldete table
        this->DeleteTableContent("currentuser");
        qDebug() <<"delete table ok";
        WriteCurrentUser(usernum,userpwd);
    }
    else
    {
        QSqlQuery query;
        QString sql = "insert into currentuser(user_num,user_pwd) values(:user_num,:user_pwd)"; //添加信息数据库语句
        query.prepare(sql);
        query.bindValue(":user_num",usernum);
        query.bindValue(":user_pwd",userpwd);
        query.setForwardOnly(true);
        query.exec();
        qDebug() <<"insert into table ok";
    }
}

/*
 *函数功能：检查某个表是否空表
 *输入参数：表名称
 *返回值：表中的字段值，根据返回值可以判断是否为空
*/
int Login::FindTableIsEmpty(QString tablename)
{
    int value = 0;
    QString sql = "select count(*) from "+tablename+";"; //查询数据库语句
    qDebug() <<sql;
    QSqlQuery query;
    query.exec(sql);
    if(query.next())
    {
        value = query.value(0).toInt();
        qDebug() <<"in "<<value;
    }
    qDebug()<<"out "<<value;
    return value;
}

/*
 *函数功能：删除表中的内容
 *
*/
void Login::DeleteTableContent(QString tablename)
{
    QString sql ="delete from "+tablename+";"; //删除数据库语句
    qDebug() <<sql;
    QSqlQuery query;
    query.exec(sql);
}

void Login::on_btnLogin_clicked() // 登录按钮
{
    QString UserNum = ui->txtUserNum->text().trimmed();
    QString UserPwd = ui->txtUserPwd->text().trimmed();
    if(UserPwd.isEmpty()||UserNum.isEmpty())
    {
       QMessageBox::information(this,"提示","账号或密码不能为空");
    }
    else
    {
        QSqlTableModel model;
        model.setTable("user");
        model.setFilter(QObject::tr("user_num = '%1' and user_pwd ='%2'")
                        .arg(UserNum).arg(UserPwd));
        model.select();
        if(model.rowCount() == 1)
        {
            WriteCurrentUser(UserNum,UserPwd);
            saveLoginUser(UserNum);
            this->close();//关闭父页面
            MainWindow *m = new MainWindow();//定义子页面的一个类
            m->show();//界面跳转
        }
        else
        {
            QMessageBox::information(this,"提示","账号或密码错误请重新输入！");
            ui->txtUserPwd->clear();
            ui->txtUserPwd->setFocus();
        }
    }
}


void Login::on_btn_close_clicked()//关闭窗口按钮
{
    close();
}

void Login::on_btn_min_clicked() //缩小窗口按钮
{
    showMinimized();
}

void Login::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        //求坐标差值
        //当前点击坐标-窗口左上角坐标
        p = e->globalPos() - this->frameGeometry().topLeft();
    }
}

void Login::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons() & Qt::LeftButton)
    {
        //移到左上角
        move(e->globalPos() - p);
    }

}


