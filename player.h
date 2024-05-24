#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "personaje.h"
#include <QSoundEffect>
//#include <QtMultimedia/QMediaPlayer>
#include <QTimer>

class Player : public QObject , public Personaje
{
    Q_OBJECT
public:
      //player hereda todos los metodos y atributos de Personaje
    explicit Player(QObject *parent = nullptr);

    //hacemos un metodo para capturar los eventos de teclado para jugador
    void keyPressEvent(QKeyEvent *event);

private:
    QSoundEffect * sonidoDisparo;
    QTimer *temporizadorAux;
    int frame; // Para controlar el frame actual de la animación

public slots:
    void spawn();
    void cambiarImagenAlDisparar();
    void actualizarAnimacion();


signals:
};

#endif // PLAYER_H
