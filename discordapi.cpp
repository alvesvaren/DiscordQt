#include "discordapi.h"

namespace api{

void login(string email, string password) {
    QUrl url("https://discordapp.com/api/v6/auth/login");
    /*QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QJsonDocument tmp;
    tmp.fromJson("{\"email\":\"test@test.test\"}");
    QByteArray data = tmp.toJson();
    manager->post(request, data);
    qDebug() << "Sync" << QString::fromUtf8(data.data(), data.size());
    /*tmp.token = email;
    tmp.ticket = password;*/
    return;
}

}
