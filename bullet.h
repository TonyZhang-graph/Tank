#ifndef BULLET_H
#define BULLET_H

#pragma once

#include <QGraphicsPixmapItem>
#include <QTransform>
#include <QtMath>

#include <QDebug>

class Bullet
{
public:
    Bullet(const QString &img_url, QPointF center, qreal heading, QGraphicsItem* []);
    qreal vx, vy, speed;
    QGraphicsPixmapItem *item;
    QGraphicsItem **walls;

    qint8 attack_value;

    void refresh();
    bool collide_with_walls();
};

#endif // BULLET_H
