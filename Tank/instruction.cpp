#include "instruction.h"

const QString intro = "坦克大战是一款爆火的游戏";

instruction::instruction() : QDialog(nullptr)
{
    this->resize(786, 786);

    // back button
    back = new QPushButton("返回", this);
    back->setGeometry(350, 700, 100, 50);
    connect(back, &QPushButton::clicked, this, &QDialog::close);

    // instruction text
    instr = new QLabel(this);
    instr->setText(intro);
    instr->setAlignment(Qt::AlignCenter);
    instr->move(300, 300);
}

instruction* instruction::p_instance = nullptr;

QPushButton* instruction::back = nullptr;

QLabel* instruction::instr = nullptr;

instruction* instruction::get_instance()
{
    if(instruction::p_instance == nullptr)
    {
        p_instance = new instruction;
    }
    return p_instance;
}
