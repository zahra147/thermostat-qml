
#include "thermostatbackend.h"

ThermostatBackend::ThermostatBackend(QObject *parent)
    : QObject{parent}
{}
int ThermostatBackend::temperature() const
{
    return m_temperature;
}
void ThermostatBackend::increase(){
    if (m_temperature<40){
        m_temperature+=1;
emit temperatureChanged();
    }
    }
void ThermostatBackend::decrease(){
    if (m_temperature>0){
        m_temperature-=1;
    emit temperatureChanged();
    }
}
QString ThermostatBackend::circleColor() const {
    if (m_temperature < 18) return "#6e94c3";
    if (m_temperature < 25) return "#e96b00";
    return "#fd1700";
}
