#include "plataforma.h"
#include <QPen>
#include <QBrush>

Plataforma::Plataforma(QObject *parent)
    : QObject{parent} , QGraphicsRectItem(0,570,1280,720)
{
    setPen(QPen(Qt::black));
    setBrush(QBrush(Qt::green));

}
