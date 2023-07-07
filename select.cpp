#include "select.h"

Select::Select(GameWindow *_ui, QGraphicsScene *_menu, QObject *parent) : QGraphicsScene{parent}
{
    // record the menu
    menu = _menu;

    // record the ui
    ui = _ui;

    // initialize the record
    game = nullptr;

    // load background
    QPixmap bg_img(":/resource/Environment/sky.png");
    background = new QGraphicsPixmapItem[49];
    QGraphicsPixmapItem *p_background = background;
    for(int i = 0; i < 49; ++i, ++p_background)
    {
        p_background->setPixmap(bg_img);
        this->addItem(p_background);
        p_background->setPos((i % 7) << 7, (i / 7) << 7);
    }

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
    _dirt = new Scene_Choice(":/resource/Environment/dirt.png");
    _sand = new Scene_Choice(":/resource/Environment/sand.png");
    _grass = new Scene_Choice(":/resource/Environment/grass.png");

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
    _conquer = new Mode_Choice("夺棋模式");

    kill = this->addWidget(_kill);
    kick = this->addWidget(_kick);
    conquer = this->addWidget(_conquer);

    kill->setPos(275, 200);
    kick->setPos(400, 200);
    conquer->setPos(525, 200);

    // text
    title = new QGraphicsTextItem("选择模式、坦克与地图");
    this->addItem(title);
    title->setFont(QFont("KaiTi", 30));
    title->setPos(300, 100);

    instr_l = new QGraphicsTextItem("红色边框为1P\n黄色边框为2P\n1P使用WASDQ键操控\n2P使用IJKLU键操控");
    this->addItem(instr_l);
    instr_l->setFont(QFont("KaiTi", 15, -1, true));
    instr_l->setPos(100, 400);

    instr_r = new QGraphicsTextItem("左键点击选择/取消1P\n右键点击/取消2P\n左键点击选择/取消地图\n左键点击选择/取消模式");
    this->addItem(instr_r);
    instr_r->setFont(QFont("KaiTi", 15, -1, true));
    instr_r->setPos(650, 400);
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
    else
    {
        // to be completed
        ui->set_scene(new GameScene(ui, menu, Scene_Choice::chose_url, Tank_Choice::chose_url));
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

