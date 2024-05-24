#ifndef PERSONAJE_H
#define PERSONAJE_H

//como quiero hacer una herencia para poder hacer una figura geometrica que me represente el personaje , voy a heredar cosas
//de la clase
#include<QGraphicsPixmapItem>
//#include <QKeyEvent>
#include<QObject>

//esta es la clase padre , esta clase va a heredar jugador y enemigos
class Personaje : public QGraphicsPixmapItem{

public:
    Personaje();
};

#endif // PERSONAJE_H
