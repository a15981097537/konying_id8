#include "mygraphicsitem.h"

MyGraphicsItem::MyGraphicsItem()
{

}
QRectF MyGraphicsItem::boundingRect() const
{
    qreal adjust=0.5;
    return QRectF(-18-adjust,-22-adjust,36+adjust,60+adjust);
}

void MyGraphicsItem::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    painter->drawRect(0,0,200,200);
}
