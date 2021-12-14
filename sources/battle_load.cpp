#include <battle_graphics.hpp>

void Battle::LoadChar()
{
    stud[0] = Character("/home/sovest/CLionProjects/KURSACH/char_config/Damager.txt", LOC[0]);
    stud[1] = Character("/home/sovest/CLionProjects/KURSACH/char_config/Archer.txt", LOC[1]);
    stud[2] = Character("/home/sovest/CLionProjects/KURSACH/char_config/Tank.txt", LOC[2]);
    stud[3] = Character("/home/sovest/CLionProjects/KURSACH/char_config/Wisard.txt", LOC[3]);
}

void Battle::LoadEnemy()
{
    enemy[0] = Enemy("/home/sovest/CLionProjects/KURSACH/enemy_config/enemy1.txt", LOC[4]);
    enemy[1] = Enemy("/home/sovest/CLionProjects/KURSACH/enemy_config/enemy1.txt", LOC[5]);
    enemy[2] = Enemy("/home/sovest/CLionProjects/KURSACH/enemy_config/enemy1.txt", LOC[6]);
    enemy[3] = Enemy("/home/sovest/CLionProjects/KURSACH/enemy_config/enemy1.txt", LOC[7]);
}

void Battle::LoadLabels()
{
    for (int i = 0; i < 4; ++i)
    {
        name[i] = new QLabel(QString::fromStdString(stud[i].getName() + ' ' + stud[i].getHP()), this);
        name[i]->move(LOC[i].first, LOC[i].second);
        name[i]->resize(100, 20);
        name[i]->show();
    }

    for (int i = 0; i < 4; ++i)
    {
        name[i + 4] = new QLabel(QString::fromStdString(enemy[i].getName() + ' ' + enemy[i].getHP()), this);
        name[i + 4]->move(LOC[i + 4].first, LOC[i + 4].second - 20);
        name[i + 4]->resize(100, 20);
        name[i + 4]->show();
    }
}

void Battle::LoadImages()
{
    back.load("/home/sovest/CLionProjects/KURSACH/images/back.png");
    target.load("/home/sovest/CLionProjects/KURSACH/images/target.png");
    bam.load("/home/sovest/CLionProjects/KURSACH/images/bam.png");
    grave.load("/home/sovest/CLionProjects/KURSACH/images/grave.png");
    arrow.load("/home/sovest/CLionProjects/KURSACH/images/arrow.png");
    fireball[0].load("/home/sovest/CLionProjects/KURSACH/images/fireball_1.png");
    fireball[1].load("/home/sovest/CLionProjects/KURSACH/images/fireball_2.png");
}
