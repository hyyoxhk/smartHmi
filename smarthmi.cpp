// SPDX-License-Identifier: MIT
/*
 * Copyright (C) 2022 He Yong <hyyoxhk@163.com>
 */

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QLocale>
#include <QTranslator>

#include "beep.h"
#include "smarthmi.h"

static QGuiApplication *createApp(int &argc, char **argv)
{
    QGuiApplication *app = new QGuiApplication(argc, argv);
    return app;
}

SmartHmi::SmartHmi(int &argc, char **argv)
    : m_app(createApp(argc, argv))
{
//    m_config = new Config(this);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "smartHmi_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            m_app->installTranslator(&translator);
            break;
        }
    }

    m_engine = new QQmlApplicationEngine(this);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(m_engine, &QQmlApplicationEngine::objectCreated,
                     m_app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    registerQmlTypes();
    setupQmlContextProperties();
    m_engine->load(url);
}

SmartHmi::~SmartHmi()
{
    if (m_engine != nullptr) {
        delete m_engine;
        m_engine = nullptr;
    }

    if (m_app != nullptr) {
        delete m_app;
        m_app = nullptr;
    }
}

int SmartHmi::exec()
{
    return m_app->exec();
}

void SmartHmi::registerQmlTypes()
{
    //qmlRegisterType<WifiIcon>("com.vantrontech.hmi", 1, 0, "WifiIcon");
}

void SmartHmi::setupQmlContextProperties()
{
    auto beep = new Beep(this);
    m_engine->rootContext()->setContextProperty("beep", beep);
}
