#include "piedra.h"

Piedra::Piedra(QObject *parent)
    : QObject{parent}
{
    setPixmap(QPixmap(":/imagenes/SPRITE/piedraSinFondo.png").scaled(130,130));

}
