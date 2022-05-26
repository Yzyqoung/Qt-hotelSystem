/*店长授权店员账号界面*/
#include "accountauthorization.h"
#include "ui_accountauthorization.h"
#include <QMessageBox>
AccountAuthorization::AccountAuthorization(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountAuthorization)
{
    ui->setupUi(this);
}

AccountAuthorization::~AccountAuthorization()
{
    delete ui;
}

/*
 *函数功能：重置按钮
 *输入参数：
 *说明：对所有输入框进行重置清空
*/
void AccountAuthorization::on_btnCancel_clicked()
{
    ui->UserName->clear();
    ui->UserNum->clear();
    ui->UserPwd->clear();
    ui->UserRePwd->clear();
}
/*
 *函数功能：注册按钮
 *输入参数：无
 *说明：识别信息判断是否可以注册成功
*/
void AccountAuthorization::on_btnOk_clicked()
{
    QString UserName = ui->UserName->text().trimmed();
    QString UserNum = ui->UserNum->text().trimmed();
    QString UserPwd = ui->UserPwd->text().trimmed();
    QString UserRePwd = ui->UserRePwd->text().trimmed();
    QString UserType = ui->comboBox->currentText();
    if(UserName==""||UserNum==""||UserPwd==""||UserRePwd==""){
        QMessageBox::information(this,"提示","请补全注册信息！");
    }else if(UserPwd!=UserRePwd){
        QMessageBox::information(this,"提示","两次密码不一致，请重新输入！");
        ui->UserPwd->clear();
        ui->UserRePwd->clear();
    }else {
        QSqlTableModel model;
        model.setTable("user");
        model.setFilter(QObject::tr("user_num = '%1'")
                        .arg(UserNum));
        model.select();
        if(model.rowCount() == 1){
            QMessageBox::information(this,"提示","该账号已存在请重新注册！");
            ui->UserNum->clear();
        }else {
            QSqlQuery query;
            QString sql = "insert into user(user_num,user_pwd,user_name,user_type) VALUES (:user_num,:user_pwd,:user_name,:user_type)"; //添加信息数据库语句
            qDebug() <<sql;
            query.prepare(sql);
            query.bindValue(":user_num",UserNum);
            query.bindValue(":user_pwd",UserPwd);
            query.bindValue(":user_name",UserName);
            query.bindValue(":user_type",UserType);
            query.setForwardOnly(true);
            query.exec();
            if(query.prepare(sql)){
                qDebug() <<"insert into table ok";
            }
            else{
                qDebug()<<"insert into table false";
            }
        }
    }
}
