#include <battle_graphics.hpp>

void Battle::drawchar(QPainter &qp, int i, int frame)
{
    if (!stud[i].dead())
        qp.drawImage(LOC[i].first - dx[i], LOC[i].second, stud[i].getImage(int(frame < 3) + vtech[i]));
    else
        qp.drawImage(LOC[i].first - dx[i], LOC[i].second, grave);
}

void Battle::drawenemy(QPainter &qp, int i, int frame)
{
    if (!enemy[i].dead())
        qp.drawImage(LOC[i + 4].first - dx[i + 4], LOC[i + 4].second, enemy[i].getImage(int(frame < 3)));
    else
        qp.drawImage(LOC[i + 4].first - dx[i + 4], LOC[i].second, grave);
}

void Battle::doDrowing()
{

    QPainter qp(this);

    // qp.drawImage(0, 0, back);

    for (int i = 0; i < 4; ++i)
        drawchar(qp, i, frame);

    for (int i = 0; i < 4; ++i)
        drawenemy(qp, i, frame);

    if (!attacking && !recieving)
    {
        qp.drawImage(LOC[turn].first, LOC[turn].second, target);
        if (click2 != -1)
            qp.drawImage(LOC[click2].first, LOC[click2].second, target);
    }

    if (attacking)
    {
        if (stud[turn].getType() == "Archer")
            Range_Attack(qp);
        if (stud[turn].getType() == "Damager")
            Attack(qp);
        if (stud[turn].getType() == "Tank")
            Attack(qp);
        if (stud[turn].getType() == "Wisard")
            Fireball(qp);
    }

    if (recieving)
    {
        Recieve(qp);
    }

    frame = (frame + 1) % 6;
}