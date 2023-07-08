#ifndef SOCCER_TANK_H
#define SOCCER_TANK_H

#include <QGraphicsPixmapItem>
#include <QTransform>
#include <QtMath>
#include <QString>

class Soccer_Tank
{
public:
    Soccer_Tank(const QString &img_url, QGraphicsItem **_walls);
    ~Soccer_Tank();

    static qreal convert;

    QGraphicsPixmapItem *item;
    QGraphicsItem **walls;

    qreal heading, speed;
    int moving;
    bool turning_left, turning_right;

    Soccer_Tank *enemy;

    void refresh();
    bool collide_with_walls();
    void set_enemy(Soccer_Tank *_enemy);
};

#endif // SOCCER_TANK_H
