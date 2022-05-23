#ifndef FRMDBPAGE_H
#define FRMDBPAGE_H
/***************************************************************
 *文件名称：订单查询功能
 *简要描述：
 *
 *当前版本：V1.0
 *作者：Young
 *创作日期：2022/4/26
 *说明：Email:578706463@qq.com
*****************************************************************/
#include <QWidget>

class DbPage;

namespace Ui {
class frmDbPage;
}

class frmDbPage : public QWidget
{
    Q_OBJECT

public:
    explicit frmDbPage(QWidget *parent = 0);
    ~frmDbPage();

private:
    Ui::frmDbPage *ui;

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
};

#endif // FRMDBPAGE_H
