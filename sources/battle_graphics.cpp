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
    click2 = 0;
    frame = 0;
    LoadChar();
    LoadEnemy();
    LoadImages();
    LoadLabels();
    // LoadButtons();
    InitGame();
}

void Battle::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    doDrowing();
}

void Battle::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);

    repaint();
}

void Battle::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        QApplication::quit();

    if (e->key() == Qt::Key_A)
        Attack();
}

void Battle::Attack()
{
    int damage;
    switch (click1)
    {
    case 1:
        damage = char1.attack();
        break;
    case 2:
        damage = char2.attack();
        break;
    case 3:
        damage = char3.attack();
        break;
    case 4:
        damage = char4.attack();
        break;
    }

    switch (click2)
    {
    case 1:
        enemy1.get_damage(damage);
        ename1->setText(QString::fromStdString(enemy1.getName() + ' ' + enemy1.getHP()));
        break;
    case 2:
        enemy2.get_damage(damage);
        ename2->setText(QString::fromStdString(enemy2.getName() + ' ' + enemy2.getHP()));
        break;
    case 3:
        enemy3.get_damage(damage);
        ename3->setText(QString::fromStdString(enemy3.getName() + ' ' + enemy3.getHP()));
        break;
    case 4:
        enemy4.get_damage(damage);
        ename4->setText(QString::fromStdString(enemy4.getName() + ' ' + enemy4.getHP()));
        break;
    }
    Recieve();
}

void Battle::randatk(int damage)
{
    switch (rand() % 4)
    {
    case 0:
        char1.get_damage(damage);
        break;
    case 1:
        char2.get_damage(damage);
        break;
    case 2:
        char3.get_damage(damage);
        break;
    case 3:
        char4.get_damage(damage);
        break;
    }
}

void Battle::Recieve()
{
    int damage1 = enemy1.attack(),
        damage2 = enemy2.attack(),
        damage3 = enemy3.attack(),
        damage4 = enemy4.attack();
    randatk(damage1);
    randatk(damage2);
    randatk(damage3);
    randatk(damage4);
    cname1->setText(QString::fromStdString(char1.getName() + ' ' + char1.getHP()));
    cname2->setText(QString::fromStdString(char2.getName() + ' ' + char2.getHP()));
    cname3->setText(QString::fromStdString(char3.getName() + ' ' + char3.getHP()));
    cname4->setText(QString::fromStdString(char4.getName() + ' ' + char4.getHP()));
}

void Battle::LoadImages()
{
    target.load("/home/sovest/CLionProjects/KURSACH/images/target.png");
}

void Battle::InitGame()
{
    timerId = startTimer(DELAY);
}

void Battle::doDrowing()
{

    QPainter qp(this);

    switch (click2)
    {
    case 1:
        qp.drawImage(LOC5.first, LOC5.second, target);
        break;
    case 2:
        qp.drawImage(LOC6.first, LOC6.second, target);
        break;
    case 3:
        qp.drawImage(LOC7.first, LOC7.second, target);
        break;
    case 4:
        qp.drawImage(LOC8.first, LOC8.second, target);
        break;
    }

    switch (click1)
    {
    case 1:
        qp.drawImage(LOC1.first, LOC1.second, target);
        break;
    case 2:
        qp.drawImage(LOC2.first, LOC2.second, target);
        break;
    case 3:
        qp.drawImage(LOC3.first, LOC3.second, target);
        break;
    case 4:
        qp.drawImage(LOC4.first, LOC4.second, target);
        break;
    }

    if (frame < 3)
    {
        qp.drawImage(char1.getRect(), char1.getImage(0));
        qp.drawImage(char2.getRect(), char2.getImage(1));
        qp.drawImage(char3.getRect(), char3.getImage(1));
        qp.drawImage(char4.getRect(), char4.getImage(0));

        qp.drawImage(enemy1.getRect(), enemy1.getImage(0));
        qp.drawImage(enemy2.getRect(), enemy2.getImage(1));
        qp.drawImage(enemy3.getRect(), enemy3.getImage(1));
        qp.drawImage(enemy4.getRect(), enemy4.getImage(0));
    }
    else
    {
        qp.drawImage(char1.getRect(), char1.getImage(1));
        qp.drawImage(char2.getRect(), char2.getImage(0));
        qp.drawImage(char3.getRect(), char3.getImage(0));
        qp.drawImage(char4.getRect(), char4.getImage(1));

        qp.drawImage(enemy1.getRect(), enemy1.getImage(1));
        qp.drawImage(enemy2.getRect(), enemy2.getImage(0));
        qp.drawImage(enemy3.getRect(), enemy3.getImage(0));
        qp.drawImage(enemy4.getRect(), enemy4.getImage(1));
    }
    frame++;
    if (frame == 6)
        frame = 0;
}

void Battle::LoadChar()
{
    char1 = Character("/home/sovest/CLionProjects/KURSACH/char_config/Tank.txt", LOC1);
    char2 = Character("/home/sovest/CLionProjects/KURSACH/char_config/Damager.txt", LOC2);
    char3 = Character("/home/sovest/CLionProjects/KURSACH/char_config/Wisard.txt", LOC3);
    char4 = Character("/home/sovest/CLionProjects/KURSACH/char_config/Archer.txt", LOC4);
}

void Battle::LoadEnemy()
{
    enemy1 = Enemy("/home/sovest/CLionProjects/KURSACH/enemy_config/enemy1.txt", LOC5);
    enemy2 = Enemy("/home/sovest/CLionProjects/KURSACH/enemy_config/enemy1.txt", LOC6);
    enemy3 = Enemy("/home/sovest/CLionProjects/KURSACH/enemy_config/enemy1.txt", LOC7);
    enemy4 = Enemy("/home/sovest/CLionProjects/KURSACH/enemy_config/enemy1.txt", LOC8);
}

void Battle::mousePressEvent(QMouseEvent *e)
{

    if (e->button() == Qt::LeftButton)
    {

        if (char1.getRect_()->contains(e->pos()))
        {
            click1 = 1;
        }
        if (char2.getRect_()->contains(e->pos()))
        {
            click1 = 2;
        }
        if (char3.getRect_()->contains(e->pos()))
        {
            click1 = 3;
        }
        if (char4.getRect_()->contains(e->pos()))
        {
            click1 = 4;
        }

        if (enemy1.getRect_()->contains(e->pos()))
        {
            click2 = 1;
        }
        if (enemy2.getRect_()->contains(e->pos()))
        {
            click2 = 2;
        }
        if (enemy3.getRect_()->contains(e->pos()))
        {
            click2 = 3;
        }
        if (enemy4.getRect_()->contains(e->pos()))
        {
            click2 = 4;
        }
    }
}

void Battle::LoadLabels()
{
    cname1 = new QLabel(QString::fromStdString(char1.getName() + ' ' + char1.getHP()), this);
    cname1->move(LOC1.first, LOC1.second);
    cname1->show();

    cname2 = new QLabel(QString::fromStdString(char2.getName() + ' ' + char2.getHP()), this);
    cname2->move(LOC2.first, LOC2.second);
    cname2->show();

    cname3 = new QLabel(QString::fromStdString(char3.getName() + ' ' + char3.getHP()), this);
    cname3->move(LOC3.first, LOC3.second);
    cname3->show();

    cname4 = new QLabel(QString::fromStdString(char4.getName() + ' ' + char4.getHP()), this);
    cname4->move(LOC4.first, LOC4.second);
    cname4->show();

    ename1 = new QLabel(QString::fromStdString(enemy1.getName() + ' ' + enemy1.getHP()), this);
    ename1->move(LOC5.first, LOC5.second - 20);
    ename1->show();

    ename2 = new QLabel(QString::fromStdString(enemy2.getName() + ' ' + enemy2.getHP()), this);
    ename2->move(LOC6.first, LOC6.second - 20);
    ename2->show();

    ename3 = new QLabel(QString::fromStdString(enemy3.getName() + ' ' + enemy3.getHP()), this);
    ename3->move(LOC7.first, LOC7.second - 20);
    ename3->show();

    ename4 = new QLabel(QString::fromStdString(enemy4.getName() + ' ' + enemy4.getHP()), this);
    ename4->move(LOC8.first, LOC8.second - 20);
    ename4->show();
}

// void Battle::LoadButtons()
// {
// }
