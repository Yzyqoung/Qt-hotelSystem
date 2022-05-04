#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <frmdbpage.h>
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

private:
    Ui::MainWindow *ui;
    frmDbPage *fDP;
};

#endif // MAINWINDOW_H
