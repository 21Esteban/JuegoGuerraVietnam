#include "game.h"
#include <QTimer>
#include<QImage>

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





    //creamos nuestroPersonaje principal
     player = new Player();
    //modificamos las propiedades de nuestro personaje
   // player->setRect(0,0,100,100);
     //Ahora acomodamos la posicion de nuestro player
     player->setPos(100, 720-130);
    //hacemos que nuestro personaje sea centrado o focusable para que ese objeto obtenga info de las teclas presionadas
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();


    //agregamos nuestro personaje a la escena
    escena->addItem(player);




    //creamos una plataforma
    //plataforma = new Plataforma();

    //creamos nuestras vidas
    vida = new Vida();


    //añadimos la plataforma a nuestra escena y las vidas
   // escena->addItem(plataforma);
    escena->addItem(vida);
    //creamos la vista

    //QGraphicsView *view = new QGraphicsView(escena);

    //spawm enemigos
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    //mostramos la vista
    show();








    //todo: Implementar el movimiento parabolico para el salto del personaje





}
