#include "game_kitchen/mymap.h"
#include<QPushButton>
#include<stdio.h>
#include<game_kitchen/gem.h>
#include<QPaintEvent>
#include<QPainter>
#include<QDebug>
#include<QThread>
#include<QEventLoop>
#include<QTimer>
#include <QtGlobal>
#include <QRandomGenerator>
#include<QSoundEffect>
#include<QLabel>

MyMap::MyMap(QWidget *parent)
    : QMainWindow{parent}
{
    lptr=new QPushButton(parent);
    lptr->setGeometry(630,60,150,150);
    lptr->setText("Your score is :  "+QString::number(score));
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            gemmap[i][j]=new gem(this);
            gemmap[i][j]->gemid=0;
        }
    }
    for(int i=2;i<13;i++){
        for(int j=2;j<13;j++){
            mapp[i][j]=new QPushButton(parent);
            mapp[i][j]->setGeometry(50*i-40,50*j-40,50,50);
            gemmap[i][j]->bunptr=mapp[i][j];
        }
    }
    mptr=new QPushButton(parent);
    mptr->setGeometry(630,250,150,50);
    mptr->setText("reshuffle("+QString::number(2-clickretimes)+")");
}

void MyMap::initsetting(){
    for (int i = 12; i >1 ; --i) {
        for(int j=12;j>1;j--){
            gemmap[i][j]->gemid=QRandomGenerator::global()->generate()%12+1;
            while(singalremove(i,j)){
                gemmap[i][j]->gemid=QRandomGenerator::global()->generate()%12+1;
            }
            gemmap[i][j]->showimg();
        }
    }
    QSoundEffect *startSound=new QSoundEffect;
    startSound->setSource(QUrl::fromLocalFile(":/qt picgr/jc2dc-7lyds.wav"));//           这里填写背景音乐文件，这个播放器只支持wav
    startSound->play();
}

bool MyMap::singalremove(int x,int y){
    int temp=gemmap[x][y]->gemid;
    int l[2]={gemmap[x-1][y]->gemid,gemmap[x-2][y]->gemid};
    int r[2]={gemmap[x+1][y]->gemid,gemmap[x+2][y]->gemid};
    int u[2]={gemmap[x][y+1]->gemid,gemmap[x][y+2]->gemid};
    int d[2]={gemmap[x][y-1]->gemid,gemmap[x][y-2]->gemid};
    bool f=0;
    if(temp==l[0]&&temp==l[1])
        f=1;
    if(temp==r[0]&&temp==r[1])
        f=1;
    if(temp==u[0]&&temp==u[1])
        f=1;
    if(temp==d[0]&&temp==d[1])
        f=1;
    if(temp==l[0]&&temp==r[0])
        f=1;
    if(temp==u[0]&&temp==d[0])
        f=1;
    return f;
}

void MyMap::swap(){
    qDebug()<<"swap answered";
    if(firsti==secondi){
        if(firstj==secondj+1||firstj==secondj-1){
            gem* t=gemmap[firsti][firstj];
            gemmap[firsti][firstj]->bunptr=mapp[secondi][secondj];
            gemmap[secondi][secondj]->bunptr=mapp[firsti][firstj];
            gemmap[firsti][firstj]=gemmap[secondi][secondj];
            gemmap[secondi][secondj]=t;
            gemmap[firsti][firstj]->showimg();
            gemmap[secondi][secondj]->showimg();
        }
    }
    else if(firstj==secondj){
        if(firsti==secondi+1||firsti==secondi-1){
            gem* t=gemmap[firsti][firstj];
            gemmap[firsti][firstj]->bunptr=mapp[secondi][secondj];
            gemmap[secondi][secondj]->bunptr=mapp[firsti][firstj];
            gemmap[firsti][firstj]=gemmap[secondi][secondj];
            gemmap[secondi][secondj]=t;
            gemmap[firsti][firstj]->showimg();
            gemmap[secondi][secondj]->showimg();
        }
    }
}

void MyMap::clickevent(){
    clicktimes++;
    if(clicktimes%2!=0){
        firsti=secondi;
        firstj=secondj;
        QSoundEffect *startSound=new QSoundEffect;
        startSound->setSource(QUrl::fromLocalFile(":/qt picgr/firstclickpic.wav"));
        startSound->play();
    }
    else{
        swap();
        if((!singalremove(firsti,firstj))&&(!singalremove(secondi,secondj))){
            qDebug()<<"Invalid move";
            //QThread::sleep(1);
            QSoundEffect *startSound=new QSoundEffect;
            startSound->setSource(QUrl::fromLocalFile(":/qt picgr/wrongmove.wav"));
            startSound->play();
            QEventLoop eventloop;
            QTimer::singleShot(300, &eventloop, SLOT(quit())); //wait 0.5s
            eventloop.exec();
            swap();
        }
        else if(singalremove(firsti,firstj)){
            QSoundEffect *startSound=new QSoundEffect;
            startSound->setSource(QUrl::fromLocalFile(":/qt picgr/secondclickpic.wav"));
            startSound->play();
            QEventLoop eventloop;
            QTimer::singleShot(300, &eventloop, SLOT(quit())); //wait 0.5s
            eventloop.exec();
            score+=3;
            lptr->setText("Your score is :  "+QString::number(score));
            validmove(firsti,firstj);
        }
        else if(singalremove(secondi,secondj)){
            QSoundEffect *startSound=new QSoundEffect;
            startSound->setSource(QUrl::fromLocalFile(":/qt picgr/secondclickpic.wav"));
            startSound->play();
            QEventLoop eventloop;
            QTimer::singleShot(300, &eventloop, SLOT(quit())); //wait 0.5s
            eventloop.exec();
            score+=3;
            lptr->setText("Your score is :  "+QString::number(score));
            validmove(secondi,secondj);
        }
    }
}

int MyMap::validmove(int x,int y){
    int temp=gemmap[x][y]->gemid;
    int l[2]={gemmap[x-1][y]->gemid,gemmap[x-2][y]->gemid};
    int r[2]={gemmap[x+1][y]->gemid,gemmap[x+2][y]->gemid};
    int u[2]={gemmap[x][y+1]->gemid,gemmap[x][y+2]->gemid};
    int d[2]={gemmap[x][y-1]->gemid,gemmap[x][y-2]->gemid};
    if(temp==l[0]&&temp==l[1]){
        gemmap[x][y]->gemid=QRandomGenerator::global()->generate()%12+1;
        while(singalremove(x,y)){
            gemmap[x][y]->gemid=QRandomGenerator::global()->generate()%12+1;
        }
        gemmap[x][y]->showimg();
        gemmap[x-1][y]->gemid=QRandomGenerator::global()->generate()%12+1;
        while(singalremove(x-1,y)){
            gemmap[x-1][y]->gemid=QRandomGenerator::global()->generate()%12+1;
        }
        gemmap[x-1][y]->showimg();
        gemmap[x-2][y]->gemid=QRandomGenerator::global()->generate()%12+1;
        while(singalremove(x-2,y)){
            gemmap[x-2][y]->gemid=QRandomGenerator::global()->generate()%12+1;
        }
        gemmap[x-2][y]->showimg();
        return 1;
    }
    if(temp==r[0]&&temp==r[1]){
        gemmap[x][y]->gemid=QRandomGenerator::global()->generate()%12+1;
        while(singalremove(x,y)){
            gemmap[x][y]->gemid=QRandomGenerator::global()->generate()%12+1;
        }
        gemmap[x][y]->showimg();
        gemmap[x+1][y]->gemid=QRandomGenerator::global()->generate()%12+1;
        while(singalremove(x+1,y)){
            gemmap[x+1][y]->gemid=QRandomGenerator::global()->generate()%12+1;
        }
        gemmap[x+1][y]->showimg();
        gemmap[x+2][y]->gemid=QRandomGenerator::global()->generate()%12+1;
        while(singalremove(x+2,y)){
            gemmap[x+2][y]->gemid=QRandomGenerator::global()->generate()%12+1;
        }
        gemmap[x+2][y]->showimg();
        return 2;
    }
    if(temp==u[0]&&temp==u[1]){
        gemmap[x][y]->gemid=QRandomGenerator::global()->generate()%12+1;
        while(singalremove(x,y)){
            gemmap[x][y]->gemid=QRandomGenerator::global()->generate()%12+1;
        }
        gemmap[x][y]->showimg();
        gemmap[x][y+1]->gemid=QRandomGenerator::global()->generate()%12+1;
        while(singalremove(x,y+1)){
            gemmap[x][y+1]->gemid=QRandomGenerator::global()->generate()%12+1;
        }
        gemmap[x][y+1]->showimg();
        gemmap[x][y+2]->gemid=QRandomGenerator::global()->generate()%12+1;
        while(singalremove(x,y+2)){
            gemmap[x][y+2]->gemid=QRandomGenerator::global()->generate()%12+1;
        }
        gemmap[x][y+2]->showimg();
        return 3;
    }
    if(temp==d[0]&&temp==d[1]){
        gemmap[x][y]->gemid=QRandomGenerator::global()->generate()%12+1;
        while(singalremove(x,y)){
            gemmap[x][y]->gemid=QRandomGenerator::global()->generate()%12+1;
        }
        gemmap[x][y]->showimg();
        gemmap[x][y-1]->gemid=QRandomGenerator::global()->generate()%12+1;
        while(singalremove(x,y-1)){
            gemmap[x][y-1]->gemid=QRandomGenerator::global()->generate()%12+1;
        }
        gemmap[x][y-1]->showimg();
        gemmap[x][y-2]->gemid=QRandomGenerator::global()->generate()%12+1;
        while(singalremove(x,y-2)){
            gemmap[x][y-2]->gemid=QRandomGenerator::global()->generate()%12+1;
        }
        gemmap[x][y-2]->showimg();
        return 4;
    }
    if(temp==l[0]&&temp==r[0]){
        gemmap[x][y]->gemid=QRandomGenerator::global()->generate()%12+1;
        while(singalremove(x,y)){
            gemmap[x][y]->gemid=QRandomGenerator::global()->generate()%12+1;
        }
        gemmap[x][y]->showimg();
        gemmap[x+1][y]->gemid=QRandomGenerator::global()->generate()%12+1;
        while(singalremove(x+1,y)){
            gemmap[x+1][y]->gemid=QRandomGenerator::global()->generate()%12+1;
        }
        gemmap[x+1][y]->showimg();
        gemmap[x-1][y]->gemid=QRandomGenerator::global()->generate()%12+1;
        while(singalremove(x-1,y)){
            gemmap[x-1][y]->gemid=QRandomGenerator::global()->generate()%12+1;
        }
        gemmap[x-1][y]->showimg();
        return 5;
    }
    if(temp==u[0]&&temp==d[0]){
        gemmap[x][y]->gemid=QRandomGenerator::global()->generate()%12+1;
        while(singalremove(x,y)){
            gemmap[x][y]->gemid=QRandomGenerator::global()->generate()%12+1;
        }
        gemmap[x][y]->showimg();
        gemmap[x][y+1]->gemid=QRandomGenerator::global()->generate()%12+1;
        while(singalremove(x,y+1)){
            gemmap[x][y+1]->gemid=QRandomGenerator::global()->generate()%12+1;
        }
        gemmap[x][y+1]->showimg();
        gemmap[x][y-1]->gemid=QRandomGenerator::global()->generate()%12+1;
        while(singalremove(x,y-1)){
            gemmap[x][y-1]->gemid=QRandomGenerator::global()->generate()%12+1;
        }
        gemmap[x][y-1]->showimg();
        return 6;
    }
    return 0;
}
