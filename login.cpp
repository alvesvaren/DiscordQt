#include "login.h"
#include "ui_login.h"

#include <iostream>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    DiscordQt w;

}

Login::~Login()
{
    delete ui;
}

void Login::on_loginButton_clicked()
{
    w.show();
}
