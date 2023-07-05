#ifndef PALSE_H
#define PALSE_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QGraphicsScene>

#include <menu.h>

class palse: public QDialog
{
    Q_OBJECT
public:
    explicit palse(QGraphicsScene* parent);
    ~palse();

private:
    // record the parent in order to back to the menu
    QGraphicsScene* _parent;

    // buttons
    QPushButton* back_to_game;
    QPushButton* back_to_menu;
    QPushButton* music_state;

    // title
    QLabel* title_text;

public slots:
    void go_back_to_menu();
    void change_music();
};

#endif // PALSE_H
