#include <battle_graphics.hpp>

void Battle::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        QApplication::quit();
    if (e->key() == Qt::Key_Enter)
        Attack();
    if (e->key() == Qt::Key_1 && !enemy[0].dead())
        click2 = 4;
    if (e->key() == Qt::Key_2 && !enemy[1].dead())
        click2 = 5;
    if (e->key() == Qt::Key_3 && !enemy[2].dead())
        click2 = 6;
    if (e->key() == Qt::Key_4 && !enemy[3].dead())
        click2 = 7;
}

void Battle::mousePressEvent(QMouseEvent *e)
{

    if (e->button() == Qt::LeftButton)
    {

        // if (stud[0].getRect_()->contains(e->pos()))
        //     click1 = 0;

        // if (stud[1].getRect_()->contains(e->pos()))
        //     click1 = 1;

        // if (stud[2].getRect_()->contains(e->pos()))
        //     click1 = 2;

        // if (stud[3].getRect_()->contains(e->pos()))
        //     click1 = 3;

        if (enemy[0].getRect_()->contains(e->pos()))
            click2 = 4;

        if (enemy[1].getRect_()->contains(e->pos()))
            click2 = 5;

        if (enemy[2].getRect_()->contains(e->pos()))
            click2 = 6;

        if (enemy[3].getRect_()->contains(e->pos()))
            click2 = 7;
    }
}
