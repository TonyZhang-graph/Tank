#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QTransform>
#include <QtMath>

#include <QDebug>

class Bullet
{
public:
    Bullet(QPointF center, qreal heading, QGraphicsItem* []);
    qreal vx, vy, speed;
    QGraphicsPixmapItem *item;
    QGraphicsItem **walls;

    void refresh();
    bool collide_with_walls();
};

#endif // BULLET_H
