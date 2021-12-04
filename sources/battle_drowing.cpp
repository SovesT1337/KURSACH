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
}

void Battle::doDrowing()
{

    QPainter qp(this);

    if (!attacking && !recieving)
    {

        if (click1 != -1)
            qp.drawImage(LOC[click1].first, LOC[click1].second, target);

        if (click2 != -1)
            qp.drawImage(LOC[click2].first, LOC[click2].second, target);
    }

    if (attacking)
    {
        step++;
        if (step < 20)
            dx[turn] += 10;
        if (step >= 30 && step < 50)
            dx[turn] -= 10;
        if (step == 50)
        {
            step = 0;
            dx[turn] = 0;
            turn++;
            attacking = false;
        }
    }

    if (recieving)
    {
        step++;
        if (step < 20)
            dx[turn] -= 10;
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