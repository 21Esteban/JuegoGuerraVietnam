#ifndef BALA_H
#define BALA_H
#include<QGraphicsPixmapItem>
#include<QObject>

class Bala :public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bala(bool IsBulletFromPlayer);

public slots:
    void movimiento();

private:

    bool IsBulletFromPlayer;

};

#endif // BALA_H
