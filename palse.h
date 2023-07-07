#ifndef PALSE_H
#define PALSE_H

#pragma once

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QGraphicsScene>
#include <QString>

#include "music.h"
#include "gamewindow.h"
#include "button.h"

class Palse : public QDialog
{
    Q_OBJECT
public:
    explicit Palse(GameWindow *_ui, QGraphicsScene* menu);
    ~Palse();

private:
    // buttons
    Button* back_to_game;
    Button* back_to_menu;
    Button* music_state;

    // title
    QLabel* title_text;

    // menu
    GameWindow *ui;
    QGraphicsScene *_menu;

public slots:
    void go_back_to_menu();
    void change_music();
};

#endif // PALSE_H
