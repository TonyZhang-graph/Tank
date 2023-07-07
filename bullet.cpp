#include "bullet.h"

qreal Bullet::convert = acos(0) / 90;

Bullet::Bullet(const QString &img_url, QPointF center, qreal heading, QGraphicsItem * _walls[], tankbase *_enemy, const qint8 &_time)
{
    walls = _walls;

    speed = 1;

    attack_value = 5;

    time = _time;

    enemy = _enemy;

    item = new QGraphicsPixmapItem(QPixmap(img_url));

    // set initial position
    QPointF cur_center = item->boundingRect().center();
    item->setPos(item->pos() + (center - cur_center));

    // set initial speed
    vx = sin(heading * convert) * speed;
    vy = -cos(heading * convert) * speed;

    // set rotation
    item->setTransformOriginPoint(item->boundingRect().center());
    item->setRotation(heading);
}

bool Bullet::collide_with_walls() {

    for (int i = 0; walls[i] != NULL; ++i) {
        if (item->collidesWithItem(walls[i])) {
            return true;
        }
    }

    return false;
}

void Bullet::refresh() {

    item->setPos(item->x() + vx, item->y() + vy);

    for (int i = 0; walls[i] != nullptr; ++i)
    {
        if (item->collidesWithItem(walls[i]))
        {
            QRectF wallRect=walls[i]->boundingRect();

            QLineF topEdge(wallRect.topLeft(), wallRect.topRight());
            QLineF rightEdge(wallRect.topRight(), wallRect.bottomRight());
            QLineF bottomEdge(wallRect.bottomRight(), wallRect.bottomLeft());
            QLineF leftEdge(wallRect.bottomLeft(), wallRect.topLeft());

            if (collide_with_line(topEdge))
            {
                reflect(topEdge);
                break;
            }
            if (collide_with_line(rightEdge))
            {
                reflect(rightEdge);
                break;
            }
            if (collide_with_line(bottomEdge))
            {
                reflect(bottomEdge);
                break;
            }
            if (collide_with_line(leftEdge))
            {
                reflect(leftEdge);
                break;
            }
        }
    }
    return;
}

void Bullet::reflect(const QLineF &a_wall)
{
    time++;

    QLineF collisionNormal = a_wall.normalVector().unitVector();
    QPointF NormalVector = collisionNormal.p2() - collisionNormal.p1();
    item->setPos(item->pos() + 3 * NormalVector);

    QPointF bulletDirection(sin(item->rotation() * convert), -cos(item->rotation() * convert));

    QPointF p1(0,0);

    QLineF originDirection(p1, bulletDirection);
    qreal deltaAngle = 180 - 2 * originDirection.angleTo(collisionNormal);
    qreal newheading = item->rotation() + deltaAngle;

    while (newheading >= 360) newheading -= 360;
    while (newheading < 0) newheading += 360;

    vx =  sin(newheading * convert) * speed;
    vy = -cos(newheading * convert) * speed;
    item->setTransformOriginPoint(item->boundingRect().center());
    item->setRotation(newheading);
}

bool Bullet::collide_with_line(const QLineF &line)
{

    QGraphicsLineItem l(line);
    return item->collidesWithItem(&l);
}

