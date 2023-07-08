#include "soccer_tank.h"

qreal Soccer_Tank::convert = acos(0) / 90;

Soccer_Tank::Soccer_Tank(const QString &img_url, QGraphicsItem **_walls)
{
    walls = _walls;

    item = new QGraphicsPixmapItem(QPixmap(img_url));

    heading = moving = 0;
    turning_left = turning_right = false;

    speed = 1;

    enemy = nullptr;
}

bool Soccer_Tank::collide_with_walls()
{
    for(int i = 0; walls[i] != nullptr; ++i)
    {
        if(item->collidesWithItem(walls[i]))
        {
            return true;
        }
    }
    return false;
}

void Soccer_Tank::refresh()
{
    // heading change
    bool heading_change = false;
    qreal delta_heading;
    if (turning_left && !turning_right)
    {
        delta_heading = -speed;
        heading_change = true;
    }

    else if (!turning_left && turning_right)
    {
        delta_heading = speed;
        heading_change = true;
    }

    if (heading_change)
    {
        heading += delta_heading;
        if (heading > 360) heading -= 360;
        else if (heading < 0) heading += 360;

        item->setTransformOriginPoint(item->boundingRect().center());
        item->setRotation(heading);

        if (this->collide_with_walls())
        {
            heading -= delta_heading;
            item->setRotation(heading);
        }
    }

    // moving
    if (moving != 0)
    {
        qreal x = item->x(), y = item->y();
        qreal delta_x = sin(heading * convert) * moving * speed;
        qreal delta_y = -cos(heading * convert) * moving * speed;

        item->setPos(x + delta_x, y + delta_y);
        if (this->collide_with_walls())
        {
            item->setPos(x, y);
        }
        if(enemy != nullptr && item->collidesWithItem(enemy->item))
        {
            item->setPos(x, y);
        }
    }
}

void Soccer_Tank::set_enemy(Soccer_Tank *_enemy)
{
    enemy = _enemy;
}

Soccer_Tank::~Soccer_Tank()
{
    delete item;
}
