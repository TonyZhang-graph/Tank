#ifndef MODE_CHOICE_H
#define MODE_CHOICE_H

#include <QPushButton>
#include <QString>
#include <QMouseEvent>

class Mode_Choice : public QPushButton
{
    Q_OBJECT
public:
    explicit Mode_Choice(const QString &_mode_name, QWidget *parent = nullptr);

    // change the state when chosen
    void mousePressEvent(QMouseEvent *event) override;

    QString mode_name;

    static bool chosen;

    static QString chose_type;

    // reset the chosen state
    static void reset();

private:
    bool be_chosen;

    static QString chosen_style, default_style;
};

#endif // MODE_CHOICE_H
