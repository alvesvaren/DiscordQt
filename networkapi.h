#ifndef NETWORKAPI_H
#define NETWORKAPI_H
#include "string"
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QUrl>
#include <QJsonDocument>
using namespace std;
vector<string> defaultVector;


namespace networkapi {
QJsonDocument get(string url, vector<std::string> headers = defaultVector, std::string payload = "{}");
}
#endif // NETWORKAPI_H
