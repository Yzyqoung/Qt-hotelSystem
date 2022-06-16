#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "frmdbpage.h"
#include "unpayfrmdbpage.h"
#include "payfrmdbpage.h"
#include "customerinfo.h"
#include "backupssql.h"
#include "promanage.h"
#include "accountauthorization.h"
#include "changepassword.h"
#include "backroom.h"

#include <QDateTime>
#include <QTimer>
#include <QSqlRecord>
#include <QPainter>
#include <QMouseEvent>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initwidget();

private slots:
    void on_btn_allorder_clicked();

    void on_btnMenu_Close_clicked();

    void on_btn_unpayorder_clicked();

    void on_btn_payorder_clicked();

    void on_btn_custormerinfo_clicked();

    void on_btn_copy_clicked();

    void on_btn_center_clicked();

    void on_btn_register_clicked();

    void on_btn_changepwd_clicked();

    void on_btn_checkout_clicked();

public slots:
    void setAllEnableTrue();
    void setAllEnableFalse();
    void showCurrentTime();
private:
    Ui::MainWindow *ui;

    QTimer *timer;

    frmDbPage * fDP;
    unpayfrmdbpage * unpayfDP;
    payfrmdbpage * payfDP;
    customerinfo * ctmfDP;
    backupssql * backsql;
    promanage * proManage;
    AccountAuthorization * account;
    ChangePassword * changepwd;
    backroom * backfDP;
};

#endif // MAINWINDOW_H
