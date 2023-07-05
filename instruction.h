#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QString>

class Instruction : public QDialog
{
    Q_OBJECT
private:
    explicit Instruction();

    // one instance mode
    static Instruction* p_instance;

    // back button
    static QPushButton* back;

    // instruction text
    static QLabel* instr;

public:
    // one instance API
    static Instruction* get_instance();
};

#endif // INSTRUCTION_H
