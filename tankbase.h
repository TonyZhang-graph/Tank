#ifndef TANKBASE_H
#define TANKBASE_H

#include <QGraphicsPixmapItem>
#include <QTransform>
#include <QtMath>

#include <QDebug>

class tankbase
{
public:
    tankbase(QGraphicsItem* []);

    QGraphicsPixmapItem *item;
    QGraphicsItem **walls;
    qreal heading, speed;
    int moving;
    bool turning_left, turning_right;

    void refresh();
    bool collide_with_walls();
};

#endif // TANKBASE_H
