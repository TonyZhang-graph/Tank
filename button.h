#ifndef BUTTON_H
#define BUTTON_H

#pragma once

#include <QPushButton>
#include <QString>

class Button : public QPushButton
{
    Q_OBJECT
public:
    explicit Button( const QString &text, QWidget *parent = nullptr, const qint8 &length = 100, const qint8 &width = 50);
};

#endif // BUTTON_H
