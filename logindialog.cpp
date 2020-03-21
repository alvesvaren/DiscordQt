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
    } else if (this->ticketId.isEmpty()){
        ui->twoFactorAuthField->setEnabled(true);
        this->ticketId = test["ticket"].toString();
        if (test["sms"].toBool() == true) {
            this->sms = true;
        }
    }

}

void LoginDialog::on_loginButton_clicked()
{

    qWarning() << "reply->readAll";
    // QJsonDocument tmp = api::login(ui->emailField->text().toStdString(), ui->passwordField->text().toStdString());
    // ui->tokenField->setText(QString::fromUtf8(tmp.toJson()));
    QUrl url("https://discordapp.com/api/v6/auth/login");
    if (ui->twoFactorAuthField->isEnabled() && ui->twoFactorAuthField->text().length() == 6) {
        QNetworkRequest mfaRequest(QUrl("https://discordapp.com/api/v6/auth/mfa/totp"));
        mfaRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        connect(manager, SIGNAL(finished(QNetworkReply*)),
                this, SLOT(on_syncRequestFinished(QNetworkReply*)));
        QJsonObject json;
        json["code"] = ui->twoFactorAuthField->text();
        json["ticket"] = this->ticketId;
        QByteArray data = QJsonDocument(json).toJson();
        manager->post(mfaRequest, data);
    } else {
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

}
