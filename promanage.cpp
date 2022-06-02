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

void promanage::findchoice(){
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

    //return setwheresql(choice);
}

QString promanage::setwheresql(QString choice){
//    QString wheresql = "";
//    QString RoomFloor = "";
//    QString RoomState = "";
//    QString RoomType = "";
//    if(choice==''){
//        wheresql = "1=1";
//    }else if(choice=='1'){
//        if(ui->comboBoxRoomfloor->currentText()=="所有楼层") wheresql = "1=1";
//        else {
//            switch (ui->comboBoxRoomfloor->currentIndex()) {
//            case 1:
//                wheresql = "room_no like '1__'";
//                break;
//            case 2:
//                wheresql = "room_no like '2__'";
//                break;
//            case 3:
//                wheresql = "room_no like '3__'";
//                break;
//            case 4:
//                wheresql = "room_no like '4__'";
//                break;
//            case 5:
//                wheresql = "room_no like '5__'";
//                break;
//            case 6:
//                wheresql = "room_no like '6__'";
//                break;
//            case 7:
//                wheresql = "room_no like '7__'";
//                break;
//            case 8:
//                wheresql = "room_no like '8__'";
//                break;
//            case 9:
//                wheresql = "room_no like '9__'";
//                break;
//            case 10:
//                wheresql = "room_no like '10__'";
//                break;
//            case 11:
//                wheresql = "room_no like '11__'";
//                break;
//            case 12:
//                wheresql = "room_no like '12__'";
//                break;
//            case 13:
//                wheresql = "room_no like '13__'";
//                break;
//            case 14:
//                wheresql = "room_no like '14__'";
//                break;
//            case 15:
//                wheresql = "room_no like '15__'";
//                break;
//            case 16:
//                wheresql = "room_no like '16__'";
//                break;
//            case 17:
//                wheresql = "room_no like '17__'";
//                break;
//            case 18:
//                wheresql = "room_no like '18__'";
//                break;
//            case 19:
//                wheresql = "room_no like '19__'";
//                break;
//            case 20:
//                wheresql = "room_no like '20__'";
//                break;
//            case 21:
//                wheresql = "room_no like '21__'";
//                break;
//            case 22:
//                wheresql = "room_no like '22__'";
//                break;
//            case 23:
//                wheresql = "room_no like '23__'";
//                break;
//            default:
//                wheresql = "1=1";
//                break;
//            }
//        }
//    }else if(choice=='2'){

//    }else if(choice=='3'){

//    }else if(choice=='12'){

//    }else if(choice=='13'){

//    }else if(choice=='23'){

//    }else if(choice=='123'){

//    }

    return "wheresql";
}

void promanage::on_btnSelect_clicked()
{
    //QString wheresql = findchoice();
    //qDebug()<<wheresql;
}
