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
    srand(time(NULL));

    LoadImages();
    LoadChar();
    LoadEnemy();
    LoadLabels();

    InitGame();
}

void Battle::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    QPainter painter(this);
    if ((enemy[0].dead() && enemy[1].dead() && enemy[2].dead() && enemy[3].dead()) ||
        (stud[0].dead() && stud[1].dead() && stud[2].dead() && stud[3].dead()))
        finishGame(&painter);

    doDrowing();
}

void Battle::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);
    if (!attacking && !recieving)

        if (turn < 4)
        {
            click1 = turn;
            if (stud[turn].dead())
                turn++;
        }
        if (turn >= 4)
        {
            if (!enemy[turn - 4].dead())
                recieving = true;
            else
            {
                turn++;
                if (turn == 8)
                    turn = 0;
            }
        }

    repaint();
}

void Battle::InitGame()
{
    timerId = startTimer(DELAY);
}

void Battle::finishGame(QPainter *)
{
    result = new QLabel("Game Over", this);
    result->move(LOC[1].first, LOC[1].second);
    result->resize(100, 20);
    result->show();
}
