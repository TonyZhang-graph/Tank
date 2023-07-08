#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#pragma once

#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QBrush>

#include "button.h"

class Instruction : public QDialog
{
    Q_OBJECT
private:
    explicit Instruction();

    // one instance mode
    static Instruction* p_instance;

    // back button
    static Button *back;

    // instruction text
    static QLabel *instr;
    static QLabel *label;

public:
    // one instance API
    static Instruction* get_instance();
};

#endif // INSTRUCTION_H
