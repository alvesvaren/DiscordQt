#ifndef DISCORDAPI_H
#define DISCORDAPI_H
#include <iostream>
#include <vector>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>

using namespace std;
namespace api {

/*struct discord_login_response {
    string token;
    bool mfa;
    bool sms;
    string ticket;
};*/

void login(string email, string password);

}

#endif // DISCORDAPI_H
