#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>

#include "gamescene.h"
#include <QScrollBar>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

    QGraphicsScene *scene;

private:
    Ui::GameWindow *ui;
};
#endif // GAMEWINDOW_H
