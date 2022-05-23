/***************************************************************
 *文件名称：数据库备份
 *简要描述：一个界面类和一个进程类。采取异步操作完成界面更新与后台数据库操作。
 *
 *当前版本：V1.0
 *作者：Young
 *创作日期：2022/5/20
 *说明：Email:578706463@qq.com
*****************************************************************/
#ifndef BACKUPSSQL_H
#define BACKUPSSQL_H
#include <QtGui>
#include <QtSql>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>

namespace Ui {
class backupssql;
}

class backupssql : public QWidget
{
    Q_OBJECT

public:
    explicit backupssql(QWidget *parent = 0);
    ~backupssql();

     void InitForm();

private slots:
    void on_pbnOk_clicked();
    void on_pbnSearch_clicked();
    void on_lineEdit_textChanged(const QString &arg1);
private:
    Ui::backupssql *ui;
signals:
    void updatestart();
    void updatefinish();
};


#endif // BACKUPSSQL_H
