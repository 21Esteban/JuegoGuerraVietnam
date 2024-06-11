#ifndef INICIOJUEGO_H
#define INICIOJUEGO_H

#include <QWidget>
#include <QPushButton>

class InicioJuego : public QWidget {
    Q_OBJECT

public:
    InicioJuego(QWidget *parent = nullptr);

signals:
    void startGame();
    void exitGame();

private slots:
    void onStartButtonClicked();
    void onExitButtonClicked();

private:
    QPushButton *startButton;
    QPushButton *exitButton;
};

#endif // INICIOJUEGO_H
