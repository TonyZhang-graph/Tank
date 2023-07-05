#include "palse.h"

Palse::Palse(QGraphicsScene *parent): QDialog(nullptr)
{
    this->setFixedSize(786, 786);

    // record the parent
    _parent = parent;

    // title text
    title_text = new QLabel(this);
    title_text->setText("暂     停");
    title_text->setFont(QFont("Microsoft yahei", 15));
    title_text->setAlignment(Qt::AlignCenter);
    title_text->move(350, 100);

    // buttons
    back_to_game = new QPushButton("返回游戏", this);
    back_to_game->move(350, 400);
    back_to_menu = new QPushButton("返回菜单", this);
    back_to_menu->move(350, 500);
    music_state = new QPushButton(Music_Property::music_state[Music_Property::music], this);
    music_state->move(350, 600);
    connect(back_to_game, &QPushButton::clicked, this, &QDialog::close);
    connect(back_to_menu, &QPushButton::clicked, this, &Palse::go_back_to_menu);
    connect(music_state, &QPushButton::clicked, this, &Palse::change_music);
}

void Palse::go_back_to_menu()
{
    this->close();
    _parent->clear();

    // here is the code to open the menu

}

void Palse::change_music()
{
    Music_Property::music ^= 1;
    music_state->setText(Music_Property::music_state[Music_Property::music]);
}

Palse::~Palse()
{
    delete title_text;
    delete back_to_game;
    delete back_to_menu;
}
