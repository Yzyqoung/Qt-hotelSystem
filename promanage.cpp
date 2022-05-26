#include "promanage.h"
#include "ui_promanage.h"

promanage::promanage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::promanage)
{
    ui->setupUi(this);
    initcombox();
    initForm();
    initView();
}

promanage::~promanage()
{
    delete ui;
}

void promanage::initForm(){
    columnNames.clear();
    columnWidths.clear();

    tableName = "hotel.room";
    countName = "room_no";

    columnNames.append("房间号");
    columnNames.append("房间类型");
    columnNames.append("房间状态");
    columnNames.append("备注");

    columnWidths.append(120);
    columnWidths.append(80);
    columnWidths.append(80);
    columnWidths.append(220);

    //设置需要显示数据的表格和翻页的按钮
    dbPage = new DbPage(this);
    //设置所有列居中显示
    dbPage->setAllCenter(true);
    dbPage->setControl(ui->tableMain, ui->labPageTotal, ui->labPageCurrent, ui->labRecordsTotal, ui->labRecordsPerpage,
                       ui->labSelectTime, 0, ui->btnFirst, ui->btnPreVious, ui->btnNext, ui->btnLast, countName);
    ui->tableMain->horizontalHeader()->setStretchLastSection(true);
    ui->tableMain->verticalHeader()->setDefaultSectionSize(25);
}

void promanage::initView(){
    QString sql = "where 1 = 1";
    dbPage->setConnName("hotel");
    dbPage->setTableName(tableName);
    dbPage->setOrderSql(QString("%1 %2").arg(countName).arg("asc"));
    dbPage->setWhereSql(sql);
    dbPage->setRecordsPerpage(50);
    dbPage->setColumnNames(columnNames);
    dbPage->setColumnWidths(columnWidths);
    dbPage->select();
}

void promanage::initcombox()
{

    QSqlQuery query;
    query.prepare("select distinct room_state from room");
    query.exec();
    QStringList StateList;
    while(query.next())
    {
        QString State = query.value("room_state").toString();
        StateList <<  State;
    }
    ui->comboBoxRoomStatus->addItems(StateList);
}

QString promanage::findchoice(){
    //房态、楼层、楼型
    QString roomstate;
    QString roomfloot;
    QString roomtype;

    if(ui->checkBox->checkState()==true) {
        roomstate = ui->comboBoxRoomStatus->currentText();
    }else {
        roomstate = "*";
    }
    if(ui->checkBox_2->checkState()==true){
        roomfloot = ui->comboBoxRoomfloor->currentText();
    }else{
        roomfloot = "*";
    }
    if(ui->checkBox_3->checkState()==true){
        roomtype = ui->comboBoxRoomType->currentText();

    }else{
         roomtype = "*";
    }
    QString wheresql = "roomstate = " + roomstate + ", roomfloot = " + roomfloot + " and roomtype = " + roomtype;
    return wheresql;
}

void promanage::on_btnSelect_clicked()
{
    QString wheresql = findchoice();
    qDebug()<<wheresql;
}
