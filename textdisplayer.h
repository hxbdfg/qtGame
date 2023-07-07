#ifndef TEXTDISPLAYER_H
#define TEXTDISPLAYER_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QPaintEvent>
#include <queue>

class TextDisplayer : public QWidget
{
    Q_OBJECT

public:
    explicit TextDisplayer(QWidget *parent = nullptr);
    void displayText(const QString &text);

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void updateTextDisplay();
    void clearTextDisplay();
    void showNextText();

private:
    QString m_textToDisplay;
    QString m_currentText;
    int m_currentCharIndex;
    std::queue<QString> m_textQueue;
    QTimer m_displayTimer;
    QTimer m_clearTimer;
    bool m_isTextCleared = true;

};



#endif // TEXTDISPLAYER_H
