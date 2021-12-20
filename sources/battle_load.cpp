#include <battle_graphics.hpp>

void Battle::LoadChar()
{
    stud[0] = Character("/home/sovest/CLionProjects/KURSACH/config/Damager.txt", LOC[0]);
    stud[1] = Character("/home/sovest/CLionProjects/KURSACH/config/Archer.txt", LOC[1]);
    stud[2] = Character("/home/sovest/CLionProjects/KURSACH/config/Tank.txt", LOC[2]);
    stud[3] = Character("/home/sovest/CLionProjects/KURSACH/config/Wisard.txt", LOC[3]);
}

void Battle::LoadEnemy()
{
    map<string, string> config;
    ifstream input(configfile);
    if (input.is_open())
        while (!input.eof())
        {
            string st;
            getline(input, st);
            string st1 = st.substr(0, st.find(' '));
            st.erase(0, st.find(' ') + 1);
            string st2 = st.substr(2, st.size());
            config[st1] = st2;
        }
    input.close();
    enemy[0] = Enemy(config["Enemy1"], LOC[4]);
    enemy[1] = Enemy(config["Enemy2"], LOC[5]);
    enemy[2] = Enemy(config["Enemy3"], LOC[6]);
    enemy[3] = Enemy(config["Enemy4"], LOC[7]);
}

void Battle::LoadLabels()
{
    for (int i = 0; i < 4; ++i)
    {
        name[i] = new QLabel(QString::fromStdString(stud[i].getName() + ' ' + stud[i].getHP()), this);
        name[i]->move(LOC[i].first, LOC[i].second);
        name[i]->resize(200, 20);
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
    youwin.load("/home/sovest/CLionProjects/KURSACH/images/youwin.png");
    gameover.load("/home/sovest/CLionProjects/KURSACH/images/gameover.png");
    levelup.load("/home/sovest/CLionProjects/KURSACH/images/levelup.png");
}
