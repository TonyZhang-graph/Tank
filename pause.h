#ifndef PAUSE_H
#define PAUSE_H

#pragma once

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QGraphicsScene>
#include <QString>

#include "music.h"
#include "gamewindow.h"
#include "button.h"

class Pause : public QDialog
{
    Q_OBJECT
public:
    explicit Pause(GameWindow *_ui, QGraphicsScene* menu);
    ~Pause();

private:
    // buttons
    Button *back_to_game;
    Button *back_to_menu;
    Button *music_state;

    // title
    QLabel *title_text;

    QLabel *label;

    // menu
    GameWindow *ui;
    QGraphicsScene *_menu;

public slots:
    void go_back_to_menu();
    void change_music();
};

#endif // Pause_H
