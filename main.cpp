#include "widget.h"
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsRectItem>
//#include "personaje.h"
#include "player.h"
#include <QTimer>
#include <QApplication>
#include<QObject>
#include"player.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //creamos una escena
    QGraphicsScene *escena = new QGraphicsScene();

    //creamos nuestroPersonaje principal
    Player *player = new Player();
    //modificamos las propiedades de nuestro personaje
    player->setRect(0,0,100,100);

    //agregamos nuestro personaje a la escena
    escena->addItem(player);

    //hacemos que nuestro personaje sea centrado o focusable para que ese objeto obtenga info de las teclas presionadas
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();


    //creamos la vista

    QGraphicsView *view = new QGraphicsView(escena);

    //COMO NO QUEREMOS QUE HAYA EL SCROLLBAR ENTONCES LOS QUITAMOS

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //mostramos la vista
    view->show();

    //establecemos el tamaño de la vista
    view->setFixedSize(1280,720);

    //acomodamos el centrado de la escena
    escena->setSceneRect(0,0,1280,720);

    //Ahora acomodamos la posicion de nuestro player
    player->setPos(100, view->height()-player->rect().height()-150);


    //todo: Implementar el movimiento parabolico para el salto del personaje




    //spawm enemigos
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    return a.exec();
}
