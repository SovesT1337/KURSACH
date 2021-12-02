// Copyright by SovesT 2021
// Created by sovest on 30.10.2021.
//

#include <battle_graphics.hpp>

int battle(int argc, char *argv[])
{
    QApplication battle(argc, argv);

    Battle window;

    window.resize(1920, 1080);
    window.setWindowTitle("BATTLE");
    window.show();

    return battle.exec();
}

Battle::Battle(QWidget *parent)
{
    click1 = 0;
    click2 = -1;
    attacking = false;
    frame = 0;
    turn = 0;

    LoadChar();
    LoadEnemy();
    LoadImages();
    LoadButtons();
    LoadLabels();

    InitGame();
}

void Battle::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter(this);
    if (enemy[0].dead() and enemy[1].dead() and enemy[2].dead() and enemy[3].dead())
        finishGame(&painter);
    doDrowing();
}

void Battle::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);
    if (turn < 4 && attacking == 0)
        click1 = turn;
    if (turn >= 4 && attacking == 0)
        Recieve();

    repaint();
}

void Battle::Attack()
{
    if (click2 != -1)
    {
        int damage = stud[turn].attack();
        enemy[click2 - 4].get_damage(damage);
        if (enemy[click2 - 4].dead())
            name[click2]->setText(QString::fromStdString(enemy[click2 - 4].getName() + " DEAD"));
        else
            name[click2]->setText(QString::fromStdString(enemy[click2 - 4].getName() + ' ' + enemy[click2 - 4].getHP()));
        // attacking = true;
        click2 = -1;
        turn++;
    }
}

void Battle::randatk(int damage)
{
    int i = rand() % 4;
    stud[i].get_damage(damage);
    name[i]->setText(QString::fromStdString(stud[i].getName() + ' ' + stud[i].getHP()));
}

void Battle::Recieve()
{
    for (int i = 0; i < 4; ++i)
        randatk(enemy[i].attack());
    turn = 0;
}

void Battle::LoadImages()
{
    target.load("/home/sovest/CLionProjects/KURSACH/images/target.png");
}

void Battle::InitGame()
{
    timerId = startTimer(DELAY);
}

void Battle::finishGame(QPainter *)
{
    QApplication::quit();
}
