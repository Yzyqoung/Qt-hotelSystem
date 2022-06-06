/***************************************************************
 *文件名称：房间状态展示
 *简要描述：放在主页面，可以点击入住，可以查看房型，房间号等信息
 *
 *当前版本：V1.0
 *作者：Young
 *创作日期：2022/5/23
 *说明：Email:578706463@qq.com
*****************************************************************/
#ifndef PROMANAGE_H
#define PROMANAGE_H

#include <QWidget>
#include "dbpage.h"

namespace Ui {
class promanage;
}

class promanage : public QWidget
{
    Q_OBJECT

public:
    explicit promanage(QWidget *parent = 0);
    ~promanage();

private slots:
    void initForm();//表格初始化
    void initView();//数据初始化
    void initcombox();//combox初始化
    QString findchoice();
    QString setwheresql(QString choice);
    void on_btnSelect_clicked();

    void on_btnback_clicked();
    void on_comboBoxRoomStatus_currentIndexChanged(int index);

    void on_comboBoxRoomfloor_currentIndexChanged(int index);

    void on_comboBoxRoomType_currentIndexChanged(int index);

private:
    Ui::promanage *ui;

    QList<QString> columnNames; //字段名集合
    QList<int> columnWidths;    //字段宽度集合
    DbPage *dbPage;             //数据库翻页类

    QString tableName;          //表名称
    QString countName;          //统计行数字段名称
};

#endif // PROMANAGE_H
