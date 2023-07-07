#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QGraphicsDropShadowEffect>
#include <QPushButton>
#include <QPainter>
#include <QPainterPath>
class CustomButton : public QPushButton
{
   public:
    CustomButton(const QString &text, QWidget *parent = nullptr) : QPushButton(text, parent) {}

    void hideButton()
    {
        hide();
    }
    void paintEvent(QPaintEvent *event) override
    {
        setStyleSheet("background-color: transparent;"); // 添加这一行代码
        QPushButton::paintEvent(event);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);

        // 绘制椭圆形背景
        int borderRadius = qMin(rect().width(), rect().height()) / 2;
        QRectF buttonRect(rect().x(), rect().y(), rect().width() - 1, rect().height() - 1);
        QPainterPath buttonPath;
        buttonPath.addRoundedRect(buttonRect, borderRadius, borderRadius);

        // 设置渐变背景
        QLinearGradient gradient(buttonRect.topLeft(), buttonRect.bottomRight());
        gradient.setColorAt(0, QColor(140, 190, 255)); // 浅蓝色
        gradient.setColorAt(1, QColor(0, 115, 255));   // 蓝色
        painter.setBrush(gradient);
        painter.setPen(Qt::NoPen);
        painter.drawPath(buttonPath);

        // 绘制按钮边框
        QPen borderPen(Qt::white);
        borderPen.setWidth(3);
        painter.setPen(borderPen);
        painter.drawPath(buttonPath);

        QFont font("华文行楷", 40);
        painter.setFont(font);

        QRectF textRect(buttonRect.adjusted(10, 10, -10, -10));
        painter.setPen(QColor(190, 230, 255, 100));
        painter.drawText(textRect.translated(2.5, 2.5), Qt::AlignCenter, text());

        painter.setPen(Qt::white);
        painter.drawText(textRect, Qt::AlignCenter, text());
    }
    QSize sizeHint() const override
    {
        return QSize(280, 80); // 调整按钮的宽度和高度
    }
};

class CustomButton1 : public QPushButton
{
public:
    CustomButton1(const QString &text, QWidget *parent = nullptr) : QPushButton(text, parent) {}
    bool isClicked = false;

    void hideButton()
    {
        hide();
    }
    void paintEvent(QPaintEvent *event) override
    {
        Q_UNUSED(event);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        // 绘制渐变背景
        QRectF buttonRect = QRectF(0, 0, width(), height());
        QLinearGradient gradient(buttonRect.topLeft(), buttonRect.topRight());

        // 添加颜色点，控制渐变效果
        gradient.setColorAt(0, QColor(255, 255, 255));  // 白色
        gradient.setColorAt(0.3, QColor(240, 240, 240));  // 较浅的灰色
        gradient.setColorAt(0.7, QColor(220, 220, 220));  // 中间的灰色
        gradient.setColorAt(1, QColor(200, 200, 200));  // 较深的灰色

        painter.setBrush(gradient);
        painter.setPen(Qt::NoPen);
        painter.drawRect(buttonRect);

        // 绘制黑边
        painter.setPen(QPen(Qt::black, 1));
        painter.drawLine(buttonRect.topLeft(), buttonRect.topRight());
        painter.drawLine(buttonRect.bottomLeft(), buttonRect.bottomRight());
        painter.drawLine(buttonRect.topRight(), buttonRect.bottomRight());

        QFont font("Arial", 15, QFont::Thin);
        painter.setFont(font);

        // 绘制按钮文本
        painter.setPen(Qt::black);
        painter.drawText(buttonRect, Qt::AlignCenter, text());
    }
    QSize sizeHint() const override
    {
        return QSize(120, 40); // 调整按钮的宽度和高度
    }
};

class CustomButton2 : public QPushButton {
public:
    CustomButton2(const QString &text, QWidget *parent = nullptr) : QPushButton(text, parent) {
        setFixedSize(40, 40); // 设置按钮大小
        setStyleSheet("QPushButton { border: none; }"); // 移除默认边框样式
    }

    void paintEvent(QPaintEvent *event) override {
        QPushButton::paintEvent(event);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing); // 抗锯齿

        QRectF buttonRect = rect().adjusted(3, 3, -3, -3); // 获取按钮区域

        // 绘制白色边框
        painter.setPen(QPen(Qt::white, 2));
        painter.setBrush(Qt::NoBrush);
        painter.drawEllipse(buttonRect);

        // 绘制圆形红色背景
        painter.setPen(Qt::NoPen);
        painter.setBrush(Qt::red);
        painter.drawEllipse(buttonRect.adjusted(2, 2, -2, -2));

        // 绘制白色的叉号
        painter.setPen(QPen(Qt::white, 4)); // 设置线宽
        int centerX = buttonRect.width() / 2 + buttonRect.x();
        int centerY = buttonRect.height() / 2 + buttonRect.y();
        int lineLength = buttonRect.width() / 5; // 线长
        painter.drawLine(centerX - lineLength, centerY -lineLength, centerX + lineLength, centerY + lineLength);
        painter.drawLine(centerX - lineLength, centerY + lineLength, centerX + lineLength, centerY - lineLength);
    }
};
#endif // CUSTOMBUTTON_H
