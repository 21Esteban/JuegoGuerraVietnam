#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "personaje.h"
#include <QSoundEffect>
//#include <QtMultimedia/QMediaPlayer>
#include <QTimer>
<<<<<<< HEAD
#include <QString>
#include <QVector>
=======
>>>>>>> 55e9208a03054091bafb59fb219175125e1a86a6

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
<<<<<<< HEAD
    int frame;
    QString animacionPath1  = ":/imagenes/movimiento1SinFondo.png";
    QString animacionPath2  = ":/imagenes/movimiento2SinFondo.png";
    QString animacionPath3  = ":/imagenes/movimiento3SinFondo.png";
    QVector<QString> animaciones ;


=======
    int frame; // Para controlar el frame actual de la animación
>>>>>>> 55e9208a03054091bafb59fb219175125e1a86a6

public slots:
    void spawn();
    void cambiarImagenAlDisparar();
    void actualizarAnimacion();


signals:
};

#endif // PLAYER_H
