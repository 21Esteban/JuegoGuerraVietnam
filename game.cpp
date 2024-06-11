#include "game.h"
#include <QTimer>
#include<QImage>
#include<enemigo.h>
#include<enemigo2.h>
Game::Game(QWidget *parent)
    : QGraphicsView(parent)
{
    //creamos una escena
     escena = new QGraphicsScene();
     nuevaEscena = new QGraphicsScene();

    //acomodamos el centrado de la escena
     escena->setSceneRect(0,0,1280,720);
     setBackgroundBrush(QBrush(QImage(":/imagenes/SPRITE/fondo2.jpg").scaled(1280, 720)));

     setScene(escena);

    //COMO NO QUEREMOS QUE HAYA EL SCROLLBAR ENTONCES LOS QUITAMOS
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //establecemos el tamaño de la vista
    setFixedSize(1280,720);
    //fondoMovido = new FondoMovido(":/imagenes/fondo2.jpg", ":/imagenes/fondo2.jpg"); // Usamos la misma imagen 2 veces
    //escena->addItem(fondoMovido);
    //fondoMovido->startMoving();


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
    crearYAgregarVidas();


    //creamos el obstaculo que en este caso va a ser la piedra
    piedra = new Piedra();
    //acomodamos nuestra piedra en la escena
    piedra->setPos(150,720-130);
    escena->addItem(piedra);
    //creamos la vista

    //QGraphicsView *view = new QGraphicsView(escena);

    //spawm enemigos como quiero que los enemigos aparezcan en un rango limite de 2 min y que en esos 2 minutos su aparicion sea random
    timer = new QTimer();
        QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
        timer->start(2000);
       // timer->start(QRandomGenerator::global()->bounded(2000, 60000)); // Intervalo aleatorio entre 3000 y 120000 milisegundos (3 y 120 segundos)





    //mostramos la vista
    show();

     connect(player, &Player::llegoAlFinalDeEscena, this, &Game::cambiarEscena);

}
void Game::crearYAgregarVidas()
{
    // Crear y agregar la vida a la escena
    vida = new Vida();
    vida->setPos(5, 5); // Ajustar la posición según sea necesario
    escena->addItem(vida);
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
        if (scene() == escena) {
            Enemigo *enemigo = new Enemigo();
            escena->addItem(enemigo);
        } else if (scene() == nuevaEscena) {
            Enemigo2 *enemigo2 = new Enemigo2();
            nuevaEscena->addItem(enemigo2);
        }
        incrementarNumEnemigos();


}

void Game::cambiarEscena()
{
    // Crear una nueva escena
    nuevaEscena = new QGraphicsScene();
    nuevaEscena->setSceneRect(0, 0, 1280, 720);
    setBackgroundBrush(QBrush(QImage(":/imagenes/SPRITE/fondo4.jpg").scaled(1280, 720)));

    // Cambiar a la nueva escena
    setScene(nuevaEscena);

    // Eliminar la escena anterior si no la necesitas más
    delete escena;



    escena = nullptr;
    player = nullptr;
    player1 = new Player();
    //modificamos las propiedades de nuestro personaje
    // player->setRect(0,0,100,100);
    //Ahora acomodamos la posicion de nuestro player
    player1->setPos(10, 720-280);
    //hacemos que nuestro personaje sea centrado o focusable para que ese objeto obtenga info de las teclas presionadas
    player1->setFlag(QGraphicsItem::ItemIsFocusable);
    player1->setFocus();

    // Agregar el jugador a la nueva escena
    nuevaEscena->addItem(player1);
    //creamos una plataforma
    //plataforma = new Plataforma();
    // Agregar la vida existente a la nueva escena
    vida = new Vida();
    //acomodamos nuestro corazon en la escena
    vida->setPos(x() + 5, y()+5);

    //añadimos la plataforma a nuestra escena y las vidas
    // escena->addItem(plataforma);
    nuevaEscena->addItem(vida);


    //creamos la vista
    //QGraphicsView *view = new QGraphicsView(escena);
    //spawm enemigos como quiero que los enemigos aparezcan en un rango limite de 2 min y que en esos 2 minutos su aparicion sea random
    // Continuar usando el mismo temporizador para generar enemigos
    disconnect(timer, &QTimer::timeout, this, &Game::generarEnemigos);
    connect(timer, &QTimer::timeout, this, &Game::generarEnemigos);
    timer->start(2000);


    // Mostrar la nueva escena
   //show();
}
