#include "vida.h"
#include <QFont>
#include <QPixmap>

Vida::Vida(QObject *parent)
    :  QObject{parent}, QGraphicsPixmapItem()
{
    //creamos la imagen

    this->numVidas = 3;
    setPixmap(QPixmap(this->imagenesVida[2]).scaled(60,60,Qt::KeepAspectRatio));


    //dibujamos el texto

    /*
    setDefaultTextColor(Qt::red);
    setFont(QFont("Sans Serif", 16));*/

}

void Vida::decrease()
{
    this->numVidas--;
    //setPlainText("Vidas : " + QString::number(numVidas));
    setPixmap(QPixmap(this->imagenesVida[numVidas]).scaled(60,60,Qt::KeepAspectRatio));
}

int Vida::getVidas()
{
    return numVidas;
}


