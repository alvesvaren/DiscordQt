#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QNetworkReply>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    QString ticketId;
    bool sms;
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:

    void on_registerButton_clicked();

    void on_emailField_textChanged(const QString &arg1);

    void on_dialogButton_accepted();

    void on_loginButton_clicked();

    void on_syncRequestFinished(QNetworkReply *reply);

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
