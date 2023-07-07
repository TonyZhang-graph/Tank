#ifndef SOCCER_MODE_H
#define SOCCER_MODE_H

#pragma once

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QTransform>
#include <QKeyEvent>
#include <QString>
#include <QGraphicsProxyWidget>
#include <QPainter>
#include <QPen>

#include "ball.h"
#include "soccer_tank.h"
#include "gamewindow.h"
#include "palse.h"
#include "score_board.h"
#include "warning.h"

class Soccer_Mode : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Soccer_Mode(GameWindow *_ui, QGraphicsScene *_menu, const QString &img_url, QString *tanks, QObject *parent = nullptr);
    ~Soccer_Mode();

    QGraphicsPixmapItem *background;

    QGraphicsItem* walls[40] = {nullptr};

    QTimer *refresh_timer;

    GameWindow *ui;
    QGraphicsScene *menu;

    Soccer_Tank *tank[2];
    Ball *ball;

    Score_Board *score_board;
    QGraphicsProxyWidget *score;

    QGraphicsPixmapItem *gates[2];

    void refresh();
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
signals:

};

#endif // SOCCER_MODE_H
