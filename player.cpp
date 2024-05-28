#include "player.h"
#include "bala.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "enemigo.h"
#include <QDebug>
#include "game.h"


extern Game * game;

Player::Player(QObject *parent)
    : QObject{parent} , Personaje()
{

    //agreagamos las animaciones a un arreglo que contiene las rutas de las imagenes que compondran nuestra animacion
    this->animaciones.push_back(animacionPath1);
    this->animaciones.push_back(animacionPath2);
    this->animaciones.push_back(animacionPath3);

    setPixmap(QPixmap(this->animaciones[0]).scaled(100,100,Qt::KeepAspectRatio));

    sonidoDisparo = new QSoundEffect();
    sonidoDisparo->setSource(QUrl("qrc:/sonidos/sonido2Acortado.wav"));
    //sonidoDisparo->setVolume(1);
    this->frame = 1 ;
    this->temporizadorAux = new QTimer();
    this->
    connect(temporizadorAux, &QTimer::timeout, this, &Player::cambiarImagenAlDisparar);
    //connect()

}

void Player::keyPressEvent(QKeyEvent *event)
{
    //qDebug() <<"acabas de presionar una tecla";
    if(event->key() == Qt::Key_Right || event->key() == Qt::Key_D){
        setPos(x()+10,y());

        this->frame = (this->frame + 1) % 3; // Esto hará que el frame se reinicie a 0 después de alcanzar 2

        setPixmap(QPixmap(this->animaciones[frame]).scaled(100,100,Qt::KeepAspectRatio));

    }else if(event->key() == Qt::Key_Left || event->key() == Qt::Key_A){
        if(pos().x()>0){
            setPos(x()-10,y());
        }

    }
    /* else if(event->key() == Qt::Key_Down){
        setPos(x(),y()+10);
    }  */  else if(event->key() == Qt::Key_Up || event->key() == Qt::Key_W ){
        setPos(x(),y()-10);
    }else if(event->key() == Qt::Key_Space){
        //si se le da al espacio, quiero hacer un disparo.
        Bala *bala = new Bala(true);
        //ya con la bala creada queremos que aparezca un poquito adelante del personaje
        bala->setPos(x()+70,y() + 24);
        //ahora que creamos la bala ,debemos de añadirla a la escena
        scene()->addItem(bala);
        //cambiamos la imagen en momento del disparo
        setPixmap(QPixmap(":/imagenes/disparandoSinFondo.png").scaled(100,100,Qt::KeepAspectRatio));
        //repdroducimos el sonido del disparo
        sonidoDisparo->play();
        //volvemos a cambiar a la imagen predeterminada despues del disparo
        this->temporizadorAux->start(100);

    }
}

void Player::spawn()
{
    game->incrementarNumEnemigos();
    //creamos un enemigo pero si hay mas de 3 enemigos no generamos mas enemigos haciendo la desconexion para dejar de emitir una señal
    if (game->getNumeroDeEnemigos() > 3){
        QObject::disconnect(game->timer, SIGNAL(timeout()), this, SLOT(spawn()));
       // QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    }
    Enemigo *enemigo = new Enemigo();
    //enemigo->setPos(1280,y()+70);
    scene()->addItem(enemigo);
    qDebug() <<"Enemigo añadido";
    //acedemos a game y sumamos uno a enemigo añadido llamando al metodo creado




}


void Player::cambiarImagenAlDisparar() {
    setPixmap(QPixmap(":/imagenes/movimiento1SinFondo.png").scaled(100,100,Qt::KeepAspectRatio));
    temporizadorAux->stop();
}

void Player::actualizarAnimacion()
{
    // Cambiar la imagen de acuerdo al frame
    if (frame == 1) {
        setPixmap(QPixmap(":/imagenes/movimiento2SinFondo.png").scaled(100, 100, Qt::KeepAspectRatio));
        frame = 2;
    } else if (frame == 2) {
        setPixmap(QPixmap(":/imagenes/movimiento3SinFondo.png").scaled(100, 100, Qt::KeepAspectRatio));
        frame = 3;
    } else if (frame == 3) {
        setPixmap(QPixmap(":/imagenes/movimiento1SinFondo.png").scaled(100, 100, Qt::KeepAspectRatio));
        frame = 1;
    }
}

