#include "button.h"

Button::Button(const QString &text, QWidget *parent, const qint8 &length, const qint8 &width) : QPushButton(parent)
{
    this->setText(text);
    this->setStyleSheet("QPushButton{background: url(:/resource/Buttons/button_1.png); color: white; text-align: center; color: white;}"
                        "QPushButton:hover{background-color: red;}"
                        "QPushButton:pressed{background-color: yellow;}");
    this->setFixedSize(length, width);
}
