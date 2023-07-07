#ifndef GEM_H
#define GEM_H

#include <QObject>
#include<QLabel>
#include<QPushButton>

class gem : public QObject
{
    Q_OBJECT
public:
    explicit gem(QObject *parent = nullptr);
    QPushButton* bunptr;
    int gemid;

    void showimg();
signals:

};

#endif // GEM_H
