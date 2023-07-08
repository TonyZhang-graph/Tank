#include "instruction.h"

Instruction::Instruction() : QDialog(nullptr)
{
    this->resize(786, 786);
    label = new QLabel(this);
    label->setPixmap(QPixmap(":/resource/Background/intro.png"));

    const QString intro = "\n\n\n\n    本游戏由三个桩子组出品（bushi）  \n"
                          "    这是一款双人坦克对战小游戏。\n"
                          "    游戏分为三个模式：击杀模式、夺旗模式和踢球模式。  \n"
                          "    击杀模式：双方需要击败对手达到一定数量才能够取得胜利。\n"
                          "    夺旗模式：双方需要在规定时间内占领旗帜，先达25者胜利。\n"
                          "    踢球模式：双方需要将球踢入对方球门一定次数才能获胜。\n"
                          "\n"
                          "    在这个游戏中，玩家可以选择三种坦克，分别为：\n"
                          "    红色坦克：移速慢，血量高。\n"
                          "    蓝色坦克：移速快，血量少。\n"
                          "    绿色坦克：移速和血量均中等。\n"
                          "\n"
                          "    游戏操作模式为：\n"
                          "    1P玩家使用WASDQ操控坦克，2P玩家使用IJKLU操控坦克。\n"
                          "    Q与U发射子弹，WS与IK控制前后移动，AD与JL控制左右转动。    \n"
                          "\n"
                          "    共有三种游戏场景可以选择，分别是泥地、沙地、草地。\n"
                          "\n"
                          "    本游戏使用音乐取自酷狗音乐（谢谢投喂谢谢投喂），\n"
                          "    如有侵权请联系告知。\n"
                          "    祝您游戏愉快！\n\n\n\n";

    // instruction text
    instr = new QLabel(this);
    instr->setText(intro);
    instr->setStyleSheet("QLabel {color: blue; background-color: rgba(255, 255, 255, 100);backdrop-filter: blur(5px); }");
    instr->setFont(QFont("KaiTi",20));
    instr->setAlignment(Qt::AlignLeft);
    instr->move(0, 0);

    // back button
    back = new Button("返回菜单", this);
    back->setGeometry(350, 700, 100, 50);
    connect(back, &QPushButton::clicked, this, &QDialog::close);


}

Instruction* Instruction::p_instance = nullptr;

Button *Instruction::back = nullptr;

QLabel *Instruction::instr = nullptr;

QLabel *Instruction::label = nullptr;

Instruction* Instruction::get_instance()
{
    return Instruction::p_instance == nullptr ? Instruction::p_instance = new Instruction : Instruction::p_instance;
}
