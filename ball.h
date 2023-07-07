#ifndef BALL_H
#define BALL_H

#include <QGraphicsPixmapItem>
#include <QTransform>
#include <QtMath>
#include <QLineF>

#include "soccer_tank.h"

class Ball
{
public:
    Ball(QGraphicsItem *_walls[], Soccer_Tank** _tank);
    ~Ball();

    qreal vx, vy, speed;

    QGraphicsPixmapItem *item;
    QGraphicsItem **walls;
    Soccer_Tank **tank;

    void refresh();
    bool collide_with_walls();
    bool collide_with_line(const QLineF &line);
    void reflect(const QLineF &a_wall);

private:
    static qreal convert;
};

#endif // BALL_H
