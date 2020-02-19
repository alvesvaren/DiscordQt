#include "logindialog.h"
#include "ui_logindialog.h"
#include <QDesktopServices>
#include <QUrl>
#include <QtNetwork/QNetworkRequest>

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

void LoginDialog::on_syncRequestFinished(QNetworkReply *reply) {
    QByteArray data = reply->readAll();
    qWarning() << data;
    QJsonObject test = QJsonDocument::fromJson(data).object();
    if (!test["token"].isNull() && test["token"].isString()) {
          ui->tokenField->setText(test["token"].toString());
          ui->twoFactorAuthField->setEnabled(false);
    } else {
        ui->twoFactorAuthField->setEnabled(true);
    }

}

void LoginDialog::on_loginButton_clicked()
{

    qWarning() << "reply->readAll";
    // QJsonDocument tmp = api::login(ui->emailField->text().toStdString(), ui->passwordField->text().toStdString());
    // ui->tokenField->setText(QString::fromUtf8(tmp.toJson()));
    QUrl url("https://discordapp.com/api/v6/auth/login");
    QNetworkRequest request(url);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(on_syncRequestFinished(QNetworkReply*)));
    QJsonObject json;
    json["email"] = ui->emailField->text();
    json["password"] = ui->passwordField->text();
    QByteArray data = QJsonDocument(json).toJson();

    // FIXME for debug
    manager->post(request, data);
}
