#include "game_puzzle/mypiece.h"
#include<QString>
#include<QPushButton>
#include<QPainter>
#include<QPixmap>
#include<QDebug>
#include<QMediaPlayer>
#include<QSoundEffect>

MyPiece::MyPiece(QWidget *parent)
    : QWidget{parent}
{

}

MyPiece::MyPiece(int xx,int yy,int q,QString p,QWidget *parent)
    :QWidget{parent}
{
    bun=new QPushButton(parent);
    bun->setFixedSize(100,100);
    bun->setGeometry(100*xx+142,100*yy+195,100,100);
    cyq=q;
    x=xx;
    y=yy;
    QPixmap pix;
    pix.load(p);

    bun->setIcon(pix);
    bun->setIconSize(QSize(bun->height(),bun->width()));
}

void swappattons(MyPiece* p1,MyPiece* p2){
    int px,py,pc;

    px=p1->x;
    py=p1->y;
    pc=p1->cyq;
    p1->x=p2->x;
    p1->y=p2->y;
    //p1->cyq=p2->cyq;
    p2->x=px;
    p2->y=py;
    //p2->cyq=pc;
    p1->bun->setGeometry(100*p1->x+142,100*p1->y+195,100,100);
  //  qDebug()<<p1->x<<p1->y;
    p2->bun->setGeometry(100*p2->x+142,100*p2->y+195,100,100);
 //   qDebug()<<p2->x<<p2->y;
}
