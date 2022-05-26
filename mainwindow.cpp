#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

    //所有界面实例化
    fDP = new frmDbPage(this);
    unpayfDP = new unpayfrmdbpage(this);
    payfDP = new payfrmdbpage(this);
    ctmfDP = new customerinfo(this);
    backsql = new backupssql(this);
    proManage = new promanage(this);
    //所有界面添加进入stackedWidget
    ui->stackedWidget->addWidget(fDP);              //Index=2
    ui->stackedWidget->addWidget(unpayfDP);         //Index=3
    ui->stackedWidget->addWidget(payfDP);           //Index=4
    ui->stackedWidget->addWidget(ctmfDP);           //Index=5
    ui->stackedWidget->addWidget(backsql);          //Index=6
    ui->stackedWidget->addWidget(proManage);         //Index=7
    //设置stackedWidget界面对齐
    ui->stackedWidget->widget(2)->layout()->setContentsMargins(0,0,0,1);
    ui->stackedWidget->widget(3)->layout()->setContentsMargins(0,0,0,1);
    ui->stackedWidget->widget(4)->layout()->setContentsMargins(0,0,0,1);
    ui->stackedWidget->widget(5)->layout()->setContentsMargins(0,0,0,1);
    ui->stackedWidget->widget(6)->layout()->setContentsMargins(0,0,0,1);
    ui->stackedWidget->widget(7)->layout()->setContentsMargins(0,0,0,1);

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
