#include <palse.h>

palse::palse(QWidget *parent): QWidget(parent)
{
    this->setFixedSize(786, 786);

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
    connect(back_to_game, &QPushButton::clicked, this, &QDialog::close);
    connect(back_to_menu, &QPushButton::clicked, this, &palse::go_back_to_menu);
}

void palse::go_back_to_menu()
{

}
