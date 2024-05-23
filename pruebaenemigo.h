#ifndef PRUEBAENEMIGO_H
#define PRUEBAENEMIGO_H


#include <QObject>
#include "personaje.h"

class PruebaEnemigo : public QObject , public Personaje
{
    Q_OBJECT
public:
    explicit PruebaEnemigo(QObject *parent = nullptr);

public slots:
    void move();

signals:
};

#endif // PRUEBAENEMIGO_H
