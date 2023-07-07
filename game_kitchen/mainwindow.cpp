#include "game_kitchen/mainwindow.h"
#include "game_kitchen/ui_mainwindow.h"
#include<game_kitchen/mymap.h>
#include<game_kitchen/gem.h>
#include<QPaintEvent>
#include<QPainter>
#include<QtMultimedia>
#include<QMediaPlayer>
#include<QSoundEffect>
#include<QProgressBar>
#include<QTime>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer;
    audioOutput = new QAudioOutput(this);
    audioOutput->setVolume(0.5);
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl("qrc:/qt picgr/bgm.wav"));
    player->setLoops(-1);
    player->play();
    progressBar = new QProgressBar(this);
    progressBar->setGeometry(60,650,550,30);
    progressBar->setStyleSheet("\
                              QProgressBar::chunk {\
                                  background-color: #CD96CD;\
                                  width: 10px;\
                                  margin: 0.5px;\
                              }");
    progressBar->setRange(0,80);
    progressBar->setValue(80);
    progressBar->setFormat("%v");
    progressBar->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);
    qtimer = new QTimer(this);
    connect(qtimer, SIGNAL(timeout()), this, SLOT(time_out()));
    MyMap *mpboard=new MyMap(this);
    QMessageBox::StandardButton reply;
    reply=QMessageBox::information(this,tr("Tips"),"You should get 40 points within 80s.");
    mapptr=mpboard;
    qtimer->start(800);
    mpboard->initsetting();
    for(int i=2;i<13;i++){
        for(int j=2;j<13;j++){
            connect(mpboard->mapp[i][j],&QPushButton::clicked,this,
                [=](){
                    mpboard->secondi=i;mpboard->secondj=j;
                    mpboard->clickevent();
            });
        }
    }
    connect(mpboard->mptr,&QPushButton::clicked,this,[=](){
        if(mpboard->clickretimes<2)
            mpboard->initsetting();
        mpboard->clickretimes++;

        mpboard->mptr->setText("reshuffle("+QString::number(2-mpboard->clickretimes)+")");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::paintEvent(QPaintEvent*){
    this->setFixedSize(800,730);
    QPainter* painter=new QPainter(this);
    QPixmap pic;
    pic.load(":/qt picgr/OIPP.jpg");
    painter->drawPixmap(0,0,this->width(),this->height(),pic);
    painter->end();
}

void MainWindow::time_out()
{
    --temp;
    progressBar->setValue(temp);
    if(temp == 0)
    {
        qtimer->stop();
        temp = 80;
        ending=1;
        if(mapptr->score>=40){
            QMessageBox::StandardButton reply;
            reply=QMessageBox::information(this,tr("Tips"),"You win!");
            emit win();
            player->stop();
            this->close();
        }
        else{
            QMessageBox::StandardButton reply;
            reply=QMessageBox::information(this,tr("Tips"),"You lose!");
            emit lose();
            player->stop();
            this->close();
        }
    }

}
