#ifndef MENU_H
#define MENU_H

#pragma once

#include <QFont>
#include <QGraphicsProxyWidget>
#include <QMouseEvent>

#include "kill_mode.h"
#include "instruction.h"
#include "music.h"
#include "select.h"
#include "gamewindow.h"
#include "button.h"
#include "kill_mode.h"

class Menu: public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Menu(GameWindow *_ui, QWidget *parent = nullptr);
    ~Menu();

    // buttons:
    // play game button, instruction button, music setting button, exit button
    Button *_ply_btn, *_instr_btn, *_msc_btn, *_exit_btn;

    QGraphicsProxyWidget *ply_btn, *instr_btn, *msc_btn, *exit_btn;

    // record the ui for scene shifting
    GameWindow *ui;

private:
    QGraphicsPixmapItem *background;

    QGraphicsTextItem *title_text;

signals:

public slots:
    void show_instruction_box();
    void change_music();
    void start_game();
};

#endif // MENU_H
