#include "window.h"
#include "ui_gamewindow.h"

Window::Window(QWidget *parent) : GameWindow(parent)
{
    set_scene(new Menu(this));
}
