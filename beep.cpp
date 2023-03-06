// SPDX-License-Identifier: MIT
/*
 * Copyright (C) 2022 He Yong <hyyoxhk@163.com>
 */

#include "beep.h"
#include <iostream>

Beep::Beep(QObject *parent)
    : QObject{parent}
{

}

void Beep::play()
{
    std::cout << "play hyyoc" << std::endl;
}
