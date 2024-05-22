#ifndef BALA_H
#define BALA_H
#include<QGraphicsRectItem>
#include<QObject>

class Bala :public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Bala();

public slots:
    void movimiento();

};

#endif // BALA_H
