#ifndef SCORE_BOARD_H
#define SCORE_BOARD_H

#include <QLabel>
#include <QString>

class Score_Board : public QLabel
{
    Q_OBJECT
public:
    explicit Score_Board(const qint8 &target_score, QWidget *parent = nullptr);

    void gain_score(const qint8 &player);

    int game_over();

    QString scores();

private:
    qint8 score[2];

    qint8 target;
};

#endif // SCORE_BOARD_H
