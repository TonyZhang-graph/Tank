#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#pragma once

#include <QMainWindow>
#include <QSoundEffect>
#include <QScrollBar>
#include <QGraphicsScene>

#include "music.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    virtual ~GameWindow();

    QGraphicsScene *scene;

    Ui::GameWindow *ui;

    void set_scene(QGraphicsScene *_scene);

private:
    QSoundEffect *music;

public slots:
    void change_music_state();

};
#endif // GAMEWINDOW_H
