#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_btnLogin_clicked();

    void on_toolButton_clicked();

    void on_btn_close_clicked();

    void on_btn_min_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
