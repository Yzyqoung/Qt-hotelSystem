#ifndef CUSTOMERINFO_H
#define CUSTOMERINFO_H
/***************************************************************
 *文件名称：用户信息表
 *简要描述：
 *
 *当前版本：V1.0
 *作者：Young
 *创作日期：2022/5/7
 *说明：Email:578706463@qq.com
*****************************************************************/
#include <QWidget>
#include "dbpage.h"
namespace Ui {
class customerinfo;
}

class customerinfo : public QWidget
{
    Q_OBJECT

public:
    explicit customerinfo(QWidget *parent = 0);
    ~customerinfo();

private:
    Ui::customerinfo *ui;

    QList<QString> columnNames; //字段名集合
    QList<int> columnWidths;    //字段宽度集合
    DbPage *dbPage;             //数据库翻页类

    QString tableName;          //表名称
    QString countName;          //统计行数字段名称

private slots:
    void initForm();//表格初始化
    void initView();
private slots:
    void on_btnSelect_clicked();
    void on_btnExcel_clicked();
    void on_btnDelete_clicked();
    void on_btn_back_clicked();
};

#endif // CUSTOMERINFO_H
