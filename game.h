#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QLineEdit>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "scene.h"
#include "CustomButton.h"
#include "CustomWindow.h"
#include "textdisplayer.h"

class Game : public QObject
{
    Q_OBJECT

public:
    explicit Game(QObject *parent = nullptr);
    TextDisplayer *textDisplayer;
    bool in_bedscene1 = false;
    bool in_bedscene2 = false;
    bool in_bedscene3 = false;
    bool in_kscene1 = false;
    bool in_kscene2 = false;
    bool in_kscene3 = false;
    bool in_livingroom = false;
    bool tidy = false;

public slots:
    void start();
    void start0();
    void end();
    void button1Clicked();
    void button2Clicked();
    void button3Clicked();
    void button4Clicked();
    void button5Clicked();
    void button6Clicked();
    void button7Clicked();
    void button8Clicked();
    void button9Clicked();
    void button10Clicked();
    void button11Clicked();
    void button12Clicked();
    void button13Clicked();
    void button14Clicked();
    void button15Clicked();
    void button16Clicked();
    void button17Clicked();
    void button18Clicked();
    void button19Clicked();
    void button20Clicked();
    void button21Clicked();
    void button22Clicked();
    void button23Clicked();
    void button24Clicked();
    void button25Clicked();
    void showInventory();
    void win_kitchen();
    void lose_kitchen();
    void win_puzzle();
    void win_2048();
    void lose_2048();

private:
    Scene *scene;
    QGraphicsView *view;
    CustomWindow *window;
    bool pen = false;
    bool ruler = false;
    bool key = false;
    bool pin = false;
    bool open_door = false;
    bool shovel = false;
    bool chicken = false;
    bool flower = false;
    int last_k = 1;
    QMediaPlayer *player1;
    QMediaPlayer *player2;
    QMediaPlayer *player3;
    QMediaPlayer *player4;
    QMediaPlayer *player5;
    QMediaPlayer *player6;
    QMediaPlayer *player7;
    QAudioOutput *audioOutput[7];

public:
    CustomButton *button;
    CustomButton *button0;
    CustomButton *endbutton;
    CustomButton1 *buttons[26];
private slots:
    void checkPosition(int x,int y);
};


#endif // GAME_H
