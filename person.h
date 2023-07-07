#ifndef PERSON_H
#define PERSON_H

#include <QGraphicsPixmapItem>


class Person : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Person(QGraphicsItem *parent = nullptr) : QGraphicsPixmapItem(parent){
        // 加载人物贴图
        setPixmap(QPixmap(":/images/character.png").scaled(96, 170));

        // 初始化人物位置
        setPos(230, 270);
    }
};

#endif // PERSON_H
