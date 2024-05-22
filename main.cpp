#include "widget.h"
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsRectItem>
//#include "personaje.h"
#include "jugador.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //creamos una escena
    QGraphicsScene *escena = new QGraphicsScene();

    //creamos nuestroPersonaje principal
    Jugador *jugador = new Jugador();
    //modificamos las propiedades de nuestro personaje
    jugador->setRect(0,0,100,100);

    //agregamos nuestro personaje a la escena
    escena->addItem(jugador);

    //hacemos que nuestro personaje sea centrado o focusable para que ese objeto obtenga info de las teclas presionadas
    jugador->setFlag(QGraphicsItem::ItemIsFocusable);
    jugador->setFocus();


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

    //Ahora acomodamos la posicion de nuestro jugador
    jugador->setPos(100, view->height()-jugador->rect().height()-70);

    //todo: Implementar el movimiento parabolico para el salto del personaje

    return a.exec();
}
