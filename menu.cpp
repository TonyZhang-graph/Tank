#include "menu.h"

Menu::Menu(GameWindow* _ui, QWidget *parent) : QGraphicsScene{parent}
{
    // record the ui
    ui = _ui;

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
    title_text = new QGraphicsTextItem("    Tank  Battle\n 双人坦克大战");
    title_text->setFont(QFont("KaiTi", 50));
    title_text->setPos(280, 170);
    this->addItem(title_text);

    // set buttons
    _ply_btn = new Button("开始游戏");
    ply_btn = this->addWidget(_ply_btn);
    ply_btn->setPos(390, 350);

    _instr_btn = new Button("游戏帮助");
    instr_btn = this->addWidget(_instr_btn);
    instr_btn->setPos(390, 425);

    _msc_btn = new Button(Music_Property::music_state[Music_Property::music]);
    msc_btn = this->addWidget(_msc_btn);
    msc_btn->setPos(390, 500);

    _exit_btn = new Button("退出游戏");
    exit_btn = this->addWidget(_exit_btn);
    exit_btn->setPos(390, 570);

    // connet signals and slots
    connect(_exit_btn, &QPushButton::clicked, ui, &GameWindow::close);
    connect(_instr_btn, &QPushButton::clicked, this, &Menu::show_instruction_box);
    connect(_msc_btn, &QPushButton::clicked, this, &Menu::change_music);
    connect(_ply_btn, &QPushButton::clicked, this, &Menu::start_game);
}

void Menu::show_instruction_box()
{
    Instruction::get_instance()->exec();
}

void Menu::start_game()
{
    ui->set_scene(new Select(ui, this));
}

void Menu::change_music()
{
    Music_Property::music ^= 1;
    _msc_btn->setText(Music_Property::music_state[Music_Property::music]);
    ui->change_music_state();
}

Menu::~Menu()
{
    delete []background;
    delete title_text;
    delete _ply_btn, _instr_btn, _msc_btn, _exit_btn;
    delete ply_btn, instr_btn, msc_btn, exit_btn;
}
