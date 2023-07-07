#ifndef WARNING_H
#define WARNING_H

#pragma once

#include <QDialog>
#include <QString>
#include <QLabel>

#include "button.h"

class Warning : public QDialog
{
    Q_OBJECT
public:
    explicit Warning(const QString &_warning, QWidget *parent = nullptr);
    ~Warning();

    Button *back;

    QLabel *text;

};

#endif // WARNING_H
