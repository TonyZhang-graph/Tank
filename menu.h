#ifndef MENU_H
#define MENU_H

#include <QFont>
#include <QPushButton>
#include <QIcon>
#include <QGraphicsProxyWidget>
#include <QMouseEvent>

#include "gamescene.h"
#include "instruction.h"

class Menu: public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

    // buttons:
    // mode 1-3 button, instruction button, music setting button, exit button
    QPushButton *_m1_btn, *_m2_btn, *_m3_btn;
    QPushButton *_instr_btn, *_msc_btn, *_exit_btn;

    QGraphicsProxyWidget *m1_btn, *m2_btn, *m3_btn;
    QGraphicsProxyWidget *instr_btn, *msc_btn, *exit_btn;

    static bool music;

    static QString music_state[2];

private:
    QGraphicsPixmapItem *background;

    QGraphicsTextItem *title_text;

signals:

public slots:
    void show_instruction_box();
    void change_music();
    void start_mode_1();
    void start_mode_2();
    void start_mode_3();
};

#endif // MENU_H
