#include "map.h"

// TREE1 = 0, TREE2 = 1, SANDBAG1 = 2, SANDBAG2 = 3, BARREL1 = 4, BARREL2 = 5, BARREL3 = 6, BARREL4 = 7;
QString Map::type_to_url[8] = {":/resource/Environment/treeLarge.png",
                          ":/resource/Environment/treeSmall.png",
                          ":/resource/Obstacles/sandbagBeige.png",
                          ":/resource/Obstacles/sandbagBrown.png",
                          ":/resource/Obstacles/barrelGreen_side.png",
                          ":/resource/Obstacles/barrelGreen_side_damaged.png",
                          ":/resource/Obstacles/barrelRed_side.png",
                          ":/resource/Obstacles/barrelGrey_sde_rust.png"};

void Map::load(QGraphicsScene *scene, QGraphicsItem **walls, QGraphicsPixmapItem *record)
{
    for (int i = 0; i < 20 && type[i] != -1; ++i, ++record)
    {
        record->setPixmap(QPixmap(type_to_url[type[i]]));
        record->setPos(x[i], y[i]);
        record->setRotation(heading[i]);
        scene->addItem(record);

        if(type[i] >= 2)
        {
            *walls = record;
            ++walls;
        }
    }
}


