#include "game_kitchen/gem.h"
#include<QLabel>
#include<QPushButton>
#include<QString>
#include<QPixmap>

gem::gem(QObject *parent)
    : QObject{parent}
{

}

void gem::showimg(){
    QString s;
    switch(gemid){
    case 1:s=":/qt picgr/111.png";break;
    case 2:s=":/qt picgr/112.png";break;
    case 3:s=":/qt picgr/113.png";break;
    case 4:s=":/qt picgr/114.png";break;
    case 5:s=":/qt picgr/115.png";break;
    case 6:s=":/qt picgr/116.png";break;
    case 7:s=":/qt picgr/117.png";break;
    case 8:s=":/qt picgr/118.png";break;
    case 9:s=":/qt picgr/119.png";break;
    case 10:s=":/qt picgr/120.png";break;
    case 11:s=":/qt picgr/121.png";break;
    case 12:s=":/qt picgr/122.png";break;
    }
    QPixmap pix;
    pix.load(s);
    bunptr->setIcon(pix);
    bunptr->setIconSize(QSize(45,45));
}
