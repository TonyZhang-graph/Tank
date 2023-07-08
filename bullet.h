#ifndef BULLET_H
#define BULLET_H

#pragma once

#include <QGraphicsPixmapItem>
#include <QTransform>
#include <QtMath>
#include <QLineF>

#include "tankbase.h"

class Bullet
{
public:
    Bullet(const QString &img_url, QPointF center, qreal heading, QGraphicsItem* _walls[], tankbase *_enemy, const qint8 &_time = 0);
    qreal vx, vy, speed;
    QGraphicsPixmapItem *item;
    QGraphicsItem **walls;

    qint8 attack_value, time;

    tankbase *enemy;

    void refresh();
    bool collide_with_walls();
    bool collide_with_line(const QLineF &line);
    void reflect(const QLineF &a_wall);

private:
    static qreal convert;
};

#endif // BULLET_H
