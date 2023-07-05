#include "select.h"

Select::Select(QObject *parent) : QGraphicsScene{parent}
{
    // load background
    QPixmap bg_img(":/resource/Environment/sky.png");
    background = new QGraphicsPixmapItem[49];
    QGraphicsPixmapItem *p_background = background;
    for(int i = 0; i < 49; ++i, ++p_background)
    {
        p_background->setPixmap(bg_img);
        this->addItem(p_background);
        p_background->setPos((i % 7) << 7, (i / 7) << 7);
    }

}

Select::~Select()
{
    delete background;

}
