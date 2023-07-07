#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    void win_();
    ~Widget();
private:
    Ui::Widget *ui;
signals:
    void win();
};
#endif // WIDGET_H
