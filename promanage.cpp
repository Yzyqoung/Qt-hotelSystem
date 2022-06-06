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
//初始化表格规格
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
//初始化表格view
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
//初始化combox
void promanage::initcombox()
{

    QSqlQuery query1;
    QSqlQuery query2;
    QSqlQuery query3;

    //初始化房间状态的combox
    query1.prepare("select distinct room_state from room");
    query1.exec();
    QStringList StateList;
    while(query1.next())
    {
        QString State = query1.value("room_state").toString();
        StateList <<  State;
    }
    ui->comboBoxRoomStatus->addItems(StateList);

    //初始化总楼层combox
    query2.prepare("select max(room_no) from room");
    query2.exec();
    int room_no;
    while(query2.next())
    {
        room_no = query2.value("max(room_no)").toInt();
    }
    room_no = room_no / 100; //求出最大层數
    QStringList floorList;
    for(int i = 1;i <= room_no ; i++){
        QString floor = QString::number(i) + "层";
        floorList << floor;
    }
    ui->comboBoxRoomfloor->addItems(floorList);

    //初始化所有楼型combox
    query3.prepare("select distinct room_type from room");
    query3.exec();
    QStringList typeList;
    while(query3.next())
    {
        QString type = query3.value("room_type").toString();
        typeList <<  type;
    }
    ui->comboBoxRoomType->addItems(typeList);
}

QString promanage::findchoice(){
    //房态、楼层、楼型
    QString choice = "";

    if(ui->checkBox->isChecked()==true) {
        choice = "1";
    }
    if(ui->checkBox_2->isChecked()==true){
        choice = choice + "2";
    }
    if(ui->checkBox_3->isChecked()==true){
        choice = choice + "3";
    }

    return setwheresql(choice);
}

QString promanage::setwheresql(QString choice){
    QString wheresql = "";
    QString RoomState = "";     //1房态
    QString RoomFloor = "";     //2楼层
    QString RoomType = "";      //3房型
    qDebug()<<"choice"<<choice;
    if(choice==""){
        wheresql = "1 = 1";
    }else if(choice == "1"){
        if(ui->comboBoxRoomStatus->currentText() == "不限房态")
        {
            wheresql = "1 = 1";
        }
        else
        {
            wheresql = "room_state = '" + ui->comboBoxRoomStatus->currentText() + "'";
        }
    }else if(choice == "2"){
        if(ui->comboBoxRoomfloor->currentText() == "所有楼层")
        {
            wheresql = "1 = 1";
        }
        else
        {
            wheresql = "room_no like '" + QString::number(ui->comboBoxRoomfloor->currentIndex()) + "__'";
        }
    }else if(choice=="3"){
        if(ui->comboBoxRoomType->currentText() == "所有房型")
        {
            wheresql = "1 = 1";
        }
        else
        {
            wheresql = "room_type = '" + ui->comboBoxRoomType->currentText() + "'";
        }
    }else if(choice=="12"){
        if(ui->comboBoxRoomfloor->currentText() == "所有楼层" && ui->comboBoxRoomStatus->currentText() == "不限房态")
        {
            wheresql = "1 = 1";
        }
        else if(ui->comboBoxRoomfloor->currentText() == "所有楼层")
        {
            wheresql = "room_state = '" + ui->comboBoxRoomStatus->currentText() + "'";
        }
        else if(ui->comboBoxRoomStatus->currentText() == "不限房态")
        {
             wheresql = "room_no like '" + QString::number(ui->comboBoxRoomfloor->currentIndex()) + "__'";
        }else
        {
             wheresql = "room_state = '" + ui->comboBoxRoomStatus->currentText() +
                     "' and room_no like '" + QString::number(ui->comboBoxRoomfloor->currentIndex()) + "__'";
        }
    }else if(choice=="13"){
        if(ui->comboBoxRoomType->currentText() == "所有房型" && ui->comboBoxRoomStatus->currentText() == "不限房态")
        {
            wheresql = "1 = 1";
        }
        else if(ui->comboBoxRoomType->currentText() == "所有房型")
        {
            wheresql = "room_state = '" + ui->comboBoxRoomStatus->currentText() + "'";
        }
        else if(ui->comboBoxRoomStatus->currentText() == "不限房态")
        {
            wheresql = "room_type = '" + ui->comboBoxRoomType->currentText() + "'";
        }else
        {
             wheresql = "room_state = '" + ui->comboBoxRoomStatus->currentText() +
                     "' and room_type = '" + ui->comboBoxRoomType->currentText() + "'";
        }
    }else if(choice=="23"){
        if(ui->comboBoxRoomfloor->currentText() == "所有楼层" && ui->comboBoxRoomType->currentText() == "所有房型")
        {
            wheresql = "1 = 1";
        }
        else if(ui->comboBoxRoomType->currentText() == "所有房型")
        {
             wheresql = "room_no like '" + QString::number(ui->comboBoxRoomfloor->currentIndex()) + "__'";
        }
        else if(ui->comboBoxRoomfloor->currentText() == "所有楼层")
        {
            wheresql = "room_type = '" + ui->comboBoxRoomType->currentText() + "'";
        }else
        {
             wheresql = "room_no like '" + QString::number(ui->comboBoxRoomfloor->currentIndex()) + "__'" +
                     " and room_type = '" + ui->comboBoxRoomType->currentText() + "'";
        }
    }else if(choice=="123"){
        if(ui->comboBoxRoomType->currentText() == "所有房型" && ui->comboBoxRoomStatus->currentText() == "不限房态"
                && ui->comboBoxRoomfloor->currentText() == "所有楼层")
        {
            wheresql = "1 = 1";
        }
        else if(ui->comboBoxRoomType->currentText() == "所有房型" && ui->comboBoxRoomStatus->currentText() == "不限房态")
        {
            wheresql = "room_no like '" + QString::number(ui->comboBoxRoomfloor->currentIndex()) + "__'";
        }
        else if(ui->comboBoxRoomStatus->currentText()== "不限房态" && ui->comboBoxRoomfloor->currentText() == "所有楼层")
        {
            wheresql = "room_type = '" + ui->comboBoxRoomType->currentText() + "'";
        }
        else if(ui->comboBoxRoomType->currentText() == "所有房型" && ui->comboBoxRoomfloor->currentText() == "所有楼层")
        {
            wheresql = "room_state = '" + ui->comboBoxRoomStatus->currentText() + "'";
        }
        else if(ui->comboBoxRoomType->currentText() == "所有房型")
        {
            wheresql = "room_state = '" + ui->comboBoxRoomStatus->currentText() +
                    "' and room_no like '" + QString::number(ui->comboBoxRoomfloor->currentIndex()) + "__'";
        }
        else if(ui->comboBoxRoomStatus->currentText() == "不限房态")
        {
            wheresql = "room_no like '" + QString::number(ui->comboBoxRoomfloor->currentIndex()) + "__'" +
                    " and room_type = '" + ui->comboBoxRoomType->currentText() + "'";
        }
        else if(ui->comboBoxRoomfloor->currentText() == "所有楼层")
        {
            wheresql = "room_state = '" + ui->comboBoxRoomStatus->currentText() +
                    "' and room_type = '" + ui->comboBoxRoomType->currentText() + "'";
        }
        else
        {
            wheresql = "room_state = '" + ui->comboBoxRoomStatus->currentText() + "'" +
                    " and room_no like '" + QString::number(ui->comboBoxRoomfloor->currentIndex()) + "__'" +
                                " and room_type = '" + ui->comboBoxRoomType->currentText() + "'";
        }
    }

    return wheresql;
}

void promanage::on_btnSelect_clicked()
{
    QString wheresql = "where " + findchoice();

    dbPage->setOrderSql(QString("%1 %2").arg(countName).arg("asc"));
    dbPage->setWhereSql(wheresql);
    dbPage->setRecordsPerpage(50);
    dbPage->select();

    qDebug()<< wheresql;
}

void promanage::on_btnback_clicked()
{
    initView();
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
}


void promanage::on_comboBoxRoomStatus_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    ui->checkBox->setChecked(true);
}

void promanage::on_comboBoxRoomfloor_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    ui->checkBox_2->setChecked(true);
}

void promanage::on_comboBoxRoomType_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    ui->checkBox_3->setChecked(true);
}
