#ifndef CHOICE_BOX_BASE_H
#define CHOICE_BOX_BASE_H

#pragma once

#include <QPushButton>
#include <QString>
#include <QMouseEvent>

class Choice_Box_Base : public QPushButton
{
    Q_OBJECT
public:
    explicit Choice_Box_Base(const QString& _img_url, QWidget *parent = nullptr);

    virtual~Choice_Box_Base();

    qint8 be_chosen;

    QString img_url;

    static QString default_style;
};

#endif // CHOICE_BOX_BASE_H
