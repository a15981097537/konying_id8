#ifndef MYGRAPHICSITEM_H
#define MYGRAPHICSITEM_H
#include <QPainter>
#include <QGraphicsItem>

//class MyGraphicsItem
//{
//public:
//    MyGraphicsItem();
//};


class MyGraphicsItem : public QGraphicsItem
{
    public:
    MyGraphicsItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
};


#endif // MYGRAPHICSITEM_H
