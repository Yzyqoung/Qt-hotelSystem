#include "changepassword.h"
#include "ui_changepassword.h"

ChangePassword::ChangePassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangePassword)
{
    ui->setupUi(this);
    ui->UserNum->setAttribute(Qt::WA_InputMethodEnabled,false);//设置账户框输入时，输入法自动转化为英文
    ui->UserPwd->setAttribute(Qt::WA_InputMethodEnabled,false);//设置密码框输入时，输入法自动转化为英文
}

ChangePassword::~ChangePassword()
{
    delete ui;
}
/*
 *函数功能：确认按钮点击事件，进行密码修改
 *输入参数：
 *说明：检查是否有空白项，无空白项判断两次密码是否相同，
 *     判断账号是否存在，判断账号和用户名是否匹配，更改新密码
*/
void ChangePassword::on_btnOk_clicked()
{
    QString UserName = ui->UserName->text().trimmed();
    QString UserNum = ui->UserNum->text().trimmed();
    QString UserPwd = ui->UserPwd->text().trimmed();
    QString UserRePwd = ui->UserRePwd->text().trimmed();
    if(UserName.isEmpty()||UserNum.isEmpty()||UserPwd.isEmpty()||UserRePwd.isEmpty())
    {
       QMessageBox::information(this,"提示","请补全信息，不能为空！");
    }
    else if(UserPwd != UserRePwd)
    {
        QMessageBox::information(this,"提示","两次密码不相同，请重新输入");
    }
    else
    {
        QSqlTableModel model;
        model.setTable("user");
        model.setFilter(QObject::tr("user_num = '%1'")
                        .arg(UserNum));
        model.select();
        if(model.rowCount() != 1){
            QMessageBox::information(this,"提示","该账号不存在！");
            ui->UserNum->clear();
        }else{
            QSqlQuery query;
            QString value;
            query.prepare("select * from user where user_num = :UserNum");
            query.bindValue(":UserNum",UserNum);
            query.exec();
            QSqlRecord rec = query.record();
            while(query.next())
            {
                int username = rec.indexOf("user_name");
                value = query.value(username).toString();
                qDebug()<<value;
            }
            if(value != UserName)
            {
                QMessageBox::information(this,"提示","用户名和账号不匹配");
                ui->UserNum->clear();
                ui->UserName->clear();
            }else {
                QSqlQuery query;
                QString sql = "update user set user_pwd = :UserPwd where user_num = :UserNum";
                query.prepare(sql);
                query.bindValue(":UserPwd",UserPwd);
                query.bindValue(":UserNum",UserNum);
                query.setForwardOnly(true);
                query.exec();
                QMessageBox::information(this,"提示","修改密码成功");
            }
        }
    }
}

void ChangePassword::on_btnCancel_clicked()
{
    ui->UserName->clear();
    ui->UserNum->clear();
    ui->UserPwd->clear();
    ui->UserRePwd->clear();
}
