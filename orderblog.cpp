#include "orderblog.h"
#include "ui_orderblog.h"
#include "QDate"
#include <QDebug>
Orderblog::Orderblog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Orderblog)
{
    ui->setupUi(this);

    //初始化界面
    this->InitForm();
}

Orderblog::~Orderblog()
{
    delete ui;
}

void Orderblog::InitForm()
{
    //初始化打开界面，默认设置时间选择为第一页
    ui->stackedWidget->setCurrentIndex(1); //0为房型查询，1为时间查询
    ui->dateStart->setDate(QDate::currentDate());
    ui->dateEnd->setDate(QDate::currentDate());

    //初始化表格列名和列宽
    ColumnNames[0] = tr("订单号");
    ColumnNames[1] = tr("客户名");
    ColumnNames[2] = tr("身份证号");
    ColumnNames[3] = tr("手机号");
    ColumnNames[4] = tr("房间号");
    ColumnNames[5] = tr("入住时间");
    ColumnNames[6] = tr("退房时间");
    ColumnNames[7] = tr("消费金额");
    ColumnNames[8] = tr("操作员");

    ColumnWidths[0] = 80;
    ColumnWidths[1] = 80;
    ColumnWidths[2] = 200;
    ColumnWidths[3] = 140;
    ColumnWidths[4] = 80;
    ColumnWidths[5] = 140;
    ColumnWidths[6] = 140;
    ColumnWidths[7] = 80;
    ColumnWidths[8] = 80;

    this->MyBindTable("hotel.order"," ",ui->tableView,ColumnNames,ColumnWidths);

      //如果登录的非店长admin，禁用删除按钮
//    if(Myapp::LastLoginter !="admin")
//    {
//        ui->btnDelete->setEnabled(false);
//    }
}

void Orderblog::MyBindTable(QString tableName, QString where,QTableView *tableView, QString columnNames[], int columnWidths[])
{
    QueryModel = new QSqlQueryModel(this);
    TableView = tableView;
    QString sql = "SELECT * FROM " + tableName + where;
    QueryModel->setQuery(sql);
    TableView->setModel(QueryModel);

    //依次设置列标题、列宽等
    for (int i = 0;i<TableView->model()->columnCount();i++)
    {
        QueryModel->setHeaderData(i,Qt::Horizontal,columnNames[i]);     //设置列标题
        TableView->setColumnWidth(i,columnWidths[i]);                   //设置列宽
    }
    TableView->horizontalHeader()->setHighlightSections(false);         //点击表头时不对表头光亮
    TableView->setSelectionMode(QAbstractItemView::ContiguousSelection);//选中模式为多行选中
    TableView->setSelectionBehavior(QAbstractItemView::SelectRows);     //选中整行
    TableView->setStyleSheet( "QTableView::item:hover{background-color:rgb(92,188,227,200)}"
                              "QTableView::item:selected{background-color:#1B89A1}");

    qDebug()<<"initial orderform success!";
}

void Orderblog::on_btn_time_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Orderblog::on_btn_room_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}
