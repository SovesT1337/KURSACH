#include <battle_graphics.hpp>

void Battle::drawchar(QPainter &qp, int i, int frame)
{
    if (!stud[i].dead())
    {
        if (frame < 3)
            qp.drawImage(LOC[i].first - dx[i], LOC[i].second, stud[i].getImage(0));
        else
            qp.drawImage(LOC[i].first - dx[i], LOC[i].second, stud[i].getImage(1));
    }
    if (stud[i].dead())
        qp.drawImage(LOC[i].first - dx[i], LOC[i].second, grave);
}

void Battle::drawenemy(QPainter &qp, int i, int frame)
{
    if (!enemy[i].dead())
    {
        if (frame < 3)
            qp.drawImage(LOC[i + 4].first - dx[i + 4], LOC[i + 4].second, enemy[i].getImage(0));
        else
            qp.drawImage(LOC[i + 4].first - dx[i + 4], LOC[i + 4].second, enemy[i].getImage(1));
    }
    if (enemy[i].dead())
        qp.drawImage(LOC[i + 4].first - dx[i + 4], LOC[i].second, grave);
}

void Battle::doDrowing()
{

    QPainter qp(this);

    if (!attacking && !recieving)
    {

        // if (click1 != -1)
        qp.drawImage(LOC[turn].first, LOC[turn].second, target);

        if (click2 != -1)
            qp.drawImage(LOC[click2].first, LOC[click2].second, target);
    }

    if (attacking)
    {
        step++;
        if (step < 20)
            dx[turn] += 10;
        if (step >= 25 && step < 30)
            qp.drawImage(700, 500, bam);
        if (step == 25)
        {
            enemy[click2 - 4].get_damage(stud[turn].attack());
            if (enemy[click2 - 4].dead())
                name[click2]->setText(QString::fromStdString(enemy[click2 - 4].getName() + " DEAD"));
            else
                name[click2]->setText(QString::fromStdString(enemy[click2 - 4].getName() + ' ' + enemy[click2 - 4].getHP()));
        }
        if (step >= 30 && step < 50)
            dx[turn] -= 10;
        if (step == 50)
        {
            step = 0;
            dx[turn] = 0;
            turn++;
            attacking = false;
            click2 = -1;
        }
    }

    if (recieving)
    {
        step++;
        if (step < 20)
            dx[turn] -= 10;
        if (step >= 25 && step < 30)
            qp.drawImage(700, 500, bam);
        if (step == 25)
        {
            randatk(enemy[turn - 4].attack());
            click2 = 0;
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

    for (int i = 0; i < 4; ++i)
        drawchar(qp, i, frame);

    for (int i = 0; i < 4; ++i)
        drawenemy(qp, i, frame);

    frame++;
    if (frame == 6)
        frame = 0;
}