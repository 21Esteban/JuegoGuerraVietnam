#ifndef VIDA_H
#define VIDA_H

#include<QGraphicsTextItem>
#include <QObject>
#include<QGraphicsPixmapItem>
#include <QString>
#include<QObject>
class Vida : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Vida(QObject *parent = nullptr);
    void decrease();
    int getVidas();
    void setNumVidas(int numVidas);
        //QString getImagen();
<<<<<<< HEAD
    QVector<QString> imagenesVida = {":/imagenes/SPRITE/corazon3SinFondo.png",":/imagenes/SPRITE/corazonSinFondo2.png",":/imagenes/SPRITE/corazonSinFondo.png"} ;
=======
    QVector<QString> imagenesVida = {":/imagenes/corazon3SinFondo.png",":/imagenes/corazonSinFondo2.png",":/imagenes/corazonSinFondo.png"} ;
>>>>>>> a20a094be80bf8904920b78fe30515ef531c6d04
private:
    int numVidas;


signals:
};

#endif // VIDA_H
