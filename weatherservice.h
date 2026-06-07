#ifndef WEATHERSERVICE_H
#define WEATHERSERVICE_H
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "config.h"

class WeatherService : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double outdoorTemp READ outdoorTemp NOTIFY outdoorTempChanged)
    Q_PROPERTY(QString cityName READ cityName NOTIFY outdoorTempChanged)
public:
    explicit WeatherService(QObject *parent = nullptr);
    Q_INVOKABLE void fetchWeather(const QString &city);
    double outdoorTemp() const;
    QString cityName() const;

signals:
    void outdoorTempChanged();
private:
    QNetworkAccessManager *m_manager;
    double m_outdoorTemp = 0.0;
    QString m_cityName ="";
    QString m_apiKey = WEATHER_API_KEY;

};

#endif // WEATHERSERVICE_H
