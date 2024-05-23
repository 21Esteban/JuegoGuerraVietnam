#include "bala.h"
#include<QTimer>
#include <QGraphicsScene>
#include<QDebug>
#include "enemigo.h"
//para loas colisiones
#include<QList>

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
    //si la bala colisiona con un enemigo destruimos ambos

    //creamos una lista de elemtos

    QList<QGraphicsItem *> elementos_colisionados = collidingItems();

    //vamos a recorrer la lista

    for(int i = 0 , n = elementos_colisionados.size() ; i < n ; i++){
        //vamos a checkear el id
        if(typeid(*(elementos_colisionados[i])) == typeid(Enemigo)){
            //eliminamos ambos elementos
            scene()->removeItem(elementos_colisionados[i]);
            scene()->removeItem(this);

            //eliminamos la memoria
            delete elementos_colisionados[i];
            delete this;
            return;
        }

    }

    this->setPos(x()+10,y());

    //si la posicion de la bala es mayor que la de el ancho de la escena entonces eliminamos la bala para liberar memoria
    if(pos().x() > scene()->width()){
        scene()->removeItem(this);
        delete this;
        qDebug()<<"bala eliminada correctamente";
    }
}
