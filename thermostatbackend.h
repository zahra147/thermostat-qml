#ifndef THERMOSTATBACKEND_H
#define THERMOSTATBACKEND_H
#include <QObject>
class ThermostatBackend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int temperature READ temperature NOTIFY temperatureChanged FINAL)
    Q_PROPERTY(QString circleColor READ circleColor NOTIFY temperatureChanged)
public:
    explicit ThermostatBackend(QObject *parent = nullptr);
    int temperature ()const;
    QString circleColor() const;
    Q_INVOKABLE void increase();
    Q_INVOKABLE void decrease();
signals:
    void temperatureChanged();

private:
    int m_temperature = 17;
};
#endif // THERMOSTATBACKEND_H
