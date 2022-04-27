#include "frmdbpage.h"
#include "ui_frmdbpage.h"
#include "dbpage.h"
#include <QDate>
frmDbPage::frmDbPage(QWidget *parent) : QWidget(parent), ui(new Ui::frmDbPage)
{
    ui->setupUi(this);

    this->initBox();
    this->initForm();
    this->initView();

    on_btnSelect_clicked();
}

frmDbPage::~frmDbPage()
{
    delete ui;
}

void frmDbPage::initBox(){
    ui->stackedWidget->setCurrentIndex(1);
    ui->dateStart->setDate(QDate::currentDate());
    ui->dateEnd->setDate(QDate::currentDate());
}

void frmDbPage::initForm()
{
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

void frmDbPage::initView(){
    //绑定数据到表格
    QString sql = "where 1=1";
    dbPage->setConnName("hotel");
    dbPage->setTableName(tableName);
    dbPage->setOrderSql(QString("%1 %2").arg(countName).arg("desc"));
    dbPage->setWhereSql(sql);
    dbPage->setRecordsPerpage(20);
    dbPage->setColumnNames(columnNames);
    dbPage->setColumnWidths(columnWidths);
    dbPage->select();
}

void frmDbPage::on_btnSelect_clicked()
{
    if(ui->stackedWidget->currentIndex()==1)//时间查询
    {
        QString startdate = ui->dateStart->date().toString("yyyy-MM-dd");
        QString enddate = ui->dateEnd->date().toString("yyyy-MM-dd");
    }
    else if(ui->stackedWidget->currentIndex()==0)//房型查询
    {

    }
}

void frmDbPage::on_btn_time_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void frmDbPage::on_btn_room_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void frmDbPage::on_btnExcel_clicked()
{

        QString filepath = QFileDialog::getSaveFileName(this, tr("Save as..."),
                                                      QString(), tr("EXCEL files (*.xls);;HTML-Files (*.txt);;"));

        if (filepath != "")
        {
            int row = ui->tableMain->model()->rowCount();
            int col = ui->tableMain->model()->columnCount();
            QList<QString> list;
            //添加列标题
            QString HeaderRow;
            for (int i = 0; i < col; i++)
            {
                HeaderRow.append(ui->tableMain->model()->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\t");
            }
            list.push_back(HeaderRow);
            for (int i = 0; i < row; i++)
            {
                QString rowStr = "";
                for (int j = 0; j < col; j++){
                    QModelIndex index = ui->tableMain->model()->index(i, j);
                    rowStr += ui->tableMain->model()->data(index).toString() + "\t";
                }
                list.push_back(rowStr);
            }
            QTextEdit textEdit;
            for (int i = 0; i < list.size(); i++)
            {
                textEdit.append(list.at(i));
            }

            QFile file(filepath);
            if (file.open(QFile::WriteOnly | QIODevice::Text))
            {
                QTextStream ts(&file);
                ts.setCodec("GB2312");//这个地方大家自己判断是否用“utf-8”
                ts << textEdit.document()->toPlainText();
                file.close();
                QMessageBox::information(NULL, "导出数据", "数据导出成功", QMessageBox::Yes, QMessageBox::Yes);
            }else{
                QMessageBox::information(NULL, "导出数据", "数据导出失败", QMessageBox::Yes, QMessageBox::Yes);
            }
        }

}

void frmDbPage::on_roomBox_activated(int index)
{
    qDebug()<<index;
    if(0!=index)
    {
        ui->btn_bigroom->setAutoExclusive(false);
        ui->btn_bigroom->setAutoExclusive(true);
        ui->btn_oneroom->setAutoExclusive(false);
        ui->btn_oneroom->setAutoExclusive(true);
        ui->btn_tworoom->setAutoExclusive(false);
        ui->btn_tworoom->setAutoExclusive(true);
        ui->btn_exeroom->setAutoExclusive(false);
        ui->btn_exeroom->setAutoExclusive(true);
        ui->btn_delroom->setAutoExclusive(false);
        ui->btn_delroom->setAutoExclusive(true);
    }
}
