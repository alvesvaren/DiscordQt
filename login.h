#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "discordqt.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
private slots:
    void on_loginButton_clicked();

private:
    DiscordQt w;
    Ui::Login *ui;

};

#endif // LOGIN_H
