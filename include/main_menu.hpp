// Copyright by SovesT 2021
// Created by sovest on 15.12.2021.
//

#ifndef KURSACH_MAIN_MENU_HPP
#define KURSACH_MAIN_MENU_HPP

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QImage>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPainter>

#include <enemy.hpp>
#include <character.hpp>

class Menu : public QWidget
{
private:
    QImage back;

    QLabel *background;

    QPushButton *start;
    QPushButton *exit;
    QPushButton *level01;
    QPushButton *level02;
    QPushButton *level03;

    int timerId;
    static const int DELAY = 60;

public:
    Menu(QWidget *parent = 0);

protected:
    void LoadImages();
    void LoadButtons();
    void InitGame();
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void doDrowing();
};

int menu(int argc, char *argv[]);

#endif // KURSACH_MAIN_MENU_HPP