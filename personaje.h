#ifndef PERSONAJE_H
#define PERSONAJE_H

//como quiero hacer una herencia para poder hacer una figura geometrica que me represente el personaje , voy a heredar cosas
//de la clase
#include<QGraphicsRectItem>
#include <QKeyEvent>


class Personaje : public QGraphicsRectItem{
public:
    Personaje();
    void keyPressEvent(QKeyEvent *event);
};

#endif // PERSONAJE_H
