#ifndef ENEMIGO2_H
#define ENEMIGO2_H

#include <QObject>
#include "personaje.h"
#include <QSoundEffect>
#include "vida.h"

class Enemigo2 :  public QObject , public Personaje
{
    Q_OBJECT
public:
    explicit Enemigo2(QObject *parent = nullptr);
    Vida vida;
public slots:
    void move();
    void disparar();
    void recibirDisparo();

private:
         // QSoundEffect * sonidoDisparo;
    bool personajeEnEscenaDos() const;

signals:
};

#endif // ENEMIGO2_H
