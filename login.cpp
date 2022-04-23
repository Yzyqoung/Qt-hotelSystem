#include "login.h"
#include "ui_login.h"

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

void Login::on_btnLogin_clicked()
{

}



void Login::on_btn_close_clicked()
{
    close();
}

void Login::on_btn_min_clicked()
{
    showMinimized();
}
