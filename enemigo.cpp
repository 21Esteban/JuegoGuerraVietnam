#include "enemigo.h"
#include<QTimer>
#include<QDebug>
#include "game.h"
#include<QRandomGenerator>
#include "bala.h"

extern Game * game;

Enemigo::Enemigo(QObject *parent)
    :  QObject{parent}, Personaje()
{
    //hacemos que el enemigo aparezca posicionado por la derecha y se mueva hacia la izquierda

    setPos(1280,720-130);

    //CREAMOS EL DISEÑO DE EL ENEMIGO

    setPixmap(QPixmap(":/imagenes/movimiento1SinFondo.png").transformed(QTransform().scale(-1,1)).scaled(100,100,Qt::KeepAspectRatio));


    //cargamos el sonido de la bala

  /*  sonidoDisparo = new QSoundEffect();
    sonidoDisparo->setSource(QUrl("qrc:/sonidos/sonido2Acortado.wav"));*/


    //LO QUE VAMOS A HACER AQUI ES HACER EMITIR UNA SEÑAL CADA CIERTO TIEMPO CON LA LIBRERIA QTimer para ejecutar la funcion move que mueve a cada enemigo

    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    //iniciamos el temporizador
    timer->start(50);

    //ahora quiero que los enemigos disparen de forma aleatoria , en un intervalo de 10 segundos

    //para la generacion de la bala lo que voy a hacer es emitir una señal de creacion de bala cada cierto tiempo en un intervalo de 10 segundos
    QTimer *timer_disparo = new QTimer();
    connect(timer_disparo,SIGNAL(timeout()),this,SLOT(disparar()));

    timer_disparo->start(3000);

}

//ahora quiero que los enemigos comienzen caminando y que de la nada empiecen  a correr


void Enemigo::move()
{
    // Generamos un número aleatorio entre 0 y 1
    int decision = QRandomGenerator::global()->bounded(2);
    qDebug() <<decision;

    // Movemos al enemigo
    if (decision == 0) {
        // Si decision es 0, el enemigo camina
        setPos(x() - 2, 720 - 130);
    } else {
        // Si decision es 1, el enemigo corre
        setPos(x() - 10, 720 - 130);
    }




}

void Enemigo::disparar()
{
    //llamamos al constructor de bala para generar la bala
    Bala *bala = new Bala(false);
    //ya con la bala creada queremos que aparezca un poquito adelante del personaje
    bala->setPos(x()-30,y() + 24);
    //ahora que creamos la bala ,debemos de añadirla a la escena
    scene()->addItem(bala);
    //cambiamos la imagen en momento del disparo
   // setPixmap(QPixmap(":/imagenes/disparandoSinFondo.png").scaled(100,100,Qt::KeepAspectRatio));
    //repdroducimos el sonido del disparo
    //this->sonidoDisparo->play();
}
