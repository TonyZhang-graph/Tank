#ifndef SELECT_H
#define SELECT_H

#pragma once

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QGraphicsProxyWidget>
#include <QPixmap>

#include "tank_choice.h"
#include "scene_choice.h"
#include "mode_choice.h"
#include "gamewindow.h"
#include "button.h"
#include "warning.h"
#include "tankbase.h"
#include "soccer_mode.h"
#include "kill_mode.h"

class Select :public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Select(GameWindow* _ui, QGraphicsScene *_menu, QObject* parent = nullptr);
    ~Select();

private:
    // record the menu
    QGraphicsScene *menu;

    // record the ui
    GameWindow *ui;

    // record the mode
    Kill_Mode *game;

    // the background
    QGraphicsPixmapItem *background;

    // choices
    Tank_Choice *_tank_green, *_tank_blue, *_tank_red;
    QGraphicsProxyWidget *tank_green, *tank_blue, *tank_red;

    Scene_Choice *_dirt, *_sand, *_grass;
    QGraphicsProxyWidget *dirt, *sand, *grass;

    Mode_Choice *_kill, *_kick, *_conquer;
    QGraphicsProxyWidget *kill, *kick, *conquer;

    // control buttons
    Button *_back, *_go;
    QGraphicsProxyWidget *back, *go;

    // instruction & title text
    QGraphicsTextItem *instr_l, *instr_r, *title;

public slots:
    void go_to_menu();
    void go_to_game();
};

#endif // SELECT_H
