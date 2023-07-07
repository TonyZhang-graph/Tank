#ifndef TANK_H
#define TANK_H

#pragma once

#include "tankbase.h"

class Tank_Blue : public tankbase
{
public:
    explicit Tank_Blue(QGraphicsItem **walls);
};

class Tank_Green : public tankbase
{
public:
    explicit Tank_Green(QGraphicsItem **walls);
};

class Tank_Red : public tankbase
{
public:
    explicit Tank_Red(QGraphicsItem **walls);
};

tankbase* Tank(const QString &type, QGraphicsItem **walls);

#endif // TANK_H
