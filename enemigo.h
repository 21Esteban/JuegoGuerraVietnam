#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QObject>
#include "personaje.h"
#include <QSoundEffect>

class Enemigo :  public QObject , public Personaje
{
    Q_OBJECT
public:
    explicit Enemigo(QObject *parent = nullptr);

public slots:
    void move();
    void disparar();

private:
   // QSoundEffect * sonidoDisparo;

signals:
};

#endif // ENEMIGO_H
