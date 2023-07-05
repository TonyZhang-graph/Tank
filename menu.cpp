#include "menu.h"

Menu::Menu(QWidget *parent) : QGraphicsScene{parent}
{
    // record the ui
//    ui = _ui;

    // set background image
    QPixmap bg_img(":/resource/Environment/sand.png");
    background = new QGraphicsPixmapItem[49];
    QGraphicsPixmapItem *p_background = background;
    for(int i = 0; i < 49; ++i, ++p_background){
        p_background->setPixmap(bg_img);
        this->addItem(p_background);
        p_background->setPos((i % 7) << 7, (i / 7) << 7);
    }

    // set title text
    title_text = new QGraphicsTextItem("Tank Battle");
    title_text->setFont(QFont("KaiTi", 50));
    title_text->setPos(320, 200);
    this->addItem(title_text);

    // set buttons
    QString style = QString("QPushButton{height: 30px; width: 100px; background: url(:/resource/Buttons/button_2.png); text-align: center; color: white;}"
                            "QPushButton:hover {background-color: red;}"
                            "QPushButton:pressed {background-color: yellow;}");

    _m1_btn = new QPushButton("击杀模式");
    _m1_btn->setStyleSheet(style);
    m1_btn = this->addWidget(_m1_btn);
    m1_btn->setPos(390, 300);

    _m2_btn = new QPushButton("夺旗模式");
    _m2_btn->setStyleSheet(style);
    m2_btn = this->addWidget(_m2_btn);
    m2_btn->setPos(390, 375);

    _m3_btn = new QPushButton("踢球模式");
    _m3_btn->setStyleSheet(style);
    m3_btn = this->addWidget(_m3_btn);
    m3_btn->setPos(390, 450);

    _instr_btn = new QPushButton("游戏帮助");
    _instr_btn->setStyleSheet(style);
    instr_btn = this->addWidget(_instr_btn);
    instr_btn->setPos(390, 525);

    _msc_btn = new QPushButton(Music_Property::music_state[Music_Property::music]);
    _msc_btn->setStyleSheet(style);
    msc_btn = this->addWidget(_msc_btn);
    msc_btn->setPos(390, 600);

    _exit_btn = new QPushButton("退出游戏");
    _exit_btn->setStyleSheet(style);
    exit_btn = this->addWidget(_exit_btn);
    exit_btn->setPos(390, 670);

    // connet signals and slots
    connect(_exit_btn, &QPushButton::clicked, this, &QGraphicsScene::clear);
    connect(_instr_btn, &QPushButton::clicked, this, &Menu::show_instruction_box);
    connect(_msc_btn, &QPushButton::clicked, this, &Menu::change_music);
    connect(_m1_btn, &QPushButton::clicked, this, &Menu::start_mode_1);
    connect(_m2_btn, &QPushButton::clicked, this, &Menu::start_mode_2);
    connect(_m3_btn, &QPushButton::clicked, this, &Menu::start_mode_3);
}

void Menu::show_instruction_box()
{
    Instruction::get_instance()->exec();
}

void Menu::start_mode_1()
{
    qDebug() << "mode 1 to be completed";
}

void Menu::start_mode_2()
{
    qDebug() << "mode 2 to be completed";
}

void Menu::start_mode_3()
{
    qDebug() << "mode 3 to be completed";
}

void Menu::change_music()
{
    Music_Property::music ^= 1;
    _msc_btn->setText(Music_Property::music_state[Music_Property::music]);
}

Menu::~Menu()
{
    delete []background;
    delete title_text;
    delete _m1_btn, _m2_btn, _m3_btn;
    delete _instr_btn, _msc_btn, _exit_btn;
    delete m1_btn, m2_btn, m3_btn;
    delete instr_btn, msc_btn, exit_btn;
}
