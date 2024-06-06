#include "bala.h"
#include<QTimer>
#include <QGraphicsScene>
#include<QDebug>
#include "enemigo.h"
//para loas colisiones
#include<QList>
#include "player.h"
#include "game.h"

extern Game * game;

Bala::Bala(bool IsBulletFromPlayer) :QGraphicsPixmapItem() {
    this->IsBulletFromPlayer = IsBulletFromPlayer;
    //CREAMOS EL DISEÑO DE LA BALA
    setPixmap(QPixmap(":/imagenes/balaSinFondo.png").scaled(70,30,Qt::KeepAspectRatio));


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

    if(this->IsBulletFromPlayer){
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
    }else{
        for(int i = 0 , n = elementos_colisionados.size() ; i < n ; i++){
            //vamos a checkear el id
            if(typeid(*(elementos_colisionados[i])) == typeid(Bala) ){
                //eliminamos ambos elementos
                scene()->removeItem(elementos_colisionados[i]);
                scene()->removeItem(this);

                //eliminamos la memoria
                delete elementos_colisionados[i];
                delete this;
                return;
            }
            else if(typeid(*(elementos_colisionados[i])) == typeid(Player)){
                qDebug()<<"Entre";
                scene()->removeItem(this);
                delete this;
                game->vida->decrease();
                qDebug()<<"sali";
                return;
            }

        }
    }



    if(this->IsBulletFromPlayer){
        this->setPos(x()+10,y());
    }else{
        this->setPos(x()-10,y());
    }


    //si la posicion de la bala es mayor que la de el ancho de la escena entonces eliminamos la bala para liberar memoria de la misma manera si la posicion es menor que 0 (se sale por el lado izquierdo) la eliminamos
    if(pos().x() > scene()->width() ||pos().x() < 0 ){
        scene()->removeItem(this);
        delete this;
        qDebug()<<"bala eliminada correctamente";
    }
}


