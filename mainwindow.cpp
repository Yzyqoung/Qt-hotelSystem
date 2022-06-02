#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showFullScreen();//直接全屏展示
    initwidget();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initwidget()
{
    //窗体边框隐藏
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);
    this->setMinimumSize(1000,600);

    ui->label_CurrentUser->setText("当前用户: " + SaveLoginUser::user_name + " 【"+ SaveLoginUser::user_type + "】");
    ui->label_CompanyName->setText("公司: 惠州学院-计算机与工程学院");
    ui->label_CurrentTime->setText(QDateTime::currentDateTime().toString(tr("当前时间: yyyy年MM月dd日 dddd HH:mm:ss ")));

    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(showCurrentTime()));
    timer->start(1000);

    //所有界面实例化
    fDP = new frmDbPage(this);
    unpayfDP = new unpayfrmdbpage(this);
    payfDP = new payfrmdbpage(this);
    ctmfDP = new customerinfo(this);
    backsql = new backupssql(this);
    proManage = new promanage(this);
    account = new AccountAuthorization(this);
    changepwd = new ChangePassword(this);
    //所有界面添加进入stackedWidget
    ui->stackedWidget->addWidget(fDP);              //Index=2
    ui->stackedWidget->addWidget(unpayfDP);         //Index=3
    ui->stackedWidget->addWidget(payfDP);           //Index=4
    ui->stackedWidget->addWidget(ctmfDP);           //Index=5
    ui->stackedWidget->addWidget(backsql);          //Index=6
    ui->stackedWidget->addWidget(proManage);        //Index=7
    ui->stackedWidget->addWidget(account);          //Index=8
    ui->stackedWidget->addWidget(changepwd);        //Index=9

    //设置stackedWidget界面对齐
    ui->stackedWidget->widget(2)->layout()->setContentsMargins(0,0,0,1);
    ui->stackedWidget->widget(3)->layout()->setContentsMargins(0,0,0,1);
    ui->stackedWidget->widget(4)->layout()->setContentsMargins(0,0,0,1);
    ui->stackedWidget->widget(5)->layout()->setContentsMargins(0,0,0,1);
    ui->stackedWidget->widget(6)->layout()->setContentsMargins(0,0,0,1);
    ui->stackedWidget->widget(7)->layout()->setContentsMargins(0,0,0,1);
    ui->stackedWidget->widget(8)->layout()->setContentsMargins(0,0,0,1);
    ui->stackedWidget->widget(9)->layout()->setContentsMargins(0,0,0,1);

}

void MainWindow::on_btnMenu_Close_clicked()
{
    this->close();
}


void MainWindow::on_btn_allorder_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_btn_unpayorder_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_btn_payorder_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_btn_custormerinfo_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_btn_copy_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::setAllEnableTrue()
{
    ui->toolBox->setEnabled(true);
    qDebug()<<"设置toolbox可用";
}

void MainWindow::setAllEnableFalse()
{
    ui->toolBox->setEnabled(false);
    qDebug()<<"设置toolbox不可用";
}

void MainWindow::on_btn_center_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_btn_register_clicked()
{
    if(SaveLoginUser::user_type!="管理员")
    {
        QMessageBox::warning(this,"警告","非管理员无法使用该功能");
    }else{
        ui->stackedWidget->setCurrentIndex(8);
    }
}

void MainWindow::on_btn_changepwd_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}


int day = 0;
int hour = 0;
int minute = 0;
int second = 0;
/*
 *函数功能：显示系统时间
 *输入参数：无
 *输出参数：无
 *返回值：无
 *说明：显示时间的槽函数，用来显示当前系统的时间和软件运行的时间
*/
void MainWindow::showCurrentTime()
{
    second++;
    if(second == 60)
    {
        minute++;
        second = 0;
    }
    if(minute == 60)
    {
        hour++;
        minute = 0;
    }
    if(hour == 24)
    {
        day++;
        hour = 0;
    }
    ui->label_CurrentTime->setText(QDateTime::currentDateTime().toString(tr("当前时间:yyyy年MM月dd日 dddd HH:mm:ss")));
    ui->label_SoftTime->setText(QString(tr("已运行:%1天%2时%3分%4秒")).arg(day).arg(hour).arg(minute).arg(second));
}




