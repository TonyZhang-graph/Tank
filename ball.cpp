#include "ball.h"

qreal Ball::convert = acos(0) / 90;

Ball::Ball(QGraphicsItem *_walls[], Soccer_Tank **_tank)
{
    walls = _walls;
    speed = 1;
    tank = _tank;

    qreal centerX = 200;
    qreal centerY = 50;
    qreal radius = 20;
    qreal heading = 90;

    QPixmap img(":/resource/Ball/SoccerBall.png");
    img = img.scaled(2 * radius, 2 * radius, Qt::KeepAspectRatioByExpanding);
    item = new QGraphicsPixmapItem(img);
    item->setPos(centerX - radius, centerY - radius); // 设置位置

    vx = sin(heading * convert) * speed;
    vy = -cos(heading * convert) * speed;

    // set rotation
    item->setTransformOriginPoint(item->boundingRect().center());
    item->setRotation(heading);
}

bool Ball::collide_with_walls() {

    for (int i = 0; walls[i] != nullptr; ++i)
    {
        if (item->collidesWithItem(walls[i]))
        {
            return true;
        }
    }
    return false;
}
bool Ball::collide_with_line(const QLineF &line)
{
    QGraphicsLineItem l(line);
    return item->collidesWithItem(&l);
}

void Ball::refresh()
{
    item->setPos(item->x() + vx, item->y() + vy);

    for (int i = 0; walls[i] != nullptr; ++i)
    {
        if (item->collidesWithItem(walls[i]))
        {
            QRectF wallRect = walls[i]->boundingRect();

            QLineF topEdge(wallRect.topLeft(), wallRect.topRight());
            QLineF rightEdge(wallRect.topRight(), wallRect.bottomRight());
            QLineF bottomEdge(wallRect.bottomRight(), wallRect.bottomLeft());
            QLineF leftEdge(wallRect.bottomLeft(), wallRect.topLeft());

            if (collide_with_line(topEdge))
            {
                reflect(topEdge);
                break;
            }
            if (collide_with_line(rightEdge))
            {
                reflect(rightEdge);
                break;
            }
            if (collide_with_line(bottomEdge))
            {
                reflect(bottomEdge);
                break;
            }
            if (collide_with_line(leftEdge))
            {
                reflect(leftEdge);
                break;
            }
        }
    }

    for(int i = 0; i < 2; ++i)
    {
        if(item->collidesWithItem(tank[i]->item))
        {
            QPointF top_left(tank[i]->item->mapToScene(tank[i]->item->boundingRect().topLeft()));
            QPointF top_right(tank[i]->item->mapToScene(tank[i]->item->boundingRect().topRight()));
            QPointF bottom_left(tank[i]->item->mapToScene(tank[i]->item->boundingRect().bottomLeft()));
            QPointF bottom_right(tank[i]->item->mapToScene(tank[i]->item->boundingRect().bottomRight()));

            QLineF topEdge(top_left, top_right);
            QLineF rightEdge(top_right, bottom_right);
            QLineF bottomEdge(bottom_right, bottom_left);
            QLineF leftEdge(bottom_left, top_left);

            if (collide_with_line(topEdge))
            {
                reflect(topEdge);
            }
            else if (collide_with_line(rightEdge))
            {
                reflect(rightEdge);
            }
            else if (collide_with_line(bottomEdge))
            {
                reflect(bottomEdge);
            }
            else if (collide_with_line(leftEdge))
            {
                reflect(leftEdge);
            }
        }
    }

}


void Ball::reflect(const QLineF &a_wall)
{
    QLineF collisionNormal = a_wall.normalVector().unitVector();
    QPointF NormalVector = collisionNormal.p2() - collisionNormal.p1();
    item->setPos(item->pos() + 7 * NormalVector);

    QPointF bulletDirection(sin(item->rotation() * convert), -cos(item->rotation()* convert));

    QPointF p1(0,0);

    QLineF originDirection(p1,bulletDirection);
    qreal deltaAngle = 180 - 2 * originDirection.angleTo(collisionNormal);
    qreal newheading=item->rotation() + deltaAngle;

    while (newheading >= 360) newheading -= 360;
    while (newheading < 0) newheading += 360;

    vx =  sin(newheading * convert) * speed;
    vy = -cos(newheading * convert) * speed;
    item->setTransformOriginPoint(item->boundingRect().center());
    item->setRotation(newheading);
}
