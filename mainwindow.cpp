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
    fDP = new frmDbPage(this);
    ui->stackedWidget->addWidget(fDP);
}

void MainWindow::on_btn_allorder_clicked()
{
    ui->stackedWidget->setCurrentWidget(fDP);
}
