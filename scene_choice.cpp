#include "scene_choice.h"

Scene_Choice::Scene_Choice(const QString &img_url, QWidget *parent) : Choice_Box_Base(img_url, parent) {}

bool Scene_Choice::chosen = 0;

QString Scene_Choice::chosen_style = QString("QPushButton{background-color: pink;}");

QString Scene_Choice::chose_url = "";

void Scene_Choice::mousePressEvent(QMouseEvent *event)
{
    if(event->button() != Qt::LeftButton)
    {
        return;
    }
    if(be_chosen == -1 && chosen)
    {
        return;
    }
    if(chosen)
    {
        this->setStyleSheet(default_style);
        be_chosen = -1, chosen = 0;
        chose_url = "";
    }
    else
    {
        this->setStyleSheet(chosen_style);
        be_chosen = chosen = 1;
        chose_url = img_url;
    }
}

void Scene_Choice::reset()
{
    Scene_Choice::chosen = 0;
    Scene_Choice::chose_url = "";
}
