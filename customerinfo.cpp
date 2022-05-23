/***************************************************************
 *文件名称：用户信息表
 *简要描述：
 *
 *当前版本：V1.0
 *作者：Young
 *创作日期：2022/5/7
 *说明：Email:578706463@qq.com
*****************************************************************/
#include "customerinfo.h"
#include "ui_customerinfo.h"

customerinfo::customerinfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::customerinfo)
{
    ui->setupUi(this);

    this->initForm();
    this->initView();

}

customerinfo::~customerinfo()
{
    delete ui;
}

void customerinfo::initForm()
{
    columnNames.clear();
    columnWidths.clear();

    tableName = "hotel.customer";
    countName = "name";

    columnNames.append("客户姓名");
    columnNames.append("性别");
    columnNames.append("身份证号");
    columnNames.append("手机号码");
    columnNames.append("VIP开通时间");
    columnNames.append("入住次数");
    columnNames.append("备注");

    columnWidths.append(80);
    columnWidths.append(40);
    columnWidths.append(120);
    columnWidths.append(120);
    columnWidths.append(120);
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

void customerinfo::initView(){
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

void customerinfo::on_btnSelect_clicked()
{
        QString customer_name = ui->edit_name->text();
        QString sql = QString("where name = '%1'").arg(customer_name);
        qDebug()<<sql;
        dbPage->setOrderSql(QString("%1 %2").arg(countName).arg("desc"));
        dbPage->setWhereSql(sql);
        dbPage->setRecordsPerpage(20);
        dbPage->select();
}

void customerinfo::on_btnExcel_clicked()
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

void customerinfo::on_btnDelete_clicked()
{
    QSqlQuery query(QSqlDatabase::database("hotel"));
    query.exec("select user_type from user");
    QString value = "";
    while(query.next())
    {
        value = query.value("user_type").toString();
        qDebug()<<"user_type:"<<value;
        //只需要一个user_type
        break;
    }
    if(value == "管理员")
    {
        qDebug()<<"管理员删除订单";
        QMessageBox::warning(this,"警告","根据相关法律法规，为保证客户入住记录不被删除修改，\n"
                                       "请联系开发商获取授权！");
    }
    else if(value == "员工")
    {
        qDebug()<<"操作失败，当前用户为："<<value<<"，请申请权限！";
        QMessageBox::information(NULL,"提示","您暂无此权限，请向管理员申请！",QMessageBox::Ok);
    }
    else if(value == "临时工")
    {
        qDebug()<<"操作失败，当前用户为："<<value<<"，请申请权限！";
        QMessageBox::information(NULL,"提示","您暂无此权限，请向管理员申请！",QMessageBox::Ok);
    }
    else if(value == "")
    {
        qDebug()<<"查询失败！";
        QMessageBox::information(NULL,"提示","您暂无此权限，请向管理员申请！",QMessageBox::Ok);

    }
    else{
        qDebug()<<"操作失败，当前用户为："<<value;
        QMessageBox::information(NULL,"提示","操作失败,当前用户为非法用户！",QMessageBox::Ok);

    }
}

void customerinfo::on_btn_back_clicked()
{
     this->initView();
}
