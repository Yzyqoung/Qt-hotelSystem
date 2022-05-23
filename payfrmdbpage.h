/***************************************************************
 *文件名称：支付完成订单界面
 *简要描述：
 *
 *当前版本：V1.0
 *作者：Young
 *创作日期：2022/5/5
 *说明：Email:578706463@qq.com
*****************************************************************/
#ifndef PAYFRMDBPAGE_H
#define PAYFRMDBPAGE_H

#include <QWidget>
#include <dbpage.h>
namespace Ui {
class payfrmdbpage;
}

class payfrmdbpage : public QWidget
{
    Q_OBJECT

public:
    explicit payfrmdbpage(QWidget *parent = 0);
    ~payfrmdbpage();

private:
    Ui::payfrmdbpage *ui;

    QList<QString> columnNames; //字段名集合
    QList<int> columnWidths;    //字段宽度集合
    DbPage *dbPage;             //数据库翻页类

    QString tableName;          //表名称
    QString countName;          //统计行数字段名称

private slots:
    void initForm();//表格初始化
    void initBox();//Box初始化
    void initView();

private slots:
    void on_btnSelect_clicked();
    void on_btn_time_clicked();
    void on_btnExcel_clicked();
    void on_btn_customer_clicked();
    void on_btn_price_clicked();
    void on_btn_staff_clicked();
    void on_btnDelete_clicked();
    void on_btnBack_clicked();
};

#endif // PAYFRMDBPAGE_H
