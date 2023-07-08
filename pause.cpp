#include "pause.h"

Pause::Pause(GameWindow* _ui, QGraphicsScene *menu): QDialog(nullptr)
{
    this->setFixedSize(400, 400);

    // record the parent
    _menu = menu;

    // record the menu
    ui = _ui;

    label = new QLabel(this);
    label->setPixmap(QPixmap(":/resource/Background/pause.png"));

    // title text
    title_text = new QLabel(this);
    title_text->setText("暂     停");
    title_text->setFont(QFont("KaiTi", 30));
    title_text->setAlignment(Qt::AlignCenter);
    title_text->move(110, 70);

    // buttons
    back_to_game = new Button("返回游戏", this);
    back_to_game->move(150, 175);

    back_to_menu = new Button("返回菜单", this);
    back_to_menu->move(150, 325);

    music_state = new Button(Music_Property::music_state[Music_Property::music], this);
    music_state->move(150, 250);

    connect(back_to_game, &QPushButton::clicked, this, &QDialog::close);
    connect(back_to_menu, &QPushButton::clicked, this, &Pause::go_back_to_menu);
    connect(music_state, &QPushButton::clicked, this, &Pause::change_music);
}

void Pause::go_back_to_menu()
{
    ui->set_scene(_menu);
    this->close();
}

void Pause::change_music()
{
    Music_Property::music ^= 1;
    music_state->setText(Music_Property::music_state[Music_Property::music]);
    ui->change_music_state();
}

Pause::~Pause()
{
    delete title_text;
    delete back_to_game;
    delete back_to_menu;
}
