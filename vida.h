#ifndef VIDA_H
#define VIDA_H

#include<QGraphicsTextItem>
#include <QObject>

class Vida : public QGraphicsTextItem
{
    Q_OBJECT
public:
    explicit Vida(QGraphicsItem *parent = nullptr);
    void decrease();
    int getVidas();
private:
    int numVidas;

signals:
};

#endif // VIDA_H
