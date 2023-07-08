#include "tankbase.h"

qreal tankbase::convert = acos(0) / 90;

tankbase::tankbase(const QString &_color, const qreal &_speed, const qint8 &_max_hp, const QString &img_url, const QString &_bullet_url, QGraphicsItem **_walls)
{
    walls = _walls;

    speed = _speed, max_hp = _max_hp;

    hp = max_hp;

    enemy = nullptr;

    color = _color;

    img.load(img_url);

    item = new QGraphicsPixmapItem;
    item->setPixmap(img_with_blood_box(img));

    heading = moving = 0;
    turning_left = turning_right = false;

    bullet_url = _bullet_url;
}

bool tankbase::collide_with_walls()
{
    for (int i = 0; walls[i] != NULL; ++i)
    {
        if (item->collidesWithItem(walls[i]))
        {
            return true;
        }
    }

    return false;
}

void tankbase::refresh()
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

bool tankbase::is_dead()
{
    return hp == 0;
}

QPixmap tankbase::img_with_blood_box(QPixmap img)
{
    qint8 x = img.width() >> 1, y = img.height() >> 1;
    QPainter *painter = new QPainter(&img);
    painter->setBrush(Qt::SolidPattern);
    painter->setBrush(Qt::gray);
    painter->drawRect(x - 15, y - 5, max_hp, 10);
    painter->setBrush(Qt::red);
    painter->drawRect(x - 15, y - 5, hp, 10);
    delete painter;
    return img;
}

void tankbase::hurted(const qint8 &attack_value)
{
    hp = qMax(0, hp - attack_value);
    item->setPixmap(img_with_blood_box(img));
}

void tankbase::set_enemy(tankbase *_enemy)
{
    enemy = _enemy;
}

void tankbase::reborn()
{
    hp = max_hp;
    item->setPixmap(img_with_blood_box(img));
}

tankbase::~tankbase()
{
    delete item;
}
