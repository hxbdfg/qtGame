#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsProxyWidget>
#include <QPixmap>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QPushButton>
#include <QKeyEvent>
#include <QLineEdit>
#include "person.h"

class Game;
class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    QGraphicsView *view;
    Person *person;
    Scene(Game* game);
    QPoint moveDirection;
    QTimer *timer;
    int speed = 2;
    bool isFlipped = false;
    QLineEdit *inputBox;

public slots:
    void hide_bedscene1();
    void hide_bedscene2();
    void hide_bedscene3();
    void show_bedscene1();
    void show_bedscene2();
    void show_bedscene3();
    void hide_kscene1();
    void hide_kscene2();
    void hide_kscene3();
    void show_kscene1();
    void show_kscene2();
    void show_kscene3();
    void hide_livingroom();
    void show_livingroom();
    void show_end();
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    bool checkCollision(int x, int y);
    void movePlayer();
    void showInputBox();
    void checkInput(const QString &text);
    void game2048();

signals:
    void positionChanged(int x, int y);
    void showInventorySignal();

private:
    Game* game;
    QPushButton *button;
    QGraphicsPixmapItem *bedscene1; // 场景背景图层
    QGraphicsPixmapItem *bedscene2;
    QGraphicsPixmapItem *bedscene3;
    QGraphicsPixmapItem *livingscene;
    QGraphicsPixmapItem *kscene1;
    QGraphicsPixmapItem *kscene2;
    QGraphicsPixmapItem *kscene3;
    QGraphicsPixmapItem *end;

signals:

};


#endif // SCENE_H
