#ifndef ORDERBLOG_H
#define ORDERBLOG_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QTableView>
namespace Ui {
class Orderblog;
}

class Orderblog : public QWidget
{
    Q_OBJECT

public:
    explicit Orderblog(QWidget *parent = 0);
    ~Orderblog();
    void InitForm(); //初始化表格

    //将order表中的数据绑定到指定的TableView上
    void MyBindTable(QString tableName, QString where,QTableView *tableView,
                     QString columnNames[], int columnWidths[]);
private slots:
    void on_btn_time_clicked();

    void on_btn_room_clicked();

private:
    Ui::Orderblog *ui;

    QSqlQueryModel *QueryModel;     //查询模型
    QTableView *TableView;          //显示数据的表格对象
    QString ColumnNames[9];         //列名数组声明
    int ColumnWidths[9];            //列宽数组声明
};

#endif // ORDERBLOG_H
