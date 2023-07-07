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

#include "ball.h"
#include "soccer_tank.h"
#include "gamewindow.h"
#include "palse.h"

class Soccer_Mode : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Soccer_Mode(GameWindow *_ui, QGraphicsScene *_menu, const QString &img_url, QString *tanks, QObject *parent = nullptr);

    QGraphicsPixmapItem *background;

    QGraphicsItem* walls[40] = {nullptr};

    QTimer *refresh_timer;

    GameWindow *ui;
    QGraphicsScene *menu;

    Soccer_Tank *tank[2];
    Ball *ball;

    void refresh();
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
signals:

};

#endif // SOCCER_MODE_H
