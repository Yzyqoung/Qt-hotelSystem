#ifndef BACKROOM_H
#define BACKROOM_H
#include "dbpage.h"
#include <QWidget>
#include <QMessageBox>
namespace Ui {
class backroom;
}

class backroom : public QWidget
{
    Q_OBJECT

public:
    explicit backroom(QWidget *parent = 0);
    ~backroom();

private slots:
    void initview();
    void initbox();
    void initform();
    void on_btn_roonno_clicked();
    void on_btn_id_clicked();

    void on_btnSelect_clicked();

    void on_btnbackroom_clicked();

private:
    Ui::backroom *ui;

    QList<QString> columnNames; //字段名集合
    QList<int> columnWidths;    //字段宽度集合
    DbPage *dbPage;             //数据库翻页类

    QString tableName;          //表名称
    QString countName;          //统计行数字段名称
};

#endif // BACKROOM_H
