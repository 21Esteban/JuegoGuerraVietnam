#include "pruebaenemigo.h"

PruebaEnemigo::PruebaEnemigo(QObject *parent)
    : QObject{parent} , Personaje()
{
    //creamos el enemigo
    setPixmap(QPixmap(":/imagenes/SPRITE/movimiento1SinFondo.png").scaled(80,80,Qt::KeepAspectRatio));
}

void PruebaEnemigo::move()
{

}
