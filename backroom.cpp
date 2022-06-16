#include "backroom.h"
#include "ui_backroom.h"
#include <QDebug>
backroom::backroom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::backroom)
{
    ui->setupUi(this);
    initbox();
    initform();
    initview();
}

backroom::~backroom()
{
    delete ui;
}

void backroom::initbox(){
    ui->stackedWidget->setCurrentIndex(0);
}

void backroom::initform(){
    columnNames.clear();
    columnWidths.clear();

    tableName = "hotel.order";
    countName = "id";

    columnNames.append("订单号码");
    columnNames.append("客户姓名");
    columnNames.append("身份证号");
    columnNames.append("手机号码");
    columnNames.append("房间号码");
    columnNames.append("入住时间");
    columnNames.append("退房时间");
    columnNames.append("消费金额");
    columnNames.append("操作人员");
    columnNames.append("备注");

    columnWidths.append(80);
    columnWidths.append(80);
    columnWidths.append(120);
    columnWidths.append(80);
    columnWidths.append(80);
    columnWidths.append(120);
    columnWidths.append(120);
    columnWidths.append(80);
    columnWidths.append(80);
    columnWidths.append(120);

    //设置需要显示数据的表格和翻页的按钮
    dbPage = new DbPage(this);
    //设置所有列居中显示
    dbPage->setAllCenter(true);
    dbPage->setControl(ui->tableMain, ui->labPageTotal, ui->labPageCurrent, ui->labRecordsTotal, ui->labRecordsPerpage,
                       ui->labSelectTime, 0, ui->btnFirst, ui->btnPreVious, ui->btnNext, ui->btnLast, countName);
    ui->tableMain->horizontalHeader()->setStretchLastSection(true);
    ui->tableMain->verticalHeader()->setDefaultSectionSize(25);
}

void backroom::initview(){
    //绑定数据到表格
    QString sql = "where pay is null";
    dbPage->setConnName("hotel");
    dbPage->setTableName(tableName);
    dbPage->setOrderSql(QString("%1 %2").arg(countName).arg("desc"));
    dbPage->setWhereSql(sql);
    dbPage->setRecordsPerpage(20);
    dbPage->setColumnNames(columnNames);
    dbPage->setColumnWidths(columnWidths);
    dbPage->select();
}

void backroom::on_btn_roonno_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void backroom::on_btn_id_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void backroom::on_btnSelect_clicked()
{
    int index = ui->stackedWidget->currentIndex();
    if(index == 0)
    {
        QString noomno = ui->edit_roomno->text();
        QString sql = "where roomno = " + noomno ;
        dbPage->setOrderSql(QString("%1 %2").arg(countName).arg("desc"));
        dbPage->setWhereSql(sql);
        dbPage->setRecordsPerpage(20);
        dbPage->select();
    }
    else if(index == 1)
    {
        QString id = ui->edit_id->text();
        QString sql = "where sql = " + id;
        dbPage->setOrderSql(QString("%1 %2").arg(countName).arg("desc"));
        dbPage->setWhereSql(sql);
        dbPage->setRecordsPerpage(20);
        dbPage->select();
    }
    else
    {
        QMessageBox::warning(this,"查询失败","发生未知错误！");
    }
}

void backroom::on_btnbackroom_clicked()
{
    QModelIndexList selected = ui->tableMain->selectionModel()->selectedRows();
    if(selected.count()>1)
    {
        QMessageBox::warning(this,"退房失败","只能选择一个订单！");
    }
    else if(selected.count()<1)
    {
        QMessageBox::warning(this,"退房失败","请选择一个订单！");
    }else
    {
         QList<QModelIndex> list= ui->tableMain->selectionModel()->selectedRows();
         qDebug()<<list[0].data().toString();
    }
}
