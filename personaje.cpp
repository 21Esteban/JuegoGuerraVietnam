#include "personaje.h"
#include <QDebug>
//#include "bala.h"
#include <QGraphicsScene>

Personaje::Personaje():QGraphicsRectItem() {

}

/*
void Personaje::keyPressEvent(QKeyEvent *event)
{
    //qDebug() <<"acabas de presionar una tecla";
    if(event->key() == Qt::Key_Right){
        setPos(x()+10,y());
    }else if(event->key() == Qt::Key_Left){
        if(pos().x()>0){
          setPos(x()-10,y());
        }

    }
    else if(event->key() == Qt::Key_Down){
        setPos(x(),y()+10);
    }    else if(event->key() == Qt::Key_Up){
        setPos(x(),y()-10);
    }else if(event->key() == Qt::Key_Space){
        //si se le da al espacio, quiero hacer un disparo.
        Bala *bala = new Bala();
        //ya con la bala creada queremos que aparezca un poquito adelante del personaje
        bala->setPos(x(),y());
        //ahora que creamos la bala ,debemos de añadirla a la escena
        scene()->addItem(bala);
    }
}
*/
