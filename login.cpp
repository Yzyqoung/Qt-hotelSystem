#include "login.h"
#include "ui_login.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDialog>
#include <QDebug>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    //去窗口边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

}

Login::~Login()
{
    delete ui;
}

/*
 *函数功能：保存当前用户名和密码
 *输入参数：数据表名，用户名，用户密码 表名：user_name
 *说明：在插入时总会先判断，若有数值，进行删除在插入
*/
void Login::WriteCurrentUser(QString tablename, QString username,QString userpwd)
{
    if(FindTableIsEmpty("currentuser") != 0)
    {
        //deldete table
        this->DeleteTableContent("currentuser");
        qDebug() <<"deldete table ok";
    }
    else
    {
        QSqlQuery query;
        QString sql = "insert into "+tablename+" values(:UserName,:UserPwd)"; //添加信息数据库语句
        qDebug() <<sql;
        query.prepare(sql);
        query.bindValue(":UserName",username);
        query.bindValue(":UserPwd",userpwd);
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

/*
 *数据库连接
*/
void Login::initsql()
{
    //数据库连接
    db = QSqlDatabase::addDatabase("QMYSQL");   //那种类型的数据库
    db.setHostName("127.0.0.1");    //本机地址
    db.setPort(3306);      //端口号
    db.setDatabaseName("hotel");    //那个数据库
    db.setUserName("root");      //用户名
    db.setPassword("123456");    //密码
    db.open();
    if(!db.open()) //如果数据库打开失败，会弹出一个警告窗口
    {
        QMessageBox::warning(this, "警告", "数据库打开失败!!");
    }
    else
    {
        return;
         //QMessageBox::warning(this, "警告", "数据库开启成功!!");
    }
}

void Login::on_btnLogin_clicked() // 登录按钮
{
    QString UserName = ui->txtUserName->text().trimmed();
    QString UserPwd = ui->txtUserPwd->text().trimmed();
    if(UserPwd.isEmpty()&&UserName.isEmpty())
    {
       QMessageBox::information(this,"提示","账号和密码不能为空");
    }
    else
    {
        QSqlTableModel model;
        model.setTable("user");
        model.setFilter(QObject::tr("user_name = '%1' and user_pwd ='%2'")
                        .arg(UserName).arg(UserPwd));
        model.select();
        qDebug()<<model.select();
        if(model.rowCount() == 1)
        {
//            Myapp::LastLoginter = ui->txtUserName->text();
//            Myapp::CurrentUserName = Myapp::LastLoginter;
//            Myapp::CurrentUserPwd = ui->txtUserPwd->text();
//            Myapp::CurrentUserType = tr("管理员");
//            Myapp::WriteConfig();           //写进配置文件
//            myHelper::MyLoginBlog("logblog","登录","登录系统","管理员");     //写入系统日志
//            qDebug() <<UserName<<""<<UserPwd;
//            QDialog::accept();
            this->close();//关闭父页面
            MainWindow *m = new MainWindow();//定义子页面的一个类
            m->show();//界面跳转
        }
        else
        {
            QMessageBox::information(this,"提示","密码错误请重新输入！");
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
