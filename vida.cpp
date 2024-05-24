#include "vida.h"
#include <QFont>

Vida::Vida(QGraphicsItem *parent)
    : QGraphicsTextItem(parent)
{
    this->numVidas = 3;

    //dibujamos el texto

    setPlainText("Vidas : " + QString::number(numVidas));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Sans Serif", 16));
}

void Vida::decrease()
{
    this->numVidas--;
    setPlainText("Vidas : " + QString::number(numVidas));
}

int Vida::getVidas()
{
    return numVidas;
}
