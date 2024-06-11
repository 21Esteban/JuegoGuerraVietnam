#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QObject>
#include "personaje.h"
#include <QSoundEffect>
#include "vida.h"

class Enemigo :  public QObject , public Personaje
{
    Q_OBJECT
public:
    explicit Enemigo(QObject *parent = nullptr);
    Vida vida;
public slots:
    void move();
    void disparar();
    void recibirDisparo();

private:
   // QSoundEffect * sonidoDisparo;


signals:
};

#endif // ENEMIGO_H

//para agregar vida a un enemigo lo que hago es detectar las colisionjes, si la colision es myor que 3 desaparezco al enemigo
