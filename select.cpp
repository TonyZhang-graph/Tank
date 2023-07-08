#include "select.h"

Select::Select(GameWindow *_ui, QGraphicsScene *_menu, QObject *parent) : QGraphicsScene{parent}
{
    // record the menu
    menu = _menu;

    // record the ui
    ui = _ui;

    // load background
    background = new QGraphicsPixmapItem(QPixmap(":/resource/Background/war.png"));
    this->addItem(background);
    background->setPos(0, 0);

    // tank choices
    _tank_green = new Tank_Choice(":/resource/Tanks/tankGreen.png");
    _tank_blue = new Tank_Choice(":/resource/Tanks/tankBlue.png");
    _tank_red = new Tank_Choice(":/resource/Tanks/tankRed.png");

    tank_green = this->addWidget(_tank_green);
    tank_blue = this->addWidget(_tank_blue);
    tank_red = this->addWidget(_tank_red);

    tank_green->setPos(275, 500);
    tank_blue->setPos(400, 500);
    tank_red->setPos(525, 500);

    // scene choices
    _dirt = new Scene_Choice(":/resource/Environment/dirt.png", ":/resource/Maps/map_dirt.map");
    _sand = new Scene_Choice(":/resource/Environment/sand.png", ":/resource/Maps/map_sand.map");
    _grass = new Scene_Choice(":/resource/Environment/grass.png", ":/resource/Maps/map_grass.map");

    dirt = this->addWidget(_dirt);
    sand = this->addWidget(_sand);
    grass = this->addWidget(_grass);

    dirt->setPos(275, 350);
    sand->setPos(400, 350);
    grass->setPos(525, 350);

    // control buttons
    _back = new Button("返回菜单");
    back = this->addWidget(_back);
    back->setPos(325, 700);
    connect(_back, &QPushButton::clicked, this, &Select::go_to_menu);

    _go = new Button("开始游戏");
    go = this->addWidget(_go);
    go->setPos(475, 700);
    connect(_go, &QPushButton::clicked, this, &Select::go_to_game);

    // mode choice
    _kill = new Mode_Choice("击杀模式");
    _kick = new Mode_Choice("踢球模式");
    _conquer = new Mode_Choice("领地模式");

    kill = this->addWidget(_kill);
    kick = this->addWidget(_kick);
    conquer = this->addWidget(_conquer);

    kill->setPos(275, 200);
    kick->setPos(400, 200);
    conquer->setPos(525, 200);

    // text
    title = new QGraphicsTextItem("选择模式、坦克与地图");
    title->setDefaultTextColor(QColorConstants::Red);
    this->addItem(title);
    title->setFont(QFont("KaiTi", 30));
    title->setPos(245, 120);

    instr_l = new QGraphicsTextItem("红色边框为1P\n黄色边框为2P\n1P使用WASDQ键操控\n2P使用IJKLU键操控");
    instr_l->setDefaultTextColor(QColorConstants::Red);
    this->addItem(instr_l);
    instr_l->setFont(QFont("KaiTi", 15, -1, true));
    instr_l->setPos(80, 350);

    instr_r = new QGraphicsTextItem("左键点击选择/取消1P\n右键点击/取消2P\n左键点击选择/取消地图\n左键点击选择/取消模式");
    instr_r->setDefaultTextColor(QColorConstants::Red);
    this->addItem(instr_r);
    instr_r->setFont(QFont("KaiTi", 15, -1, true));
    instr_r->setPos(650, 350);
}

Select::~Select()
{
    delete background;
    delete _tank_green, delete _tank_blue, delete _tank_red;
    delete tank_green, delete tank_blue, delete tank_red;
    delete _sand, delete _dirt, delete _grass;
    delete sand, delete dirt, delete grass;
    delete _back, delete _go;
    delete back, delete go;
    delete instr_l, delete instr_r, delete title;
    delete _kill, delete _kick, delete _conquer;
    delete kill, delete kick, delete conquer;
}

void Select::go_to_game()
{
    if(!Scene_Choice::chosen || !Mode_Choice::chosen || !Tank_Choice::chosen[0] || !Tank_Choice::chosen[1])
    {
        Warning("未完成选择！").exec();
        return;
    }

    QString mode_chosen = Mode_Choice::chose_type;

    if(mode_chosen == "踢球")
    {
        ui->set_scene(new Soccer_Mode(ui, menu, Scene_Choice::chose_url, Tank_Choice::chose_url));
    }
    if(mode_chosen == "击杀")
    {
        ui->set_scene(new Kill_Mode(ui, menu, Scene_Choice::chose_url, Scene_Choice::map_url, Tank_Choice::chose_url));
    }
    if(mode_chosen == "领地")
    {
        ui->set_scene(new Conquer_Mode(ui, menu, Tank_Choice::chose_url, Scene_Choice::map_url));
    }

    Tank_Choice::reset();
    Scene_Choice::reset();
    Mode_Choice::reset();
}

void Select::go_to_menu()
{
    ui->set_scene(menu);
    Tank_Choice::reset();
    Scene_Choice::reset();
    Mode_Choice::reset();
}

