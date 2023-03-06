// SPDX-License-Identifier: MIT
/*
 * Copyright (C) 2022 He Yong <hyyoxhk@163.com>
 */

#ifndef SMARTHMI_H
#define SMARTHMI_H

#include <QObject>

class Config;
class QGuiApplication;
class QQmlApplicationEngine;

class SmartHmi : public QObject
{
    Q_OBJECT
public:
    explicit SmartHmi(int &argc, char **argv);
    ~SmartHmi();

    int exec();

private:
    Config *m_config;
    QGuiApplication *m_app;
    QQmlApplicationEngine *m_engine;

    void registerQmlTypes();
    void setupQmlContextProperties();

};

#endif // SMARTHMI_H
