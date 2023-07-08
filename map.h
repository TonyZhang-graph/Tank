#ifndef MAP_H
#define MAP_H

#pragma once

#include <QFile>
#include <QDataStream>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QString>

struct Map
{
    int bgtype;
    int type[20];
    int x[20], y[20];
    int heading[20];

    static QString type_to_url[8];

    void load(QGraphicsScene *scene, QGraphicsItem **walls, QGraphicsPixmapItem *record);
};

#endif // MAP_H
