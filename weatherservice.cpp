#include "weatherservice.h"
#include <QNetworkRequest>
#include <QUrl>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>

WeatherService::WeatherService(QObject *parent)
    : QObject{parent}
{
    m_manager = new QNetworkAccessManager(this);
}

double WeatherService::outdoorTemp() const
{
    return m_outdoorTemp;
}

void WeatherService::fetchWeather(const QString &city)
{
    QString url = "https://api.openweathermap.org/data/2.5/weather?q="
                  + city
                  + "&appid=" + m_apiKey
                  + "&units=metric";

    QNetworkRequest request;
    request.setUrl(QUrl(url));
    QNetworkReply *reply = m_manager->get(request);

    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        QByteArray data = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(data);
        QJsonObject obj = doc.object();
        QJsonObject main = obj["main"].toObject();
        m_outdoorTemp = main["temp"].toDouble();
        emit outdoorTempChanged();
        reply->deleteLater();
    });
}
