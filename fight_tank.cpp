#include "fight_tank.h"

Tank_Blue::Tank_Blue(QGraphicsItem **walls) : tankbase(0.7, 10, ":/resource/Tanks/tankBlue.png", ":/resource/Bullets/bulletBlue.png", walls) {}

Tank_Green::Tank_Green(QGraphicsItem **walls) : tankbase(0.5, 20, ":/resource/Tanks/tankGreen.png", ":/resource/Bullets/bulletGreen.png", walls) {}

Tank_Red::Tank_Red(QGraphicsItem **walls) : tankbase(0.3, 30, ":/resource/Tanks/tankRed.png", ":/resource/Bullets/bulletRed.png", walls) {}

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
