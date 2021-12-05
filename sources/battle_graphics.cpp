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
    click1 = -1;
    click2 = -1;
    attacking = false;
    recieving = false;
    frame = 0;
    step = 0;
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

    if (turn < 4 && attacking == 0){
        click1 = turn;
        if (stud[turn].dead()) turn++;
        }
    if (turn >= 4 && attacking == 0)
        Recieve();

    repaint();
}

void Battle::Attack()
{
    if (click2 != -1 && !attacking && !recieving)
    {
        attacking = true;
    }
}

void Battle::randatk(int damage)
{
    click2 = rand() % 4;
    stud[click2].get_damage(damage);
    name[click2]->setText(QString::fromStdString(stud[click2].getName() + ' ' + stud[click2].getHP()));
}

void Battle::Recieve()
{
    if (!enemy[turn - 4].dead() && !recieving)
    {
        recieving = true;
    }
    if (enemy[turn - 4].dead())
    {
        if (turn == 8)
            turn = 0;
        turn++;
    }
}

void Battle::InitGame()
{
    timerId = startTimer(DELAY);
}

void Battle::finishGame(QPainter *)
{
    QApplication::quit();
}
