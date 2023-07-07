QT       += core gui
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    game.cpp \
    game_kitchen/gem.cpp \
    game_kitchen/mainwindow.cpp \
    game_kitchen/mymap.cpp \
    game_puzzle/mypartpicture.cpp \
    game_puzzle/mypiece.cpp \
    game_puzzle/widget.cpp \
    main.cpp \
    scene.cpp \
    textdisplayer.cpp \
    widget2048.cpp


HEADERS += \
    CustomButton.h \
    CustomWindow.h \
    game.h \
    game_kitchen/gem.h \
    game_kitchen/mainwindow.h \
    game_kitchen/mymap.h \
    game_kitchen/ui_mainwindow.h \
    game_puzzle/mypartpicture.h \
    game_puzzle/mypiece.h \
    game_puzzle/ui_widget.h \
    game_puzzle/widget.h \
    person.h \
    scene.h \
    textdisplayer.h \
    widget2048.h

FORMS += \
    game_kitchen/mainwindow.ui \
    game_puzzle/widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    game_kitchen/picchat.qrc \
    game_puzzle/picgroup1.qrc \
    game_puzzle/qpic1.qrc \
    resources.qrc \



