#ifndef PALSE_H
#define PALSE_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>

class palse: public QDialog
{
    Q_OBJECT
public:
    explicit palse(QWidget* parent);
    ~palse();

private:
    // buttons
    QPushButton* back_to_game;
    QPushButton* back_to_menu;

    // title
    QLabel* title_text;

public slots:
    void go_back_to_menu();
};

#endif // PALSE_H
