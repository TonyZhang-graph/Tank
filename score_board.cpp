#include "score_board.h"

Score_Board::Score_Board(const qint8 &target_score, QWidget *parent) : QLabel(parent)
{
    score[0] = score[1] = 0;
    target = target_score;

    this->setFixedSize(50, 50);
    this->setStyleSheet("QLabel{background-color: black; text-align: center; color: white;}");
    this->setText(scores());
}

void Score_Board::gain_score(const qint8 &player)
{
    ++score[player];
    this->setText(scores());
}

int Score_Board::game_over()
{
    return score[0] == target ? 1 : score[1] == target ? 2 : 0;
}

QString Score_Board::scores()
{
    return QString(" 1P : 2P\n"
                   "  %1  : %2").arg(score[0]).arg(score[1]);
}
