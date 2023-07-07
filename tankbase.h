#ifndef TANKBASE_H
#define TANKBASE_H

#pragma once

#include <QGraphicsPixmapItem>
#include <QTransform>
#include <QtMath>
#include <QString>

#include <QDebug>

class tankbase
{
public:
    tankbase(const QString &img_url, QGraphicsItem *[]);

    QGraphicsPixmapItem *item;
    QGraphicsItem **walls;
    qreal heading, speed;
    int moving;
    bool turning_left, turning_right;

    void refresh();
    bool collide_with_walls();
};

#endif // TANKBASE_H
