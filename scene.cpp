#include "scene.h"
#include "game.h"
#include "widget2048.h"
#include <QApplication>
#include <iostream>

Scene::Scene(Game* game): QGraphicsScene(game), game(game)
{

    // 设置背景图
    setBackgroundBrush(QPixmap(":/images/start.jpg").scaled(1200, 800));

    // 创建视图并将场景设置为视图的场景
    view = new QGraphicsView(this);
    view->setFocusPolicy(Qt::StrongFocus);
    view->setFocus();
    view->setSceneRect(0, 0, 1200, 800);

    person = new Person();
    addItem(person);
    person->setPos(230, 260); // 设置人物的初始位置
    person->setFocus();
    person->setZValue(1);
    person->hide();

    // 创建定时器
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Scene::movePlayer);


    // 设置视图的渲染选项，包括抗锯齿和平滑边缘
    view->setRenderHint(QPainter::Antialiasing, true);
    view->setRenderHint(QPainter::SmoothPixmapTransform, true);

    // 隐藏视图的边框和滚动条
    view->setFrameShape(QFrame::NoFrame);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->resize(1200, 800);
    view->show();

    bedscene1 = new QGraphicsPixmapItem(QPixmap(":/images/bedroom_dark.jpg").scaled(1200, 800)); // 创建背景图层1
    addItem(bedscene1); // 添加背景图层到场景中
    bedscene1->setPos(0, 0); // 设置背景图层位置
    hide_bedscene1();

    bedscene2 = new QGraphicsPixmapItem(QPixmap(":/images/bedroom_mess.jpg").scaled(1200, 800));
    addItem(bedscene2);
    bedscene2->setPos(0, 0);
    hide_bedscene2();

    bedscene3 = new QGraphicsPixmapItem(QPixmap(":/images/bedroom_neat.jpg").scaled(1200, 800));
    addItem(bedscene3);
    bedscene3->setPos(0, 0);
    hide_bedscene3();

    livingscene = new QGraphicsPixmapItem(QPixmap(":/images/livingroom.jpg").scaled(1200, 800));
    addItem(livingscene);
    livingscene->setPos(0, 0);
    hide_livingroom();

    kscene1 = new QGraphicsPixmapItem(QPixmap(":/images/kitchen_close.jpg").scaled(1200, 800));
    addItem(kscene1);
    kscene1->setPos(0, 0);
    hide_kscene1();

    kscene2 = new QGraphicsPixmapItem(QPixmap(":/images/kitchen_open.jpg").scaled(1200, 800));
    addItem(kscene2);
    kscene2->setPos(0, 0);
    hide_kscene2();

    kscene3 = new QGraphicsPixmapItem(QPixmap(":/images/kitchen_open_with.jpg").scaled(1200, 800));
    addItem(kscene3);
    kscene3->setPos(0, 0);
    hide_kscene3();

    end = new QGraphicsPixmapItem(QPixmap(":/images/end.jpg").scaled(1200, 800));
    addItem(end);
    end->setPos(0, 0);
    end->setVisible(false);

    // 创建输入框
    inputBox = new QLineEdit;
    inputBox->setPlaceholderText("请输入密码");
    inputBox->setFixedSize(250, 40);

    QGraphicsProxyWidget *inputBoxProxy = addWidget(inputBox);
    inputBoxProxy->setPos(475, 360);
    inputBox->hide();

    connect(inputBox, &QLineEdit::returnPressed, this, [this]() {
            QString text = inputBox->text();
            checkInput(text);
            });
}

void Scene::game2048()
{
    Widget_* w = new Widget_;
    w->show();
    connect(w, &Widget_::win, game, &Game::win_2048);
    connect(w, &Widget_::lose, game, &Game::lose_2048);
}

void Scene::showInputBox()
{
    // 显示输入框
    inputBox->clear();
    inputBox->show();
    inputBox->setFocus();
}

void Scene::checkInput(const QString &text)
{
    if (text == "7285") {
        game->textDisplayer->displayText("不愧是你，记性不好但智商挺高啊");
        game->textDisplayer->displayText("你正准备打开ai引论lab");
        game->textDisplayer->displayText("突然看到了桌面上一个熟悉的图标");
        game->textDisplayer->displayText("于是——⚪神，启动！");
        game->in_bedscene3 = false;
        QTimer::singleShot(10000, game, &Game::end);
    } else {
        game->textDisplayer->displayText("坏，密码忘了...");
    }
    // 隐藏输入框
    inputBox->hide();
    inputBox->clearFocus();
    inputBox->clear();

}
void Scene::keyPressEvent(QKeyEvent *event)
{
    QGraphicsScene::keyPressEvent(event);
    if (event->key() == Qt::Key_M) {
        emit showInventorySignal();
    }
    if (event->isAutoRepeat()) {
        return;
    }
    event->accept();
    timer->start(10);

    switch (event->key()) {
    case Qt::Key_Left:
        moveDirection.setX(-1);
        if (isFlipped) {
            isFlipped = false;
            person->setPixmap(person->pixmap().transformed(QTransform().scale(-1, 1)));
        }
        break;
    case Qt::Key_Right:
        moveDirection.setX(1);
        if (!isFlipped) {
            isFlipped = true;
            person->setPixmap(person->pixmap().transformed(QTransform().scale(-1, 1)));
        }
        break;
    case Qt::Key_Up:
        moveDirection.setY(-1);
        break;
    case Qt::Key_Down:
        moveDirection.setY(1);
        break;
    }
}

void Scene::keyReleaseEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat()) {
        return;
    }
    event->accept();
    timer->stop();

    moveDirection = QPoint(0, 0);
}

void Scene::movePlayer()
{
    int targetX = person->pos().x() + moveDirection.x() * speed;
    int targetY = person->pos().y() + moveDirection.y() * speed;

    if (!checkCollision(targetX, targetY)) {
        person->moveBy(moveDirection.x() * speed, moveDirection.y() * speed);
        emit positionChanged(person->pos().x(), person->pos().y());
    }
}

bool Scene::checkCollision(int x, int y)
{
    // 检查坐标 (x, y) 是否与障碍物重叠
    if(game->in_bedscene1 || game->in_bedscene2 || game->in_bedscene3)
    {
        if(x < 40||x > 1120||y > 626||y < 104||(x < 402 && y < 220)||(x < 116 && y < 220)||(x < 90 && y < 275)||(x > 928 && y < 274)
            ||(x > 954 && y < 380)||(x > 986 && y < 530)||(x < 506 && y < 584 && y > 274))
            return true;
    }
    if(game->in_kscene1 || game->in_kscene2 || game->in_kscene3)
    {
        if(y > 654||x < 116||y < 96||(x < 742 && y < 214)||(x < 220 && y < 320)||(x < 190 && y < 458)||(x > 790 && y > 440)
            ||(x > 1011 && y < 292)||(y < 440 && x > 1054)||(x > 982 && y < 186))
            return true;
    }
    if(game->in_livingroom)
    {
        if(y > 654||x < 18||x > 1098||y < 98||(x > 762 && y < 195)||(x > 950 && y < 440)||(x > 932 && y < 288)||(x > 916 && y < 195)||
            (x < 926 && y < 546 && y > 402 && x > 674)||(x > 664 && y > 218 && y < 332 && x < 898)||(y > 311 && y < 403 && x < 914 && x > 674)
            ||(x < 127 && y < 189)||(x < 108 && y < 272)||(x < 128 && y < 412 && y > 291)||(x < 108 && y < 534))
            return true;
    }
    return false;
}
void Scene::hide_bedscene1()
{
    bedscene1->setVisible(false);
}

void Scene::hide_bedscene2()
{
    bedscene2->setVisible(false);
}
void Scene::hide_bedscene3()
{
    bedscene3->setVisible(false);
}
void Scene::show_bedscene1()
{
    bedscene1->setVisible(true);
}
void Scene::show_bedscene2()
{
    bedscene2->setVisible(true);
}
void Scene::show_bedscene3()
{
    bedscene3->setVisible(true);
}

void Scene::hide_livingroom()
{
    livingscene->setVisible(false);
}
void Scene::show_livingroom()
{
    livingscene->setVisible(true);
}

void Scene::hide_kscene1()
{
    kscene1->setVisible(false);
}

void Scene::hide_kscene2()
{
    kscene2->setVisible(false);
}
void Scene::hide_kscene3()
{
    kscene3->setVisible(false);
}
void Scene::show_kscene1()
{
    kscene1->setVisible(true);
}
void Scene::show_kscene2()
{
    kscene2->setVisible(true);
}
void Scene::show_kscene3()
{
    kscene3->setVisible(true);
}
void Scene::show_end()
{
    end->setVisible(true);
    bedscene3->setVisible(false);
}
