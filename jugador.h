#ifndef JUGADOR_H
#define JUGADOR_H

#include"personaje.h"

class Jugador :public Personaje {
public:
    //jugador hereda todos los metodos y atributos de Personaje
    Jugador();
    //hacemos un metodo para capturar los eventos de teclado para jugador
     void keyPressEvent(QKeyEvent *event);
};

#endif // JUGADOR_H
