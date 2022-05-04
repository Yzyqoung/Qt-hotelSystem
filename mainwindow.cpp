#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPalette palette;
    //设置主窗口背景颜色
    palette.setColor(QPalette::Window,QColor(135,206,255));
    this->setPalette(palette);

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
    //
    //location = this->geometry();


    fDP = new frmDbPage(this);
    ui->stackedWidget->addWidget(fDP);
}

void MainWindow::on_btn_allorder_clicked()
{
    ui->stackedWidget->setCurrentWidget(fDP);
}

void MainWindow::on_btnMenu_Close_clicked()
{
    this->close();
}
