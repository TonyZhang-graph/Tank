#include "tile.h"

QMap<QString, Qt::GlobalColor> Tile::colors;

Tile::Tile(tankbase **_tanks)
{
    colors["blue"] = Qt::blue;
    colors["green"] = Qt::green;
    colors["red"] = Qt::red;

    tanks = _tanks;

    conquer = 0;

    length = 128;

    pixmap = new QPixmap(length, length);

    QPainter *painter = new QPainter(pixmap);

    painter->setBrush(QBrush(Qt::transparent));

    painter->drawRect(1, 1, length - 1, length - 1);

    delete painter;

    item = new QGraphicsPixmapItem(*pixmap);
}

void Tile::change_color()
{
    bool conquered[2];
    for(int i = 0; i < 2; ++i)
    {
        conquered[i] = tanks[i]->item->collidesWithItem(item);
    }
    if(conquered[0] == conquered[1])
    {
        return;
    }
    conquer = conquered[0] ? 1 : 2;

    QPainter *painter = new QPainter(pixmap);

    painter->setBrush(QBrush(colors[tanks[conquer - 1]->color]));

    painter->drawRect(1, 1, length - 1, length - 1);

    delete painter;

    item->setPixmap(*pixmap);
}

//Tile::~Tile()
//{
//    delete item;
//    delete pixmap;
//}
