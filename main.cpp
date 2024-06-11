#include <QApplication>
#include "game.h"
#include "iniciojuego.h"

Game *game;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    InicioJuego inicioJuego;  // Se crea una instancia de la ventana inicial.
    game = nullptr;  // Inicialmente, el puntero del juego se establece en nullptr.

    QObject::connect(&inicioJuego, &InicioJuego::startGame, [&]() {
        inicioJuego.hide();  // Oculta la ventana inicial.
        game = new Game();  // Crea una instancia del juego cuando se presiona el botón.
        game->show();  // Muestra el juego.
    });

    inicioJuego.show();  // Muestra la ventana inicial.

    return a.exec();
}
