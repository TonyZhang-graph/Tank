#ifndef TANK_CHOICE_H
#define TANK_CHOICE_H

#pragma once

#include <QMouseEvent>

#include "choice_box_base.h"

class Tank_Choice : public Choice_Box_Base
{
    Q_OBJECT
public:
    explicit Tank_Choice(const QString& img_url, QWidget *parent = nullptr);

    // change the state when chosen
    void mousePressEvent(QMouseEvent *event) override;

    // record the buttons that was chosen
    static bool chosen[2];

    static void reset();

    static QString chose_url[2];
private:
    // state styles
    static QString chosen_style[2];
};

#endif // TANK_CHOICE_H
