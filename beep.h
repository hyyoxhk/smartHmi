// SPDX-License-Identifier: MIT
/*
 * Copyright (C) 2022 He Yong <hyyoxhk@163.com>
 */

#ifndef BEEP_H
#define BEEP_H

#include <QObject>

class Beep : public QObject
{
    Q_OBJECT
public:
    explicit Beep(QObject *parent = nullptr);

    Q_INVOKABLE void play();
};

#endif // BEEP_H
