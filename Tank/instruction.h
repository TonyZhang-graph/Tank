#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QString>

class instruction : public QDialog
{
    Q_OBJECT
private:
    explicit instruction();

    // one instance mode
    static instruction* p_instance;

    // back button
    static QPushButton* back;

    // instruction text
    static QLabel* instr;

public:
    // one instance API
    static instruction* get_instance();
};

#endif // INSTRUCTION_H
