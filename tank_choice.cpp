#include "tank_choice.h"

Tank_Choice::Tank_Choice(const QString &img_url, QWidget *parent) : Choice_Box_Base(img_url, parent) {}

bool Tank_Choice::chosen[2] = {0, 0};

QString Tank_Choice::chosen_style[2] = {QString("QPushButton{background-color: red;}"), QString("QPushButton{background-color: yellow;}")};

QString Tank_Choice::chose_url[2] = {"", ""};

void Tank_Choice::mousePressEvent(QMouseEvent *event)
{
    // record the style that will be shown
    qint8 index = -1;

    switch(event->button())
    {
    case Qt::LeftButton:
        index = 0;
        break;

    case Qt::RightButton:
        index = 1;
        break;

    default:
        break;
    }

    if(index == -1)
    {
        return;
    }

    if(be_chosen != -1)
    {
        if(be_chosen != index)
        {
            return;
        }
        this->setStyleSheet(default_style);
        be_chosen = -1, chosen[index] = 0;
        chose_url[index] = "";
        return;
    }

    if(chosen[index])
    {
        return;
    }
    this->setStyleSheet(chosen_style[index]);
    be_chosen = index, chosen[index] = 1;
    chose_url[index] = img_url;
}

void Tank_Choice::reset()
{
    Tank_Choice::chosen[0] = Tank_Choice::chosen[1] = 0;
    Tank_Choice::chose_url[0] = Tank_Choice::chose_url[1] = "";
}
