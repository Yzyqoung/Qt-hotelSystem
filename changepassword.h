#ifndef CHANGEPASSWORD_H
#define CHANGEPASSWORD_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDebug>
#include "mainwindow.h"
namespace Ui {
class ChangePassword;
}

class ChangePassword : public QWidget
{
    Q_OBJECT

public:
    explicit ChangePassword(QWidget *parent = 0);
    ~ChangePassword();

private slots:
    void on_btnOk_clicked();

    void on_btnCancel_clicked();

private:
    Ui::ChangePassword *ui;
};

#endif // CHANGEPASSWORD_H
