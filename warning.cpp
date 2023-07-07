#include "warning.h"

Warning::Warning(const QString &_warning, QWidget *parent) :QDialog(parent)
{
    this->setFixedSize(400, 200);
    back = new Button("确定", this);
    back->move(150, 125);

    connect(back, &QPushButton::clicked, this, &QDialog::close);

    text = new QLabel(_warning, this);
    text->move(165, 50);
}

Warning::~Warning()
{
    delete back, delete text;
}
