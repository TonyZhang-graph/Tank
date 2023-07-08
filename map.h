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
    int type[30];
    int x[30], y[30];
    int heading[30];

    static QString type_to_url[11];

    void load(QGraphicsScene *scene, QGraphicsItem **walls, QGraphicsPixmapItem *record);
};

#endif // MAP_H
