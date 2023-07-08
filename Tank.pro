QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ball.cpp \
    bullet.cpp \
    button.cpp \
    choice_box_base.cpp \
    conquer_mode.cpp \
    fight_tank.cpp \
    instruction.cpp \
    kill_mode.cpp \
    main.cpp \
    gamewindow.cpp \
    map.cpp \
    menu.cpp \
    mode_choice.cpp \
    music.cpp \
    palse.cpp \
    scene_choice.cpp \
    score_board.cpp \
    select.cpp \
    soccer_mode.cpp \
    soccer_tank.cpp \
    tank_choice.cpp \
    tankbase.cpp \
    tile.cpp \
    warning.cpp \
    window.cpp

HEADERS += \
    ball.h \
    bullet.h \
    button.h \
    choice_box_base.h \
    conquer_mode.h \
    fight_tank.h \
    gamewindow.h \
    instruction.h \
    kill_mode.h \
    map.h \
    menu.h \
    mode_choice.h \
    music.h \
    palse.h \
    scene_choice.h \
    score_board.h \
    select.h \
    soccer_mode.h \
    soccer_tank.h \
    tank_choice.h \
    tankbase.h \
    tile.h \
    warning.h \
    window.h

FORMS += \
    gamewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
