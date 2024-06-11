#include "game.h"
#include <QTimer>
#include<QImage>
#include"fondomovido.h"

Game::Game(QWidget *parent)
    : QGraphicsView(parent)
{
    //creamos una escena
     escena = new QGraphicsScene();

    //acomodamos el centrado de la escena
     escena->setSceneRect(0,0,1280,720);
     setBackgroundBrush(QBrush(QImage(":/imagenes/fondo2.jpg").scaled(1280, 720)));

     setScene(escena);

    //COMO NO QUEREMOS QUE HAYA EL SCROLLBAR ENTONCES LOS QUITAMOS
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //establecemos el tamaño de la vista
    setFixedSize(1280,720);
   // fondoMovido = new FondoMovido(":/imagenes/fondo2.jpg", ":/imagenes/fondo2.jpg"); // Usamos la misma imagen 2 veces
   // escena->addItem(fondoMovido);
   // fondoMovido->startMoving();


    //creamos nuestroPersonaje principal
     player = new Player();
    //modificamos las propiedades de nuestro personaje
   // player->setRect(0,0,100,100);
     //Ahora acomodamos la posicion de nuestro player
     player->setPos(100, 720-130);
    //hacemos que nuestro personaje sea centrado o focusable para que ese objeto obtenga info de las teclas presionadas
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    this->enemigosSpawneados = 0;

    //agregamos nuestro personaje a la escena
    escena->addItem(player);

    //creamos una plataforma
    //plataforma = new Plataforma();

    //creamos nuestras vidas
    vida = new Vida();
    //acomodamos nuestro corazon en la escena
    vida->setPos(x() + 5, y()+5);

    //añadimos la plataforma a nuestra escena y las vidas
   // escena->addItem(plataforma);
    escena->addItem(vida);

    //creamos el obstaculo que en este caso va a ser la piedra
    piedra = new Piedra();
    //acomodamos nuestra piedra en la escena
    piedra->setPos(150,720-120);
    escena->addItem(piedra);
    //creamos la vista|

    //QGraphicsView *view = new QGraphicsView(escena);

    //spawm enemigos como quiero que los enemigos aparezcan en un rango limite de 2 min y que en esos 2 minutos su aparicion sea random
    timer = new QTimer();
        QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
        timer->start(2000);
       // timer->start(QRandomGenerator::global()->bounded(2000, 60000)); // Intervalo aleatorio entre 3000 y 120000 milisegundos (3 y 120 segundos)




    //mostramos la vista
    show();

    //todo: Implementar el movimiento parabolico para el salto del personaje

}

void Game::incrementarNumEnemigos()
{
    this->enemigosSpawneados++;
}

int Game::getNumeroDeEnemigos()
{
    return this->enemigosSpawneados;
}

void Game::generarEnemigos()
{

}
