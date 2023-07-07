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
    tankbase(const qreal &_speed, const qint8 &_max_hp, const QString &img_url, const QString &_bullet_url, QGraphicsItem **_walls);
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

    QString bullet_url;

    tankbase *enemy;

    void refresh();
    bool collide_with_walls();
    bool is_dead();
    void hurted(const qint8 &attack_value);
    QPixmap img_with_blood_box(QPixmap img);
    void set_enemy(tankbase *_enemy);
};

#endif // TANKBASE_H
