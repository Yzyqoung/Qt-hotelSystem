#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "frmdbpage.h"
#include "unpayfrmdbpage.h"
#include "payfrmdbpage.h"
#include "customerinfo.h"
#include "backupssql.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
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

public slots:
    void setAllEnableTrue();
    void setAllEnableFalse();
private:
    Ui::MainWindow *ui;
private:
    Ui::MainWindow *ui;
    frmDbPage *fDP;
    unpayfrmdbpage *unpayfDP;
    payfrmdbpage *payfDP;
    customerinfo * ctmfDP;
    backupssql * backsql;
};

#endif // MAINWINDOW_H
