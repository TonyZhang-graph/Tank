#include "warning.h"

Warning::Warning(const QString &_warning, QWidget *parent) :QDialog(parent)
{
    this->setFixedSize(400, 200);

    this->setStyleSheet("QDialog{background: url(:/resource/Background/ball_in.png);}");

    back = new Button("确定", this);
    back->move(150, 125);

    connect(back, &QPushButton::clicked, this, &QDialog::close);

    text = new QLabel(_warning, this);
    text->setStyleSheet("QLabel {color: red; background-color: rgba(255, 255, 255, 100); backdrop-filter: blur(5px); }");
    text->setAlignment(Qt::AlignCenter);
    text->setFont(QFont("KaiTi",20));
    text->move(100, 20);
}

Warning::~Warning()
{
    delete back, delete text;
}
