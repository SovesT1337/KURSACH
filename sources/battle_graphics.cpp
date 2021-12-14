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
        switch (turn < 4)
        {
        case true:
        {
            click1 = turn;
            if (stud[turn].dead())
                turn++;
            break;
        }
        case false:
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
        }
    repaint();
}

int track(int loc1, int loc2)
{
    return (loc1 - loc2) / 10;
}

void Battle::Range_Attack(QPainter &qp)
{
    int dfx = track(LOC[turn].first, LOC[click2].first),
        dfy = track(LOC[turn].second, LOC[click2].second);
    step++;
    if (step < 10)
        dx[turn] += 10;
    if (step == 10)
        vtech[turn] = 2;
    if (step == 25)
        vtech[turn] = 0;
    if (step > 25 && step < 35)
    {
        fx -= dfx;
        fy -= dfy;
        qp.drawImage(LOC[turn].first + 20 - dx[turn] + fx, LOC[turn].second + 90 + fy, arrow);
    }
    if (step == 35)
    {
        fx = 0;
        fy = 0;
    }
    if (step >= 35 && step < 40)
        qp.drawImage(LOC[click2].first, LOC[click2].second, bam);
    if (step == 35)
    {

        enemy[click2 - 4].get_damage(stud[turn].attack());
        if (enemy[click2 - 4].dead())
            delete name[click2];
        else
            name[click2]->setText(QString::fromStdString(enemy[click2 - 4].getName() + ' ' + enemy[click2 - 4].getHP()));
    }
    if (step >= 40 && step < 50)
    {
        dx[turn] -= 10;
    }
    if (step == 50)
    {
        step = 0;
        dx[turn] = 0;
        turn++;
        attacking = false;
        click2 = -1;
    }
}

void Battle::Fireball(QPainter &qp)
{
    int dfx = track(LOC[turn].first, LOC[click2].first),
        dfy = track(LOC[turn].second, LOC[click2].second);
    step++;
    if (step < 10)
        dx[turn] += 10;
    if (step == 10)
        vtech[turn] = 2;
    if (step == 25)
        vtech[turn] = 0;
    if (step > 25 && step < 35)
    {
        fx -= dfx;
        fy -= dfy;
        qp.drawImage(LOC[turn].first + 20 - dx[turn] + fx, LOC[turn].second + 40 + fy, fireball[step % 2]);
    }
    if (step == 35)
    {
        fx = 0;
        fy = 0;
    }
    if (step >= 35 && step < 40)
        qp.drawImage(LOC[click2].first, LOC[click2].second, bam);
    if (step == 35)
    {

        enemy[click2 - 4].get_damage(stud[turn].attack());
        if (enemy[click2 - 4].dead())
            delete name[click2];
        else
            name[click2]->setText(QString::fromStdString(enemy[click2 - 4].getName() + ' ' + enemy[click2 - 4].getHP()));
    }
    if (step >= 40 && step < 50)
    {
        dx[turn] -= 10;
    }
    if (step == 50)
    {
        step = 0;
        dx[turn] = 0;
        turn++;
        attacking = false;
        click2 = -1;
    }
}

void Battle::Attack(QPainter &qp)
{
    step++;
    if (step < 20)
        dx[turn] += 10;
    if (step >= 25 && step < 30)
        qp.drawImage(LOC[click2].first, LOC[click2].second, bam);
    if (step == 25)
    {
        vtech[turn] = 2;
        enemy[click2 - 4].get_damage(stud[turn].attack());
        if (enemy[click2 - 4].dead())
            delete name[click2];
        else
            name[click2]->setText(QString::fromStdString(enemy[click2 - 4].getName() + ' ' + enemy[click2 - 4].getHP()));
    }
    if (step >= 30 && step < 50)
    {
        vtech[turn] = 0;
        dx[turn] -= 10;
    }
    if (step == 50)
    {
        step = 0;
        dx[turn] = 0;
        turn++;
        attacking = false;
        click2 = -1;
    }
}

void Battle::randatk(int damage)
{
    click2 = rand() % 4;
    while (stud[click2].dead())
    {
        click2++;
        if (click2 == 4)
            click2 = 0;
    }
    stud[click2].get_damage(damage);
    if (stud[click2].dead())
        delete name[click2];
    else
        name[click2]->setText(QString::fromStdString(stud[click2].getName() + ' ' + stud[click2].getHP()));
}

void Battle::Recieve(QPainter &qp)
{
    step++;
    if (step < 20)
        dx[turn] -= 10;

    if (step >= 25 && step < 30)
        qp.drawImage(700, 500, bam);

    if (step == 25)
    {
        randatk(enemy[turn - 4].attack());
        click2 = -1;
    }

    if (step >= 30 && step < 50)
        dx[turn] += 10;

    if (step == 50)
    {
        step = 0;
        dx[turn] = 0;
        turn++;
        recieving = false;
        if (turn == 8)
            turn = 0;
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
