#ifndef KILL_MODE_H
#define KILL_MODE_H

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

class Kill_Mode : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Kill_Mode(GameWindow *_ui, QGraphicsScene *_menu, const QString &img_url, const QString &map_url, QString *tanks, QObject *parent = nullptr);
    ~Kill_Mode();

    QGraphicsPixmapItem *background;

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

#endif // KILL_MODE_H
