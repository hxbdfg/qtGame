#include "game_puzzle/mypartpicture.h"
#include<game_puzzle/mypiece.h>
#include<QPushButton>
#include<QDeBug>
#include<QPainter>
#include<QMediaPlayer>
#include<QSoundEffect>
#include<QEventLoop>
#include<QTimer>

MyPartPicture::MyPartPicture(QWidget *parent)
    : QWidget{parent}
{

    mapp[0][0]=new MyPiece(0,0,8,":/qt pic/8.jpg",parent);
    mypicarray[0][0]=8;
    mapp[0][1]=new MyPiece(0,1,15,":/qt pic/15.jpg",parent);
    mypicarray[0][1]=15;
    mapp[0][2]=new MyPiece(0,2,12,":/qt pic/12.jpg",parent);
    mypicarray[0][2]=12;
    mapp[0][3]=new MyPiece(0,3,18,":/qt pic/18.jpg",parent);
    mypicarray[0][3]=18;
    mapp[0][4]=new MyPiece(0,4,20,":/qt pic/20.jpg",parent);
    mypicarray[0][4]=20;
    mapp[1][0]=new MyPiece(1,0,4,":/qt pic/4.jpg",parent);
    mypicarray[1][0]=4;
    mapp[1][1]=new MyPiece(1,1,7,":/qt pic/7.jpg",parent);
    mypicarray[1][1]=7;
    mapp[1][2]=new MyPiece(1,2,0,":/qt pic/0.jpg",parent);
    mypicarray[1][2]=0;
    mapp[1][3]=new MyPiece(1,3,13,":/qt pic/13.jpg",parent);
    mypicarray[1][3]=13;
    mapp[1][4]=new MyPiece(1,4,11,":/qt pic/11.jpg",parent);
    mypicarray[1][4]=11;
    mapp[2][0]=new MyPiece(2,0,23,":/qt pic/23.jpg",parent);
    mypicarray[2][0]=23;
    mapp[2][1]=new MyPiece(2,1,5,":/qt pic/5.jpg",parent);
    mypicarray[2][1]=5;
    mapp[2][2]=new MyPiece(2,2,19,":/qt pic/19.jpg",parent);
    mypicarray[2][2]=19;
    mapp[2][3]=new MyPiece(2,3,1,":/qt pic/1.jpg",parent);
    mypicarray[2][3]=1;
    mapp[2][4]=new MyPiece(2,4,21,":/qt pic/21.jpg",parent);
    mypicarray[2][4]=21;
    mapp[3][0]=new MyPiece(3,0,17,":/qt pic/17.jpg",parent);
    mypicarray[3][0]=17;
    mapp[3][1]=new MyPiece(3,1,9,":/qt pic/9.jpg",parent);
    mypicarray[3][1]=9;
    mapp[3][2]=new MyPiece(3,2,14,":/qt pic/14.jpg",parent);
    mypicarray[3][2]=14;
    mapp[3][3]=new MyPiece(3,3,16,":/qt pic/16.jpg",parent);
    mypicarray[3][3]=16;
    mapp[3][4]=new MyPiece(3,4,24,":/qt pic/24.jpg",parent);
    mypicarray[3][4]=24;
    mapp[4][0]=new MyPiece(4,0,22,":/qt pic/22.jpg",parent);
    mypicarray[4][0]=22;
    mapp[4][1]=new MyPiece(4,1,2,":/qt pic/2.jpg",parent);
    mypicarray[4][1]=2;
    mapp[4][2]=new MyPiece(4,2,10,":/qt pic/10.jpg",parent);
    mypicarray[4][2]=10;
    mapp[4][3]=new MyPiece(4,3,3,":/qt pic/3.jpg",parent);
    mypicarray[4][3]=3;
    mapp[4][4]=new MyPiece(4,4,6,":/qt pic/6.jpg",parent);
    mypicarray[4][4]=6;
}

bool MyPartPicture::isWin(){
    bool f=1;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            qDebug()<<mapp[i][j]->cyq<<mapp[i][j]->x<<mapp[i][j]->y;
            if(mapp[i][j]->cyq-(5*mapp[i][j]->y+mapp[i][j]->x)!=0){
                f=0;
                break;
            }
        }
    }

    return f;
}

void MyPartPicture::letsplay(){
    //while(true)
/*
    QSoundEffect *startSound=new QSoundEffect;
    startSound->setSource(QUrl::fromLocalFile(":/qt pic/picpicwin.ogg"));
    startSound->play();
*/

    if(isWin()){
        for(int i=0;i<5;i++){
            for (int j = 0; j < 5; ++j) {
                disconnect(mapp[i][j]->bun,&QPushButton::clicked,this,
                        0);
            }
        }
        QSoundEffect *startSound=new QSoundEffect;
        startSound->setSource(QUrl::fromLocalFile(":/qt pic/picpicwinwin.wav"));
        startSound->play();

        QEventLoop eventloop;
        QTimer::singleShot(3000, &eventloop, SLOT(quit())); //wait 3s
        eventloop.exec();
        wtr->win_();
        wtr->close();
        return;
    }
}

void MyPartPicture::playing(){
    clicktimes++;
    if(clicktimes%2==0){
        swappattons(tmpptr,tmpptr0);
        QSoundEffect *startSound=new QSoundEffect;
        startSound->setSource(QUrl::fromLocalFile(":/qt pic/secondclickpic.wav"));
        startSound->play();
        if(isWin()){
            emit myclicksig();
        }
    }
    else{
        QSoundEffect *startSound=new QSoundEffect;
        startSound->setSource(QUrl::fromLocalFile(":/qt pic/firstclickpic.wav"));
        startSound->play();
        tmpptr0=tmpptr;
    }
}
