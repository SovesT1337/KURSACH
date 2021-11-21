// Copyright by SovesT 2021
// Created by sovest on 30.10.2021.
//

#ifndef KURSACH_BATTLE_GRAPHICS_HPP
#define KURSACH_BATTLE_GRAPHICS_HPP

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

class Battle : public QWidget {
private:
    int click1;
    int click2;
    int frame;
    int timerId;

    Enemy enemy1;
    Enemy enemy2;
    Enemy enemy3;
    Enemy enemy4;
    
    Character char1;
    Character char2;
    Character char3;
    Character char4;

    QImage target;

    // QButton btn1;

    QLabel *cname1;
    QLabel *cname2;
    QLabel *cname3;
    QLabel *cname4;
    QLabel *ename1;
    QLabel *ename2;
    QLabel *ename3;
    QLabel *ename4;

    const pair<int, int> LOC1 = std::make_pair(1200, 200);
    const pair<int, int> LOC2 = std::make_pair(1400, 200);
    const pair<int, int> LOC3 = std::make_pair(1200, 400);
    const pair<int, int> LOC4 = std::make_pair(1400, 400);
    const pair<int, int> LOC5 = std::make_pair(400, 200);
    const pair<int, int> LOC6 = std::make_pair(600, 200);
    const pair<int, int> LOC7 = std::make_pair(400, 400);
    const pair<int, int> LOC8 = std::make_pair(600, 400);
    static const int DELAY = 60;

    void LoadImages();
    void InitGame();
    void LoadLabels();
    // void LoadButtons();
    void doDrowing();
    void LoadChar();
    void LoadEnemy();
    void Attack();

public:
    Battle(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);
    void mousePressEvent(QMouseEvent *);

};

int battle(int argc, char *argv[]);

#endif //KURSACH_BATTLE_GRAPHICS_HPP
