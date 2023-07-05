#include <palse.h>

palse::palse(QGraphicsScene *parent): QDialog(nullptr)
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
    music_state = new QPushButton(Menu::music_state[Menu::music], this);
    music_state->move(350, 600);
    connect(back_to_game, &QPushButton::clicked, this, &QDialog::close);
    connect(back_to_menu, &QPushButton::clicked, this, &palse::go_back_to_menu);
}

void palse::go_back_to_menu()
{
    this->close();
    _parent->clear();

    // here is the code to open the menu

}

void palse::change_music()
{
    Menu::music ^= 1;
    music_state->setText(Menu::music_state[Menu::music]);
}

palse::~palse()
{
    delete title_text;
    delete back_to_game;
    delete back_to_menu;
}
