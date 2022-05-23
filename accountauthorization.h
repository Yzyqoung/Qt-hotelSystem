#ifndef ACCOUNTAUTHORIZATION_H
#define ACCOUNTAUTHORIZATION_H

#include <QWidget>
#include <QSqlQuery>
#include <QSqlTableModel>
#include "SQL_CONFIG/sql_connect.h"
#include "mainwindow.h"
namespace Ui {
class AccountAuthorization;
}

class AccountAuthorization : public QWidget
{
    Q_OBJECT

public:
    explicit AccountAuthorization(QWidget *parent = 0);
    ~AccountAuthorization();

private slots:
    void on_btnCancel_clicked();

    void on_btnOk_clicked();

private:
    Ui::AccountAuthorization *ui;
};

#endif // ACCOUNTAUTHORIZATION_H
