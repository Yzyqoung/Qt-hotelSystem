/***************************************************************
 *文件名称：数据库备份功能
 *简要描述：异步操作，进度条动画和后台数据库备份操作分布进行。
 * 因为time定时器运行时，会导致ui无响应锁死、故使用子线程实现该功能。
 *
 *当前版本：V1.0
 *作者：Young
 *创作日期：2022/5/20
 *说明：Email:578706463@qq.com
*****************************************************************/
#include "backupssql.h"
#include "ui_backupssql.h"
#include "mainwindow.h"
#include <QProcess>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QTime>
backupssql::backupssql(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::backupssql)
{
    ui->setupUi(this);
    this->InitForm();
}

backupssql::~backupssql()
{
    delete ui;
}

void backupssql::InitForm()
{
    ui->labelBackInfo->setText(tr(" "));//初始化备份提示信息
    ui->pbnOk->setToolTip(tr("确认备份"));

    ui->progressBar->setRange(0,5000 - 1);
    ui->progressBar->setValue(0);

    connect(this,SIGNAL(updatestart()),this->parentWidget(),SLOT(setAllEnableFalse()));
    connect(this,SIGNAL(updatefinish()),this->parentWidget(),SLOT(setAllEnableTrue()));
}

/*
 *函数功能：备份数据库
*/
void backupssql::on_pbnOk_clicked()
{
    emit updatestart();
    QString Cmd = QString("C:\\Program Files\\MySQL\\MySQL Server 8.0\\bin\\mysqldump.exe");
    QStringList argument;
    argument<<"--add-drop-table"<<"-uroot"<<"-p123456"<<"hotel";
    QString Path = ui->lineEdit->text();
    QProcess *poc=new QProcess;
    poc->setStandardOutputFile(Path);
    poc->start(Cmd,argument);

    for(int i = 0;i<5000;i++)
    {

        ui->labelBackInfo->setText(tr("正在备份……"));
        if(i%1000==0&&i!=0) //延时，防止数据库过大，在后台备份
        {
            QTime time = QTime::currentTime().addSecs(1);
            while(QTime::currentTime()<time)
            {
                 ui->progressBar->setValue(i);
            }
        }else{
            for(int j = 0;j<2000;j++)
            {
                ui->progressBar->setValue(i);
            }
        }

    }
    emit updatefinish();
    ui->labelBackInfo->setText(tr("备份完成"));
    ui->pbnOk->setToolTip(tr("已经备份完成"));
}

/*
 *获取当前要备份数据库的目录
*/
void backupssql::on_pbnSearch_clicked()
{
    QString defaultname = "back_hotel.sql";
    //选择路径
    QString filename = QFileDialog::getSaveFileName(this,tr("保存数据库"),"",
                                                    tr("sql文件(*.sql);;txt文件(*.txt);;"));
    if(filename.isEmpty())
    {
        filename = defaultname;
    }
    ui->lineEdit->setText(filename);

}

void backupssql::on_lineEdit_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    ui->progressBar->setValue(0);
    ui->pbnOk->setToolTip(tr(""));
}





