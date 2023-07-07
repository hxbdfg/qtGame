#ifndef MYMAP_H
#define MYMAP_H

#include <QMainWindow>
#include<QPushButton>
#include<game_kitchen/gem.h>
#include<QPaintEvent>
#include<QLabel>

class MyMap : public QMainWindow
{
    Q_OBJECT
public:
    explicit MyMap(QWidget *parent = nullptr);
    QPushButton* mapp[15][15];
    gem* gemmap[15][15];
    void initsetting();
    bool singalremove(int x,int y);
    void swap();
    void clickevent();
    int clicktimes;
    int firsti,firstj;
    int secondi,secondj;
    int validmove(int x,int y);
    int score=0;
    QPushButton* lptr;
    QPushButton* mptr;
    int clickretimes=0;
signals:
};

#endif // MYMAP_H
