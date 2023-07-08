#ifndef CONQUER_MODE_H
#define CONQUER_MODE_H

#pragma once

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QTransform>
#include <QKeyEvent>
#include <QGraphicsProxyWidget>
#include <QString>
#include <QGraphicsTextItem>
#include <QList>

#include "bullet.h"
#include "fight_tank.h"
#include "palse.h"
#include "gamewindow.h"
#include "score_board.h"
#include "warning.h"
#include "map.h"
#include "tile.h"

class Conquer_Mode : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Conquer_Mode(GameWindow *_ui, QGraphicsScene *_menu, QString *tanks, QObject *parent = nullptr);
    ~Conquer_Mode();

    Tile *tiles[49];

    QGraphicsItem *walls[40] = {nullptr};
    QGraphicsPixmapItem *record;

    QList<Bullet> bullets;
    tankbase *tank[2];

    QTimer *refresh_timer;

    GameWindow *ui;
    QGraphicsScene *menu;

    Score_Board *score_board;
    QGraphicsProxyWidget *score;

    virtual void refresh();
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
signals:

};

#endif // CONQUER_MODE_H
