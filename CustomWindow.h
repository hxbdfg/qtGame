#ifndef CUSTOMWINDOW_H
#define CUSTOMWINDOW_H

#include <QtWidgets>
#include "CustomButton.h"

class CustomWindow : public QWidget {
public:
    CustomWindow(QWidget *parent = nullptr) : QWidget(parent) {
        // 设置窗口大小和标题
        setFixedSize(459, 543);
        setWindowTitle("Custom Window");

        // 创建一个标签控件用于显示文本
        label = new QLabel(this);
        label->setAlignment(Qt::AlignTop | Qt::AlignLeft);
        label->setGeometry(60, 50, 380, 580);
        label->setStyleSheet("QLabel { line-height: 60px;}");
        QFont font("楷体", 14, QFont::Bold);
        label->setFont(font);

        // 创建自定义关闭按钮
        closeButton = new CustomButton2("Close", this);
        closeButton->setGeometry(380, 38, 20, 20);

        // 设置窗口形状为自定义图片形状
        setWindowShape(":/images/item_paper.png");
        // 设置窗口样式为自定义图片
        setWindowBackgroundImage(":/images/item_paper.png");


        // 连接关闭按钮的点击信号和槽函数
        connect(closeButton, &QPushButton::clicked, this, &CustomWindow::close);

        connect(this, &QWidget::destroyed, this, &CustomWindow::onWindowClosed);
    }

    // 向窗口内添加文字
    void addText(const QString& text) {
        label->setText(label->text() + "\n" + text);
    }

protected:
    // 监听键盘事件
    void keyPressEvent(QKeyEvent *event) override {
        if (event->key() == Qt::Key_M) {
            show();
            activateWindow();
            raise();
        }
        QWidget::keyPressEvent(event);
    }

private slots:
    // 窗口关闭时的槽函数
    void onWindowClosed() {
        qApp->quit();
    }

private:
    QLabel *label;
    CustomButton2 *closeButton;
    // 设置窗口背景图片
    void setWindowBackgroundImage(const QString& imagePath) {
        QPixmap pixmap(imagePath);
        QPalette palette;
        palette.setBrush(backgroundRole(), QBrush(pixmap.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
        setPalette(palette);
    }

    // 设置窗口形状为自定义图片形状
    void setWindowShape(const QString& imagePath) {
        QImage image(imagePath);
        QBitmap mask = QBitmap::fromImage(image.createAlphaMask(Qt::ColorOnly));
        setMask(mask);
    }
};

class CustomWindow1 : public QWidget {
public:
    CustomWindow1(QWidget *parent = nullptr) : QWidget(parent) {
        // 设置窗口大小和标题
        setFixedSize(556, 535);
        setWindowTitle("Custom Window");

        // 创建自定义关闭按钮
        closeButton = new CustomButton2("Close", this);
        closeButton->setGeometry(420, 88, 14, 14);

        // 设置窗口为自定义图片
        setWindowShape(":/images/agenda.png");
        setWindowBackgroundImage(":/images/agenda.png");

        // 连接关闭按钮的点击信号和槽函数
        connect(closeButton, &QPushButton::clicked, this, &CustomWindow1::close);

        connect(this, &QWidget::destroyed, this, &CustomWindow1::onWindowClosed);
    }

private slots:
    // 窗口关闭时的槽函数
    void onWindowClosed() {
        qApp->quit(); // 退出应用程序
    }

private:
    CustomButton2 *closeButton;
    // 设置窗口背景图片
    void setWindowBackgroundImage(const QString& imagePath) {
        QPixmap pixmap(imagePath);
        QPalette palette;
        palette.setBrush(backgroundRole(), QBrush(pixmap.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
        setPalette(palette);
    }
    // 设置窗口形状为自定义图片形状
    void setWindowShape(const QString& imagePath) {
        QImage image(imagePath);
        QBitmap mask = QBitmap::fromImage(image.createAlphaMask(Qt::ColorOnly));
        setMask(mask);
    }
};

class CustomWindow2 : public QWidget {
public:
    CustomWindow2(QWidget *parent = nullptr) : QWidget(parent) {
        // 设置窗口大小和标题
        setFixedSize(433, 249);
        setWindowTitle("Custom Window");

        // 创建自定义关闭按钮
        closeButton = new CustomButton2("Close", this);
        closeButton->setGeometry(345, 30, 6, 6);

        // 设置窗口为自定义图片
        setWindowShape(":/images/chicken.png");
        setWindowBackgroundImage(":/images/chicken.png");

        // 连接关闭按钮的点击信号和槽函数
        connect(closeButton, &QPushButton::clicked, this, &CustomWindow2::close);
    }

private slots:
    // 窗口关闭时的槽函数
    void onWindowClosed() {
        qApp->quit(); // 退出应用程序
    }

private:
    CustomButton2 *closeButton;
    // 设置窗口背景图片
    void setWindowBackgroundImage(const QString& imagePath) {
        QPixmap pixmap(imagePath);
        QPalette palette;
        palette.setBrush(backgroundRole(), QBrush(pixmap.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));
        setPalette(palette);
    }
    // 设置窗口形状为自定义图片形状
    void setWindowShape(const QString& imagePath) {
        QImage image(imagePath);
        QBitmap mask = QBitmap::fromImage(image.createAlphaMask(Qt::ColorOnly));
        setMask(mask);
    }
};


#endif // CUSTOMWINDOW_H
