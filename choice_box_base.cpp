#include "choice_box_base.h"

Choice_Box_Base::Choice_Box_Base(const QString &_img_url, QWidget *parent): QPushButton(parent)
{
    img_url = _img_url;

    this->setFixedSize(100, 100);
    this->setIcon(QIcon(img_url));
    this->setIconSize(QSize(93, 93));
    this->setStyleSheet(default_style);

    be_chosen = -1;
}

QString Choice_Box_Base::default_style = QString("QPushButton{background-color: white; text-align:center; color: white; }"
                                                 "QPushButton:hover{background-color: grey;}");

Choice_Box_Base::~Choice_Box_Base(){}
