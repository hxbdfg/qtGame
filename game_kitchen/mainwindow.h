#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPaintEvent>
#include<QProgressBar>
#include<QTimer>
#include<QtMultimedia>
#include<game_kitchen/mymap.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent*);
    QProgressBar* progressBar;
    QTimer* qtimer;
    int temp=80;
    bool ending=0;
    MyMap* mapptr;
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
signals:
    void win();
    void lose();
public slots:
    void time_out();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
