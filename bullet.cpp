#include "bullet.h"

const qreal convert = acos(0) / 90;

Bullet::Bullet(QPointF center, qreal heading, QGraphicsItem * _walls[])
{
    walls = _walls;

    speed = 1;

    item = new QGraphicsPixmapItem;
    QPixmap img(":/resource/Bullets/bulletGreen.png");
    item->setPixmap(img);

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

    return;
}
