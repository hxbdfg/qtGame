#ifndef MYPIECE_H
#define MYPIECE_H

#include <QWidget>
#include<QString>
#include<QPushButton>

class MyPiece : public QWidget
{
    Q_OBJECT
public:
    explicit MyPiece(QWidget *parent = nullptr);
    explicit MyPiece(int xx,int yy,int q,QString p=" ",QWidget* parent=nullptr);
    QPushButton* bun=nullptr;
    int cyq;
    int x=0;
    int y=0;

    friend void swappattons(MyPiece* p1,MyPiece* p2);
signals:

};

#endif // MYPIECE_H
