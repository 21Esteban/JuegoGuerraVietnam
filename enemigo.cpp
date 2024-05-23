#include "enemigo.h"
#include<QTimer>
#include<QDebug>

Enemigo::Enemigo(QObject *parent)
    :  QObject{parent}, Personaje()
{
    //hacemos que el enemigo aparezca posicionado por la derecha y se mueva hacia la izquierda

   // setPos(1280,y()+80);

    //CREAMOS EL DISEÑO DE EL ENEMIGO
    setRect(1280,470,100,100);

    //LO QUE VAMOS A HACER AQUI ES HACER EMITIR UNA SEÑAL CADA CIERTO TIEMPO CON LA LIBRERIA QTimer
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    //iniciamos el temporizador
    timer->start(20);
}



void Enemigo::move()
{
    //movemos al enemigo
    setPos(x()-2,y());



}
