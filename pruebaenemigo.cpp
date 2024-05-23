#include "pruebaenemigo.h"

PruebaEnemigo::PruebaEnemigo(QObject *parent)
    : QObject{parent} , Personaje()
{
    //creamos el enemigo
    setRect(0,0,10,50);
}

void PruebaEnemigo::move()
{

}
