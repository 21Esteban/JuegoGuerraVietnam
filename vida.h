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
    QVector<QString> imagenesVida = {":/imagenes/SPRITE/corazon3SinFondo.png",":/imagenes/SPRITE/corazonSinFondo2.png",":/imagenes/SPRITE/corazonSinFondo.png"} ;
private:
    int numVidas;


signals:
};

#endif // VIDA_H
