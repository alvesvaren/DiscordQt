#include "logindialog.h"
#include "ui_logindialog.h"
#include <QDesktopServices>
#include <QUrl>
#include "discordapi.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_registerButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://discordapp.com/register"));
}

void LoginDialog::on_emailField_textChanged(const QString &arg1)
{

}

void LoginDialog::on_dialogButton_accepted()
{
    ui->tokenField->text();
}

void LoginDialog::on_loginButton_clicked()
{
    api::discord_login_response tmp = api::login(ui->emailField->text().toStdString(), ui->passwordField->text().toStdString());
    ui->tokenField->setText(QString::fromUtf8(tmp.token.c_str()));
}
