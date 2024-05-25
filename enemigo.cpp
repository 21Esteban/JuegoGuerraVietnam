#include "enemigo.h"
#include<QTimer>
#include<QDebug>
#include "game.h"

extern Game * game;

Enemigo::Enemigo(QObject *parent)
    :  QObject{parent}, Personaje()
{
    //hacemos que el enemigo aparezca posicionado por la derecha y se mueva hacia la izquierda

    setPos(1280,720-130);

    //CREAMOS EL DISEÑO DE EL ENEMIGO
<<<<<<< HEAD
    setPixmap(QPixmap(":/imagenes/movimiento1SinFondo.png").transformed(QTransform().scale(-1,1)).scaled(100,100,Qt::KeepAspectRatio));
=======
   setPixmap(QPixmap(":/imagenes/movimiento1SinFondo.png").scaled(100,100,Qt::KeepAspectRatio));
>>>>>>> 55e9208a03054091bafb59fb219175125e1a86a6

    //LO QUE VAMOS A HACER AQUI ES HACER EMITIR UNA SEÑAL CADA CIERTO TIEMPO CON LA LIBRERIA QTimer
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    //iniciamos el temporizador
    timer->start(20);
}



void Enemigo::move()
{
    //movemos al enemigo
    setPos(x()-2,720-130);



}
