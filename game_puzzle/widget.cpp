#include "game_puzzle/widget.h"
#include "ui_widget.h"
#include<game_puzzle/mypartpicture.h>
#include<QPushButton>
#include<QDebug>
#include<QPainter>
#include<QPaintEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //MyPiece* p=new MyPiece(":/qt pic/0.jpg",this);
    MyPartPicture* ptr=new MyPartPicture(this);
    ptr->wtr=this;
for(int i=0;i<5;i++){
        for (int j = 0; j < 5; ++j) {
            connect(ptr->mapp[i][j]->bun,&QPushButton::clicked,ptr,
                    [=](){
                        ptr->tmpptr=ptr->mapp[i][j];
                        ptr->playing();
                    });
        }
    }
connect(ptr,&MyPartPicture::myclicksig,ptr,&MyPartPicture::letsplay);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent*) {
    this->setFixedSize(800,840);
    QPainter* painter=new QPainter(this);
    QPixmap pic;
    pic.load(":/qt pic/OIP.jpg");
    painter->drawPixmap(0,0,this->width(),this->height(),pic);
    painter->end();
}

void Widget::win_()
{
    emit win();
}
