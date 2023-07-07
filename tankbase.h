#ifndef TANKBASE_H
#define TANKBASE_H

#pragma once

#include <QGraphicsPixmapItem>
#include <QTransform>
#include <QtMath>
#include <QString>
#include <QPainter>

class tankbase
{
public:
    tankbase(const qreal &_speed, const qint8 &_max_hp, const QString &img_url, QGraphicsItem **_walls);
    virtual ~tankbase();

    static qreal convert;

    QPixmap img;

    QGraphicsPixmapItem *item;
    QGraphicsItem **walls;

    qreal heading;
    qint8 hp;
    int moving;
    bool turning_left, turning_right;
    qint8 max_hp;
    qreal speed;

    void refresh();
    bool collide_with_walls();
    bool is_dead();
    QPixmap img_with_blood_box(QPixmap img);
};

#endif // TANKBASE_H
