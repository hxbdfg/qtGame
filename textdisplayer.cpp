#include "textdisplayer.h"

TextDisplayer::TextDisplayer(QWidget *parent)
    : QWidget(parent), m_currentCharIndex(0)
{
    setAttribute(Qt::WA_TranslucentBackground);
    connect(&m_displayTimer, &QTimer::timeout, this, &TextDisplayer::updateTextDisplay);
    connect(&m_clearTimer, &QTimer::timeout, this, &TextDisplayer::clearTextDisplay);
}

void TextDisplayer::displayText(const QString &text)
{
    m_textQueue.push(text); // 将新文本添加到队列中

    if (m_isTextCleared &&!m_displayTimer.isActive()) {
        // 如果当前没有正在显示的文本，则开始显示下一段文本
        showNextText();
    }
}

void TextDisplayer::showNextText()
{
    if (!m_textQueue.empty()) {
        QString nextText = m_textQueue.front();
        m_textQueue.pop();

        m_textToDisplay = nextText;
        m_currentCharIndex = 0;
        m_displayTimer.start(60);
        m_isTextCleared = false; // 设置标志表示当前文本未完全消失
    }
}

void TextDisplayer::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // 在文本上方画一条线
    if (!m_currentText.isEmpty()) {
        int lineHeight = 20;
        painter.setPen(Qt::black);

        painter.drawLine(0, height() / 2 - lineHeight - 1, width(), height() / 2 - lineHeight - 1);
        painter.drawLine(0, height() / 2 - lineHeight + 1, width(), height() / 2 - lineHeight + 1);


        // 绘制原始文本
        painter.setPen(Qt::white);
        painter.drawLine(0, height() / 2 - lineHeight, width(), height() / 2 - lineHeight);
    }
    // 绘制文本
        painter.setPen(Qt::black);
        QFont font = painter.font();
        font.setPointSize(15);
        font.setWeight(QFont::Bold); // 设置粗体字
        painter.setFont(font);
        int offset = 1; // 偏移量
        // 绘制四次文本，分别在上、下、左、右方向上添加黑边
        painter.drawText(rect().translated(-offset, 0), Qt::AlignCenter, m_currentText);
        painter.drawText(rect().translated(offset, 0), Qt::AlignCenter, m_currentText);
        painter.drawText(rect().translated(0, -offset), Qt::AlignCenter, m_currentText);
        painter.drawText(rect().translated(0, offset), Qt::AlignCenter, m_currentText);

        // 绘制原始文本
        painter.setPen(Qt::white);
        painter.drawText(rect(), Qt::AlignCenter, m_currentText);
}

void TextDisplayer::updateTextDisplay()
{
    if (m_currentCharIndex < m_textToDisplay.length())
    {
        m_currentText.append(m_textToDisplay.at(m_currentCharIndex));
        m_currentCharIndex++;
        m_isTextCleared = false; // 设置标志表示当前文本未完全消失
        update();
    }
    else
    {
        m_displayTimer.stop();
        m_clearTimer.start(1500);
    }
}

void TextDisplayer::clearTextDisplay()
{
    m_clearTimer.stop();
    m_currentText.clear();
    m_isTextCleared = true; // 设置标志表示当前文本已完全消失
    m_currentCharIndex = 0; // 重置字符索引
    update();
    if (!m_textQueue.empty()) {
        // 如果队列中还有待显示的文本，则显示下一段文本
        showNextText();
    }
}
