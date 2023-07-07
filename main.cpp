#include <QGraphicsView>
#include "game.h"
#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Game* game = new Game;


    return a.exec();
}
