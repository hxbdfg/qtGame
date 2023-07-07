#include "game.h"
#include "CustomButton.h"
#include "textdisplayer.h"
#include "game_kitchen/mainwindow.h"
#include "game_puzzle/widget.h"

Game::Game(QObject *parent) : QObject(parent)
{
    //主页面
    scene = new Scene(this);
    button = new CustomButton("开始游戏");
    QGraphicsProxyWidget *buttonProxy = scene->addWidget(button);
    buttonProxy->setPos(450, 500);

    button0 = new CustomButton("玩法说明");
    QGraphicsProxyWidget *buttonProxy00 = scene->addWidget(button0);
    buttonProxy00->setPos(450, 600);

    connect(button0, &QPushButton::clicked, this, &Game::start0);
    connect(button0, &QPushButton::clicked, button0, &CustomButton::hideButton);

    endbutton = new CustomButton("结束这一天");
    QGraphicsProxyWidget *buttonProxy0 = scene->addWidget(endbutton);
    buttonProxy0->setPos(450, 500);
    endbutton->hide();

    connect(button, &QPushButton::clicked, this, &Game::start);
    connect(button, &QPushButton::clicked, button, &CustomButton::hideButton);

    connect(endbutton, &QPushButton::clicked, this, [](){qApp->quit();});

    //创建文本
    textDisplayer = new TextDisplayer;
    QGraphicsProxyWidget *text = scene->addWidget(textDisplayer);
    text->setPos(300,400);

    //拉开窗帘
    buttons[0] = new CustomButton1("拉开");
    QGraphicsProxyWidget *buttonProxy1 = scene->addWidget(buttons[0]);
    buttonProxy1->setPos(700, 150);
    buttons[0]->hide();

    connect(buttons[0], &QPushButton::clicked, this, &Game::button1Clicked);
    connect(buttons[0], &QPushButton::clicked, buttons[0], &CustomButton1::hideButton);

    //拿到日程表
    buttons[1] = new CustomButton1("查看纸条");
    QGraphicsProxyWidget *buttonProxy2 = scene->addWidget(buttons[1]);
    buttonProxy2->setPos(500, 150);
    buttons[1]->hide();

    connect(buttons[1], &QPushButton::clicked, this, &Game::button2Clicked);
    connect(buttons[1], &QPushButton::clicked, buttons[1], &CustomButton1::hideButton);

    //整理桌面
    buttons[2] = new CustomButton1("整理桌面");
    QGraphicsProxyWidget *buttonProxy3 = scene->addWidget(buttons[2]);
    buttonProxy3->setPos(450, 150);
    buttons[2]->hide();

    connect(buttons[2], &QPushButton::clicked, this, &Game::button3Clicked);
    connect(buttons[2], &QPushButton::clicked, buttons[2], &CustomButton1::hideButton);

    //写数学作业
    buttons[3] = new CustomButton1("写数学作业");
    QGraphicsProxyWidget *buttonProxy4 = scene->addWidget(buttons[3]);
    buttonProxy4->setPos(450, 200);
    buttons[3]->hide();

    connect(buttons[3], &QPushButton::clicked, this, &Game::button4Clicked);
    connect(buttons[3], &QPushButton::clicked, buttons[3], &CustomButton1::hideButton);

    //检查床底
    buttons[4] = new CustomButton1("检查床底");
    QGraphicsProxyWidget *buttonProxy5 = scene->addWidget(buttons[4]);
    buttonProxy5->setPos(250, 550);
    buttons[4]->hide();

    connect(buttons[4], &QPushButton::clicked, this, &Game::button5Clicked);
    connect(buttons[4], &QPushButton::clicked, buttons[4], &CustomButton1::hideButton);

    //翻垃圾桶
    buttons[5] = new CustomButton1("翻垃圾桶");
    QGraphicsProxyWidget *buttonProxy6 = scene->addWidget(buttons[5]);
    buttonProxy6->setPos(500, 270);
    buttons[5]->hide();

    connect(buttons[5], &QPushButton::clicked, this, &Game::button6Clicked);
    connect(buttons[5], &QPushButton::clicked, buttons[5], &CustomButton1::hideButton);

    //检查床铺
    buttons[6] = new CustomButton1("检查床铺");
    QGraphicsProxyWidget *buttonProxy7 = scene->addWidget(buttons[6]);
    buttonProxy7->setPos(250, 470);
    buttons[6]->hide();

    connect(buttons[6], &QPushButton::clicked, this, &Game::button7Clicked);
    connect(buttons[6], &QPushButton::clicked, buttons[6], &CustomButton1::hideButton);

    //拿起枕头
    buttons[7] = new CustomButton1("拿起枕头");
    QGraphicsProxyWidget *buttonProxy8 = scene->addWidget(buttons[7]);
    buttonProxy8->setPos(150, 480);
    buttons[7]->hide();

    connect(buttons[7], &QPushButton::clicked, this, &Game::button8Clicked);
    connect(buttons[7], &QPushButton::clicked, buttons[7], &CustomButton1::hideButton);

    //搜查衣架
    buttons[8] = new CustomButton1("检查衣架");
    QGraphicsProxyWidget *buttonProxy9 = scene->addWidget(buttons[8]);
    buttonProxy9->setPos(850, 200);
    buttons[8]->hide();

    connect(buttons[8], &QPushButton::clicked, this, &Game::button9Clicked);
    connect(buttons[8], &QPushButton::clicked, buttons[8], &CustomButton1::hideButton);

    //检查窗台
    buttons[9] = new CustomButton1("检查窗台");
    QGraphicsProxyWidget *buttonProxy10 = scene->addWidget(buttons[9]);
    buttonProxy10->setPos(700, 150);
    buttons[9]->hide();

    connect(buttons[9], &QPushButton::clicked, this, &Game::button10Clicked);
    connect(buttons[9], &QPushButton::clicked, buttons[9], &CustomButton1::hideButton);

    //开门
    buttons[10] = new CustomButton1("开门");
    QGraphicsProxyWidget *buttonProxy11 = scene->addWidget(buttons[10]);
    buttonProxy11->setPos(950, 150);
    buttons[10]->hide();

    connect(buttons[10], &QPushButton::clicked, this, &Game::button11Clicked);
    connect(buttons[10], &QPushButton::clicked, buttons[10], &CustomButton1::hideButton);

    //打开电脑
    buttons[11] = new CustomButton1("打开电脑");
    QGraphicsProxyWidget *buttonProxy12 = scene->addWidget(buttons[11]);
    buttonProxy12->setPos(450, 150);
    buttons[11]->hide();

    connect(buttons[11], &QPushButton::clicked, scene, &Scene::showInputBox);//输入密码

    //查看钟表
    buttons[12] = new CustomButton1("查看钟表");
    QGraphicsProxyWidget *buttonProxy13 = scene->addWidget(buttons[12]);
    buttonProxy13->setPos(630, 170);
    buttons[12]->hide();

    connect(buttons[12], &QPushButton::clicked, this, &Game::button12Clicked);
    connect(buttons[12], &QPushButton::clicked, buttons[12], &CustomButton1::hideButton);

    //摘花
    buttons[13] = new CustomButton1("摘花");
    QGraphicsProxyWidget *buttonProxy14 = scene->addWidget(buttons[13]);
    buttonProxy14->setPos(950, 460);
    buttons[13]->hide();

    connect(buttons[13], &QPushButton::clicked, this, &Game::button13Clicked);
    connect(buttons[13], &QPushButton::clicked, buttons[13], &CustomButton1::hideButton);

    //挖花盆
    buttons[14] = new CustomButton1("挖土");
    QGraphicsProxyWidget *buttonProxy15 = scene->addWidget(buttons[14]);
    buttonProxy15->setPos(740, 150);
    buttons[14]->hide();

    connect(buttons[14], &QPushButton::clicked, this, &Game::button14Clicked);
    connect(buttons[14], &QPushButton::clicked, buttons[14], &CustomButton1::hideButton);

    //掏垃圾桶
    buttons[15] = new CustomButton1("掏垃圾桶");
    QGraphicsProxyWidget *buttonProxy16 = scene->addWidget(buttons[15]);
    buttonProxy16->setPos(850, 150);
    buttons[15]->hide();

    connect(buttons[15], &QPushButton::clicked, this, &Game::button15Clicked);
    connect(buttons[15], &QPushButton::clicked, buttons[15], &CustomButton1::hideButton);

    //拼图游戏
    buttons[25] = new CustomButton1("查看");
    QGraphicsProxyWidget *buttonProxy26 = scene->addWidget(buttons[25]);
    buttonProxy26->setPos(850, 80);
    buttons[25]->hide();

    connect(buttons[25], &QPushButton::clicked, this, &Game::button25Clicked);
    connect(buttons[25], &QPushButton::clicked, buttons[25], &CustomButton1::hideButton);


    //前往卧室
    buttons[16] = new CustomButton1("前往卧室");
    QGraphicsProxyWidget *buttonProxy17 = scene->addWidget(buttons[16]);
    buttonProxy17->setPos(160, 170);
    buttons[16]->hide();

    connect(buttons[16], &QPushButton::clicked, this, &Game::button16Clicked);
    connect(buttons[16], &QPushButton::clicked, buttons[16], &CustomButton1::hideButton);

    //掏垃圾桶
    buttons[17] = new CustomButton1("掏垃圾桶");
    QGraphicsProxyWidget *buttonProxy18 = scene->addWidget(buttons[17]);
    buttonProxy18->setPos(860, 180);
    buttons[17]->hide();

    connect(buttons[17], &QPushButton::clicked, this, &Game::button17Clicked);
    connect(buttons[17], &QPushButton::clicked, buttons[17], &CustomButton1::hideButton);

    //打开冰箱
    buttons[18] = new CustomButton1("打开冰箱");
    QGraphicsProxyWidget *buttonProxy19 = scene->addWidget(buttons[18]);
    buttonProxy19->setPos(200, 560);
    buttons[18]->hide();

    connect(buttons[18], &QPushButton::clicked, this, &Game::button18Clicked);
    connect(buttons[18], &QPushButton::clicked, buttons[18], &CustomButton1::hideButton);

    //打开橱柜
    buttons[19] = new CustomButton1("打开橱柜");
    QGraphicsProxyWidget *buttonProxy20 = scene->addWidget(buttons[19]);
    buttonProxy20->setPos(620, 265);
    buttons[19]->hide();

    connect(buttons[19], &QPushButton::clicked, this, &Game::button19Clicked);
    connect(buttons[19], &QPushButton::clicked, buttons[19], &CustomButton1::hideButton);

    //拿铲子
    buttons[20] = new CustomButton1("拿取");
    QGraphicsProxyWidget *buttonProxy21 = scene->addWidget(buttons[20]);
    buttonProxy21->setPos(620, 265);
    buttons[20]->hide();

    connect(buttons[20], &QPushButton::clicked, this, &Game::button20Clicked);
    connect(buttons[20], &QPushButton::clicked, buttons[20], &CustomButton1::hideButton);

    //查看菜谱
    buttons[21] = new CustomButton1("查看菜谱");
    QGraphicsProxyWidget *buttonProxy22 = scene->addWidget(buttons[21]);
    buttonProxy22->setPos(300, 370);
    buttons[21]->hide();

    connect(buttons[21], &QPushButton::clicked, this, &Game::button21Clicked);
    connect(buttons[21], &QPushButton::clicked, buttons[21], &CustomButton1::hideButton);

    //开始烹饪
    buttons[22] = new CustomButton1("开始烹饪");
    QGraphicsProxyWidget *buttonProxy23 = scene->addWidget(buttons[22]);
    buttonProxy23->setPos(300, 420);
    buttons[22]->hide();

    connect(buttons[22], &QPushButton::clicked, this, &Game::button22Clicked);
    connect(buttons[22], &QPushButton::clicked, buttons[22], &CustomButton1::hideButton);

    //前往客厅
    buttons[23] = new CustomButton1("前往客厅");
    QGraphicsProxyWidget *buttonProxy24 = scene->addWidget(buttons[23]);
    buttonProxy24->setPos(900, 240);
    buttons[23]->hide();

    connect(buttons[23], &QPushButton::clicked, this, &Game::button23Clicked);
    connect(buttons[23], &QPushButton::clicked, buttons[23], &CustomButton1::hideButton);

    //前往厨房
    buttons[24] = new CustomButton1("前往厨房");
    QGraphicsProxyWidget *buttonProxy25 = scene->addWidget(buttons[24]);
    buttonProxy25->setPos(340, 150);
    buttons[24]->hide();

    connect(buttons[24], &QPushButton::clicked, this, &Game::button24Clicked);
    connect(buttons[24], &QPushButton::clicked, buttons[24], &CustomButton1::hideButton);

    // 连接人物的移动信号到槽函数
    connect(scene, &Scene::positionChanged, this, &Game::checkPosition);

    player1 = new QMediaPlayer;
    player2 = new QMediaPlayer;
    player3 = new QMediaPlayer;
    player4 = new QMediaPlayer;
    player5 = new QMediaPlayer;
    player6 = new QMediaPlayer;
    player7 = new QMediaPlayer;
    audioOutput[0] = new QAudioOutput(this);
    audioOutput[0]->setVolume(0.5);
    audioOutput[1] = new QAudioOutput(this);
    audioOutput[1]->setVolume(0.5);
    audioOutput[2] = new QAudioOutput(this);
    audioOutput[2]->setVolume(0.5);
    audioOutput[3] = new QAudioOutput(this);
    audioOutput[3]->setVolume(0.5);
    audioOutput[4] = new QAudioOutput(this);
    audioOutput[4]->setVolume(0.3);
    audioOutput[5] = new QAudioOutput(this);
    audioOutput[5]->setVolume(1.8);
    audioOutput[6] = new QAudioOutput(this);
    audioOutput[6]->setVolume(0.5);

    player1->setAudioOutput(audioOutput[0]);
    player1->setSource(QUrl("qrc:/images/start.mp3"));
    player1->setLoops(-1);
    player2->setAudioOutput(audioOutput[1]);
    player2->setSource(QUrl("qrc:/images/bedroom.mp3"));
    player2->setLoops(-1);
    player3->setAudioOutput(audioOutput[2]);
    player3->setSource(QUrl("qrc:/images/livingroom.mp3"));
    player3->setLoops(-1);
    player4->setAudioOutput(audioOutput[3]);
    player4->setSource(QUrl("qrc:/images/kitchen.mp3"));
    player4->setLoops(-1);
    player5->setAudioOutput(audioOutput[4]);
    player5->setSource(QUrl("qrc:/images/get_item.mp3"));
    player6->setAudioOutput(audioOutput[5]);
    player6->setSource(QUrl("qrc:/images/clock.mp3"));
    player7->setAudioOutput(audioOutput[6]);
    player7->setSource(QUrl("qrc:/images/game_2048.mp3"));
    player7->setLoops(-1);
    player1->play();
}

void Game::start()
{
    // 开始游戏
    scene->show_bedscene1();
    scene->person->show();
    button0->hideButton();

    // 创建文本项并设置文本内容
    QGraphicsTextItem *textItem = new QGraphicsTextItem("按‘M’键查看物品栏");
    textItem->setDefaultTextColor(Qt::white);
    QFont font;
    font.setPointSize(16);
    textItem->setFont(font);
    textItem->setPos(0, 800 - textItem->boundingRect().height());
    scene->addItem(textItem);

    player1->stop();
    player2->play();
    in_bedscene1 = true;
    textDisplayer->displayText("房间好黑......先把窗帘拉开吧");

    //创建物品栏窗口
    window = new CustomWindow;
    window->hide();
    connect(scene, &Scene::showInventorySignal, this, &Game::showInventory);
}

void Game::start0()
{
    textDisplayer->displayText("本游戏不需要玩法说明");
}

void Game::showInventory() {
    window->show();
}

void Game::end(){

    scene->show_end();
    scene->person->setVisible(false);
    QGraphicsTextItem *textItem = new QGraphicsTextItem();
    textItem->setPlainText("");
    scene->addItem(textItem);

    QString text = "你下定决心：\n     明天一定认真学习!!";
    QFont font("华文行楷", 50);

    textItem->setFont(font);
    textItem->setDefaultTextColor(Qt::white);

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
    effect->setOffset(2,2);
    effect->setBlurRadius(5);
    effect->setColor(Qt::black);

    textItem->setGraphicsEffect(effect);


    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [=]() {
        static int index = 0;
        QString str = text.mid(0, ++index);
        textItem->setPlainText(str);

        // 更新文本居中显示
        QRectF textRect = textItem->boundingRect();
        textItem->setPos((scene->sceneRect().width() - textRect.width()) / 2,
                         (scene->sceneRect().height() - textRect.height()) / 3);

        if (index >= text.length()) {
            timer->stop();
            endbutton->show();
        }
    });
    timer->start(100);
}

void Game::checkPosition(int x, int y)
{
    //拉窗帘
    if (!buttons[0]->isClicked && in_bedscene1 && x < 696 && x > 476 && y == 104) {
        buttons[0]->show();
    } else {
        buttons[0]->hide();
    }
    //查看日程表
    if (!buttons[1]->isClicked && in_bedscene2 && x < 470 && x > 428 && y == 104) {
        buttons[1]->show();
    } else {
        buttons[1]->hide();
    }
    //整理书桌
    if (!buttons[2]->isClicked && in_bedscene2 && ((x < 403 && x > 100 && y == 220)||(x == 402 && y < 221 && y > 103))) {
        buttons[2]->show();
    } else {
        buttons[2]->hide();
    }
    //写数学作业（进入小游戏）
    if (in_bedscene3 && ((x < 403 && x > 100 && y == 220)||(x == 402 && y < 221 && y > 103))) {
        buttons[3]->show();
    } else {
        buttons[3]->hide();
    }
    //检查床底
    if (!buttons[4]->isClicked && in_bedscene3 && ((x == 506 && y < 585 && y > 314)||(y == 584 && x > 132 && x < 507))) {
        buttons[4]->show();
    } else {
        buttons[4]->hide();
    }
    //翻垃圾桶
    if (!buttons[5]->isClicked && (in_bedscene3 || in_bedscene2) && x < 468 && y < 188) {
        buttons[5]->show();
    } else {
        buttons[5]->hide();
    }
    //检查床铺
    if (!buttons[6]->isClicked && in_bedscene3 && ((x == 506 && y < 585 && y > 314)||(y == 584 && x > 132 && x < 507))) {
        buttons[6]->show();
    } else {
        buttons[6]->hide();
    }
    //拿起枕头
    if (!buttons[7]->isClicked && (in_bedscene3 || in_bedscene2) && ((x < 91 && y == 584)||(y == 274 && x < 144))) {
        buttons[7]->show();
    } else {
        buttons[7]->hide();
    }
    //搜查衣架
    if (!buttons[8]->isClicked && (in_bedscene3 || in_bedscene2) && x < 800 && x > 722 && y < 147) {
        buttons[8]->show();
    } else {
        buttons[8]->hide();
    }
    //检查窗台
    if (!buttons[9]->isClicked && (in_bedscene3 || in_bedscene2) && x < 696 && x > 476 && y == 104) {
        buttons[9]->show();
    } else {
        buttons[9]->hide();
    }
    //开门
    if ((in_bedscene3 || in_bedscene2) && x < 880 && x > 826 && y == 104) {
        buttons[10]->show();
    } else {
        buttons[10]->hide();
    }
    //打开电脑
    if (in_bedscene3 && ((x < 403 && x > 100 && y == 220)||(x == 402 && y < 221 && y > 103))) {
        buttons[11]->show();
    } else {
        buttons[11]->hide();
    }
    //查看钟表
    if (!buttons[12]->isClicked && in_livingroom && x < 566 &&  x > 504 && y == 98) {
        buttons[12]->show();
    } else {
        buttons[12]->hide();
    }
    //摘花
    if (!buttons[13]->isClicked && in_livingroom && x > 1052 && y < 508) {
        buttons[13]->show();
    } else {
        buttons[13]->hide();
    }
    //挖土
    if (!buttons[14]->isClicked && in_livingroom && x < 658 && x > 622 && y < 122) {
        buttons[14]->show();
    } else {
        buttons[14]->hide();
    }
    //掏垃圾桶（客厅
    if (!buttons[15]->isClicked && in_livingroom && x > 738 && y < 156) {
        buttons[15]->show();
    } else {
        buttons[15]->hide();
    }
    //拼图游戏
    if (!buttons[25]->isClicked && in_livingroom && x > 738 && y < 156) {
        buttons[25]->show();
    } else {
        buttons[25]->hide();
    }
    //前往卧室
    if (in_livingroom && x < 129 && y < 220 && y > 134) {
        buttons[16]->show();
    } else {
        buttons[16]->hide();
    }
    //掏垃圾桶（厨房
    if (!buttons[17]->isClicked && (in_kscene1 || in_kscene2 || in_kscene3) && x < 816 && x > 746 && y < 153) {
        buttons[17]->show();
    } else {
        buttons[17]->hide();
    }
    //打开冰箱
    if (!buttons[18]->isClicked && (in_kscene1 || in_kscene2 || in_kscene3) && x == 116 && y > 506) {
        buttons[18]->show();
    } else {
        buttons[18]->hide();
    }
    //打开橱柜
    if (!buttons[19]->isClicked && in_kscene1 && x < 598 && x > 476 && y == 214) {
        buttons[19]->show();
    } else {
        buttons[19]->hide();
    }
    //拿取铲子
    if (!buttons[20]->isClicked && in_kscene3 && x < 598 && x > 476 && y == 214) {
        buttons[20]->show();
    } else {
        buttons[20]->hide();
    }
    //查看菜谱
    if ((in_kscene1 || in_kscene2 || in_kscene3) && ((x == 220 && y < 321)||(x == 190 && y < 459))) {
        buttons[21]->show();
    } else {
        buttons[21]->hide();
    }
    //开始烹饪
    if ((in_kscene1 || in_kscene2 || in_kscene3) && ((x == 220 && y < 321)||(x == 190 && y < 459))) {
        buttons[22]->show();
    } else {
        buttons[22]->hide();
    }
    //前往客厅
    if ((in_kscene1 || in_kscene2 || in_kscene3) && x == 1010 && y < 292 && y > 186) {
        buttons[23]->show();
    } else {
        buttons[23]->hide();
    }
    //前往厨房
    if (in_livingroom && x < 272 && x > 224 && y == 98) {
        buttons[24]->show();
    } else {
        buttons[24]->hide();
    }
}

void Game::button1Clicked()//拉开窗帘并显示文本
{
    scene->show_bedscene2();
    scene->hide_bedscene1();
    textDisplayer->displayText("美(wu)好(liao)的一天又要开始啦");
    in_bedscene1 = false;
    in_bedscene2 = true;
    buttons[0]->isClicked = true;
    scene->person->setFocus();
}

void Game::button2Clicked()//查看日程表
{
    CustomWindow1 *window1 = new CustomWindow1;
    window1->show();
    buttons[1]->isClicked = true;
    window->addText("一张提醒你学习的小纸条");
    player5->play();
    textDisplayer->displayText("“获得物品：一张提醒你学习的小纸条”");
    textDisplayer->displayText("那就先写数学作业吧...咦，我的数学作业本在哪里捏");
    scene->person->setFocus();
}

void Game::button3Clicked()//整理桌面
{
    scene->show_bedscene3();
    scene->hide_bedscene2();
    textDisplayer->displayText("为了找到不翼而飞的数学作业本，你终于整理了积乱已久的书桌");
    in_bedscene2 = false;
    in_bedscene3 = true;
    tidy = true;
    buttons[2]->isClicked = true;
    scene->person->setFocus();
}

void Game::button4Clicked()//写数学作业（进入小游戏）
{
    if(pen && ruler)
    {
        buttons[3]->isClicked = true;
        player2->stop();
        player7->play();
        //进入小游戏
        scene->game2048();
    }
    else
    {
        textDisplayer->displayText("可恶，尺子找不见了，笔也没油了，以后再也不乱扔文具了qaq");
    }
    scene->person->setFocus();
}

void Game::win_2048()
{
    player7->stop();
    player2->play();
    textDisplayer->displayText("数学作业写完了！好耶！");
}
void Game::lose_2048()
{
    player7->stop();
    player2->play();
    textDisplayer->displayText("好难，不会写，摆了！");
}

void Game::button5Clicked()//检查床底
{
    textDisplayer->displayText("“获得物品：一根沾满灰尘的中性笔”");
    window->addText("一根沾满灰尘的中性笔");
    player5->play();
    textDisplayer->displayText("原来这里还有一支笔！");
    if(!ruler)
    {
        textDisplayer->displayText("然而尺子在哪里呢...谁说有直边的东西不是尺子！");
    }
    pen = true;
    buttons[4]->isClicked = true;
    scene->person->setFocus();
}

void Game::button6Clicked()//翻垃圾桶
{

    textDisplayer->displayText("所以你为什么要干这种事啊...喂，别是学程设学傻了");
    textDisplayer->displayText("“获得物品：一张散发着微妙气味的校园卡”");
    window->addText("一张散发着微妙气味的校园卡");
    player5->play();
    textDisplayer->displayText("丢失已久的校园卡终于在今天找见了！喜大普奔！");
    textDisplayer->displayText("嗯...或许它还能有些别的用处");
    ruler = true;
    buttons[5]->isClicked = true;
    scene->person->setFocus();
}

void Game::button7Clicked()//检查床铺
{
    textDisplayer->displayText("你寻找了被子下的每个角落，然而无事发生");
    textDisplayer->displayText("啧，还得把被子重新叠回去，这波血亏");
    buttons[6]->isClicked = true;
    scene->person->setFocus();
}

void Game::button8Clicked()//拿起枕头
{
    textDisplayer->displayText("“获得物品：一把平平无奇的钥匙”");
    window->addText("一把平平无奇的钥匙");
    player5->play();
    key = true;
    buttons[7]->isClicked = true;
    scene->person->setFocus();
}

void Game::button9Clicked()//检查衣架
{
    textDisplayer->displayText("“获得物品：一枚平平无奇的回形针，不知道有什么用”");
    window->addText("一枚平平无奇的回形针");
    player5->play();
    pin = true;
    buttons[8]->isClicked = true;
    scene->person->setFocus();
}

void Game::button10Clicked()//检查窗台
{
    textDisplayer->displayText("窗台上积了厚厚一层灰，你被呛得咳了两声");
    buttons[9]->isClicked = true;
    scene->person->setFocus();
}

void Game::button11Clicked()//开门
{
    if(!key)
    {
        textDisplayer->displayText("钥匙...咦，我兜里的钥匙呢");
    }
    else if(!open_door)
    {
        textDisplayer->displayText("你将钥匙插入锁孔中，用力一拧");
        textDisplayer->displayText("只听“咔”一声，你的手上只剩下了钥匙头");
        open_door = true;
    }
    else if(!pin)
    {
        textDisplayer->displayText("你望着锁孔里的半截钥匙，陷入沉思");
    }
    else if(!buttons[10]->isClicked)
    {
        textDisplayer->displayText("机智的你用回形针捅了几下锁孔，门竟然开了");
        textDisplayer->displayText("哇啊，肚子好饿，该搞点吃的...");
        scene->show_livingroom();
        if(tidy){
            scene->hide_bedscene3();
            in_bedscene3 = false;
        }
        else {
            scene->hide_bedscene2();
            in_bedscene2 = false;
        }
        in_livingroom = true;
        player2->stop();
        player3->play();
        scene->person->setPos(128, 210);
        buttons[10]->isClicked = true;
    }
    else
    {
        scene->show_livingroom();
        if(tidy){
            scene->hide_bedscene3();
            in_bedscene3 = false;
        }
        else {
            scene->hide_bedscene2();
            in_bedscene2 = false;
        }
        in_livingroom = true;
        player2->stop();
        player3->play();
        scene->person->setPos(128, 210);
    }
    scene->person->setFocus();
}

void Game::button12Clicked()//查看钟表
{
    //敲击音频
    textDisplayer->displayText("钟声响起");
    player6->play();
    scene->person->setFocus();
}

void Game::button13Clicked()//摘花
{
    textDisplayer->displayText("你毫不犹豫地摘下了可怜的植物身上仅有的三朵花");
    textDisplayer->displayText("“获得物品：三朵快枯萎的花”");
    window->addText("三朵快枯萎的花");
    player5->play();
    flower = true;
    buttons[13]->isClicked = true;
    scene->person->setFocus();
}

void Game::button14Clicked()//挖土
{
    if(!shovel)
    {
        textDisplayer->displayText("你正打算徒手挖土，但又忽然觉得这样做有失北大学生身份，遂放弃");
    }
    else
    {
        textDisplayer->displayText("“获得物品：一张意义不明的纸条”");
        textDisplayer->displayText("“书架上挂着一幅振奋人心的画像，垃圾桶旁的钟表无声地守望着岁月的流转。”");
        window->addText("一张意义不明的纸条：“书架上挂着一");
        window->addText("幅振奋人心的画像，垃圾桶旁的钟表无");
        window->addText("声地守望着岁月的流转。”");
        buttons[14]->isClicked = true;
    }
    scene->person->setFocus();
}

void Game::button15Clicked()//掏垃圾桶
{
    textDisplayer->displayText("喂！你怎么又...");
    textDisplayer->displayText("“获得物品：一张散发恶臭的纸条”");
    textDisplayer->displayText("纸条上写着 “3Fe+_HNO\u2083=3Fe(NO\u2083)\u2082+2NO+4H\u2082O”");
    window->addText("一张散发恶臭的纸条：“3Fe+_HNO\u2083=");
    window->addText("3Fe(NO\u2083)\u2082+2NO+4H\u2082O”");
    player5->play();
    buttons[15]->isClicked = true;
    scene->person->setFocus();
}

void Game::button25Clicked()//拼图游戏
{
    Widget *w = new Widget;
    w->show();
    connect(w, &Widget::win, this, &Game::win_puzzle);
    scene->person->setFocus();
}

void Game::win_puzzle()
{
    textDisplayer->displayText("“获得成就：智力超群的认可”");
    window->addText("成就：智力超群的认可");
}

void Game::button16Clicked()//前往卧室
{
    scene->show_bedscene3();
    scene->hide_livingroom();
    in_livingroom = false;
    in_bedscene3 = true;
    buttons[16]->isClicked = true;
    player3->stop();
    player2->play();
    scene->person->setPos(852, 124);
    scene->person->setFocus();
}

void Game::button17Clicked()//掏垃圾桶
{
    textDisplayer->displayText("还来...是信科让你变成这样的吗");
    textDisplayer->displayText("垃圾桶几天没倒了，散发着腐臭的气息，你不禁捏住了鼻子");
    buttons[17]->isClicked = true;
    scene->person->setFocus();
}

void Game::button18Clicked()//打开冰箱
{
    textDisplayer->displayText("“获得物品：一只不知放了多久的鸡腿，似乎有一些微妙的气味”");
    window->addText("一只不知放了多久的鸡腿，似乎有一些");
    window->addText("微妙的气味");
    player5->play();
    chicken = true;
    buttons[18]->isClicked = true;
    scene->person->setFocus();
}

void Game::button19Clicked()//打开橱柜
{
    scene->show_kscene3();
    scene->hide_kscene1();
    in_kscene1 = false;
    in_kscene3 = true;
    last_k = 3;
    buttons[19]->isClicked = true;
    scene->person->setFocus();
}

void Game::button20Clicked()//拿取铲子
{
    scene->show_kscene2();
    scene->hide_kscene3();
    in_kscene3 = false;
    in_kscene2 = true;
    last_k = 2;
    textDisplayer->displayText("“获得物品：一把不知道为什么会出现在这里的铲子”");
    window->addText("一把不知道为什么会出现在这里的铲子");
    player5->play();
    buttons[20]->isClicked = true;
    shovel = true;
    scene->person->setFocus();
}

void Game::button21Clicked()//查看菜谱
{
    CustomWindow2 *window2 = new CustomWindow2;
    window2->show();
    scene->person->setFocus();
}

void Game::button22Clicked()//开始烹饪
{
    if(chicken && flower){
        //进入小游戏
        player4->stop();
        MainWindow *w = new MainWindow();
        w->show();  
        connect(w, &MainWindow::win, this, &Game::win_kitchen);
        connect(w, &MainWindow::lose, this, &Game::lose_kitchen);
    }
    else{
        textDisplayer->displayText("食材不足");
    }
    scene->person->setFocus();
}

void Game::win_kitchen()
{
    player4->play();
    textDisplayer->displayText("甜甜花酿鸡，完成！");
}

void Game::lose_kitchen()
{
    player4->play();
    textDisplayer->displayText("锅里的甜甜花酿鸡完全被烤焦了，看起来不太能吃");
    textDisplayer->displayText("只好再做一份了");
}

void Game::button23Clicked()//前往客厅
{
    scene->show_livingroom();
    if(last_k == 1){
        scene->hide_kscene1();
        in_kscene1 = false;
    }
    if(last_k == 2){
        scene->hide_kscene2();
        in_kscene2 = false;
    }
    if(last_k == 3){
        scene->hide_kscene3();
        in_kscene3 = false;
    }
    in_livingroom = true;
    buttons[22]->isClicked = true;
    player4->stop();
    player3->play();
    scene->person->setPos(128, 210);
    scene->person->setFocus();
}

void Game::button24Clicked()//前往厨房
{
    if(last_k == 1){
        scene->show_kscene1();
        in_kscene1 = true;
    }
    if(last_k == 2){
        scene->show_kscene2();
        in_kscene2 = true;
    }
    if(last_k == 3){
        scene->show_kscene3();
        in_kscene3 = true;
    }
    scene->hide_livingroom();
    in_livingroom = false;
    buttons[23]->isClicked = true;
    player3->stop();
    player4->play();
    scene->person->setPos(1010, 268);
    scene->person->setFocus();
}
