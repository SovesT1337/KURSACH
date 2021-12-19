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
#include <unistd.h>
#include <time.h>

#include <enemy.hpp>
#include <character.hpp>

class Battle : public QWidget
{
private:
    int click1 = -1;
    int click2 = -1;
    bool attacking = false;
    bool recieving = false;
    int frame = 0;
    int step = 0;
    int turn = 0;
    int timerId;
    int vtech[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int dx[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int fx = 0;
    int fy = 0;

    Enemy enemy1;
    Enemy enemy2;
    Enemy enemy3;
    Enemy enemy4;
    Enemy enemy[4] = {enemy1, enemy2, enemy3, enemy4};

    Character stud1;
    Character stud2;
    Character stud3;
    Character stud4;
    Character stud[4] = {stud1, stud2, stud3, stud4};

    QImage back;
    QImage target;
    QImage bam;
    QImage grave;
    QImage arrow;
    QImage fireball[2];

    QPushButton *btn1;

    QLabel *cname1;
    QLabel *cname2;
    QLabel *cname3;
    QLabel *cname4;
    QLabel *ename1;
    QLabel *ename2;
    QLabel *ename3;
    QLabel *ename4;
    QLabel *name[8] = {cname1, cname2, cname3, cname4, ename1, ename2, ename3, ename4};
    QLabel *result;

    const pair<int, int> LOC[8] = {std::make_pair(1200, 550),
                                   std::make_pair(1300, 650),
                                   std::make_pair(1200, 750),
                                   std::make_pair(1300, 850),
                                   std::make_pair(600, 550),
                                   std::make_pair(500, 650),
                                   std::make_pair(600, 750),
                                   std::make_pair(500, 850)};
    static const int DELAY = 60;

    void LoadImages();
    void InitGame();
    void LoadLabels();
    void doDrowing();
    void LoadChar();
    void LoadEnemy();
    void Attack(QPainter &);
    void Range_Attack(QPainter &);
    void Fireball(QPainter &);
    void Recieve(QPainter &);
    void randatk(int);
    void drawchar(QPainter &, int, int);
    void drawenemy(QPainter &, int, int);

public:
    Battle(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);
    void mousePressEvent(QMouseEvent *);
    void finishGame(QPainter *);
};

int battle(int argc, char *argv[]);

#endif //KURSACH_BATTLE_GRAPHICS_HPP
