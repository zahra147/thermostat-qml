#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "thermostatbackend.h"
#include "weatherservice.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    ThermostatBackend backend;
    engine.rootContext()->setContextProperty("backend", &backend);
    WeatherService weather;
    engine.rootContext()->setContextProperty("weather", &weather);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("cloudTest1", "Main");

    return app.exec();
}
