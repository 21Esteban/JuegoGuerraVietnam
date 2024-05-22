#include "bala.h"
#include<QTimer>
#include <QGraphicsScene>
#include<QDebug>

Bala::Bala() {
    //CREAMOS EL DISEÑO DE LA BALA
    setRect(0,0,50,10);

    //LO QUE VAMOS A HACER AQUI ES HACER EMITIR UNA SEÑAL CADA CIERTO TIEMPO CON LA LIBRERIA QTimer
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(movimiento()));

    //iniciamos el temporizador
    timer->start(20);
}

//metodo que hace el movimiento de la bala

void Bala::movimiento()
{
    this->setPos(x()+10,y());

    //si la posicion de la bala es mayor que la de el ancho de la escena entonces eliminamos la bala para liberar memoria
    if(pos().x() > scene()->width()){
        scene()->removeItem(this);
        delete this;
        qDebug()<<"bala eliminada correctamente";
    }
}
