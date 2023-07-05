#include "instruction.h"

Instruction::Instruction() : QDialog(nullptr)
{
    this->resize(786, 786);

    const QString intro = "坦克大战是一款爆火的游戏";

    // back button
    back = new QPushButton("返回菜单", this);
    back->setGeometry(350, 700, 100, 50);
    connect(back, &QPushButton::clicked, this, &QDialog::close);

    // instruction text
    instr = new QLabel(this);
    instr->setText(intro);
    instr->setAlignment(Qt::AlignCenter);
    instr->move(300, 300);
}

Instruction* Instruction::p_instance = nullptr;

QPushButton* Instruction::back = nullptr;

QLabel* Instruction::instr = nullptr;

Instruction* Instruction::get_instance()
{
    return Instruction::p_instance == nullptr ? Instruction::p_instance = new Instruction : Instruction::p_instance;
}
