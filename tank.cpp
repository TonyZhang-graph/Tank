#include "tank.h"

Tank_Blue::Tank_Blue(QGraphicsItem **walls) : tankbase(0.7, 1, ":/resource/Tanks/tankBlue.png", walls) {}

Tank_Green::Tank_Green(QGraphicsItem **walls) : tankbase(0.5, 2, ":/resource/Tanks/tankGreen.png", walls) {}

Tank_Red::Tank_Red(QGraphicsItem **walls) : tankbase(0.3, 3, ":/resource/Tanks/tankRed.png", walls) {}

tankbase* Tank(const QString &type, QGraphicsItem **walls)
{
    if(type == "G")
    {
        return new Tank_Green(walls);
    }
    if(type == "B")
    {
        return new Tank_Blue(walls);
    }
    if(type == "R")
    {
        return new Tank_Red(walls);
    }
    return nullptr;
}
