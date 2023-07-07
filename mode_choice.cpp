#include "mode_choice.h"

Mode_Choice::Mode_Choice(const QString &_mode_name, QWidget *parent) : QPushButton(parent)
{
    mode_name = _mode_name;

    this->setFixedSize(100, 100);
    this->setText(mode_name);
    this->setStyleSheet(default_style);
}

bool Mode_Choice::chosen = 0;

QString Mode_Choice::chosen_style = QString("QPushButton{background-color: white; text-align: center; color: black;}");

QString Mode_Choice::default_style = QString("QPushButton{background-color: black; text-align: center; color: white;}"
                                             "QPushButton:hover{background-color: grey; text-align: center; color: orange;}");

QString Mode_Choice::chose_type = "";

void Mode_Choice::mousePressEvent(QMouseEvent *event)
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
        chose_type = "";
    }
    else
    {
        this->setStyleSheet(chosen_style);
        be_chosen = chosen = 1;
        chose_type = mode_name.left(2);
    }
}

void Mode_Choice::reset()
{
    Mode_Choice::chosen = 0;
    Mode_Choice::chose_type = "";
}
