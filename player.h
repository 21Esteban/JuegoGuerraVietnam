#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "personaje.h"

class Player : public QObject , public Personaje
{
    Q_OBJECT
public:
      //player hereda todos los metodos y atributos de Personaje
    explicit Player(QObject *parent = nullptr);

    //hacemos un metodo para capturar los eventos de teclado para jugador
    void keyPressEvent(QKeyEvent *event);

public slots:
    void spawn();

signals:
};

#endif // PLAYER_H
