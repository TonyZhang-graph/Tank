#ifndef WINDOW_H
#define WINDOW_H

#include "menu.h"
#include "gamewindow.h"

class Window : public GameWindow
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);
};

#endif // WINDOW_H
