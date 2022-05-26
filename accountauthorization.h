#ifndef ACCOUNTAUTHORIZATION_H
#define ACCOUNTAUTHORIZATION_H
#include <QtGui>
#include <QtSql>
#include <QWidget>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>
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
