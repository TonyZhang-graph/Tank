#ifndef GAMESCENE_H
#define GAMESCENE_H

#pragma once

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QTransform>
#include <QKeyEvent>

#include <QString>
#include <QGraphicsTextItem>
#include <QList>

#include "bullet.h"
#include "tank.h"
#include "palse.h"
#include "gamewindow.h"

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(GameWindow *_ui, QGraphicsScene *_menu, const QString &img_url, QString *tanks, QObject *parent = nullptr);
    QGraphicsPixmapItem background[49];

    QGraphicsItem* walls[40] = {NULL};
    QList<Bullet> bullets;

    QTimer *refresh_timer;

    GameWindow *ui;
    QGraphicsScene *menu;

    void refresh();
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

    tankbase *tank[2];
signals:

};

#endif // GAMESCENE_H
