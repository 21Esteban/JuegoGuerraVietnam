#ifndef PIEDRA_H
#define PIEDRA_H

#include <QObject>
#include<QGraphicsPixmapItem>
class Piedra : public QObject ,  public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Piedra(QObject *parent = nullptr);

signals:
};

#endif // PIEDRA_H
