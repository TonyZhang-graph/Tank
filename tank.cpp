#include "tank.h"

Tank_Blue::Tank_Blue(QGraphicsItem **walls) : tankbase(0.7, 10, ":/resource/Tanks/tankBlue.png", walls) {}

Bullet Tank_Blue::new_bullet()
{
    return Bullet(":/resource/Bullets/bulletBlue.png", item->mapToScene(item->boundingRect().center()), heading, walls);
}

Tank_Green::Tank_Green(QGraphicsItem **walls) : tankbase(0.5, 20, ":/resource/Tanks/tankGreen.png", walls) {}

Bullet Tank_Green::new_bullet()
{
    return Bullet(":/resource/Bullets/bulletGreen.png", item->mapToScene(item->boundingRect().center()), heading, walls);
}

Tank_Red::Tank_Red(QGraphicsItem **walls) : tankbase(0.3, 30, ":/resource/Tanks/tankRed.png", walls) {}

Bullet Tank_Red::new_bullet()
{
    return Bullet(":/resource/Bullets/bulletRed.png", item->mapToScene(item->boundingRect().center()), heading, walls);
}

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
