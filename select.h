#ifndef SELECT_H
#define SELECT_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QGraphicsProxyWidget>

class Select :public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Select(QObject* parent = nullptr);
    ~Select();

private:
    QGraphicsPixmapItem *background;


    // choices


};

#endif // SELECT_H
