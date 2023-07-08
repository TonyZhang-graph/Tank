#ifndef TILE_H
#define TILE_H

#pragma once

#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QMap>

#include "tankbase.h"

class Tile
{
public:
    explicit Tile(tankbase **_tanks);
//    ~Tile();

    QGraphicsPixmapItem *item;
    QPixmap *pixmap;

    tankbase **tanks;

    int length;

    qint8 conquer;

    static QMap<QString, Qt::GlobalColor> colors;

    bool change_color();
};

#endif // TILE_H
