#include "piedra.h"

Piedra::Piedra(QObject *parent)
    : QObject{parent}
{
    setPixmap(QPixmap(":/imagenes/piedraSinFondo.png").scaled(130,130));

}
