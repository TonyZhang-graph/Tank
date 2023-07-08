#ifndef SCENE_CHOICE_H
#define SCENE_CHOICE_H

#pragma once

#include <QMouseEvent>

#include "choice_box_base.h"

class Scene_Choice: public Choice_Box_Base
{
    Q_OBJECT
public:
    explicit Scene_Choice(const QString &img_url, const QString &_map_url, QWidget *parent = nullptr);

    // change the state when chosen
    void mousePressEvent(QMouseEvent *event) override;

    static bool chosen;

    QString map;

    static void reset();

    static QString chose_url;

    static QString map_url;

private:
    static QString chosen_style;
};

#endif // SCENE_CHOICE_H
