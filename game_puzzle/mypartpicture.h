#ifndef MYPARTPICTURE_H
#define MYPARTPICTURE_H

#include <QWidget>
#include<game_puzzle/mypiece.h>
#include<QPushButton>
#include "widget.h"

class MyPartPicture : public QWidget
{
    Q_OBJECT
public:
    explicit MyPartPicture(QWidget *parent = nullptr);
    MyPiece* mapp[5][5];
    int mypicarray[5][5];
    bool isWin();
    void letsplay();
    int clicktimes=0;
    MyPiece *tmpptr=nullptr;
    MyPiece *tmpptr0=nullptr;
    Widget* wtr=nullptr;
public slots:
    void playing();
signals:
    void myclicksig();

};

#endif // MYPARTPICTURE_H
