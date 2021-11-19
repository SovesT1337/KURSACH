// Copyright by SovesT 2021
// Created by sovest on 30.10.2021.
//


#include <battle_graphics.hpp>

int battle(int argc, char *argv[]) {
    QApplication battle(argc, argv);

    Battle window;

    window.resize(1920, 1080);
    window.setWindowTitle("BATTLE");
    window.show();

    return battle.exec();
}

Battle::Battle(QWidget *parent) {
    click1 = 0;
    click2 = 0;
    frame = 0;
    LoadChar();
    LoadImages();
    LoadLabels();
    InitGame();
}

void Battle::paintEvent(QPaintEvent * e) {
    Q_UNUSED(e);

    doDrowing();
}

void Battle::timerEvent(QTimerEvent * e) {
    Q_UNUSED(e);

    repaint();
}

void Battle::keyPressEvent(QKeyEvent * e) {
    if (e->key() == Qt::Key_Escape) QApplication::quit();
}

void Battle::LoadImages() {

}

void Battle::InitGame() {
    timerId = startTimer(DELAY);
}

void Battle::doDrowing() {

    QPainter qp(this);

    qp.drawImage(0, 0, enemy1);

    if (frame < 3) {
        qp.drawImage(char1.getRect(), char1.getImage(0));
        qp.drawImage(char2.getRect(), char2.getImage(0));
        qp.drawImage(char3.getRect(), char3.getImage(0));
        qp.drawImage(char4.getRect(), char4.getImage(0));
    }
    else {
        qp.drawImage(char1.getRect(), char1.getImage(1));
        qp.drawImage(char2.getRect(), char2.getImage(1));
        qp.drawImage(char3.getRect(), char3.getImage(1));
        qp.drawImage(char4.getRect(), char4.getImage(1));
    }
    frame++;
    if (frame == 6) frame = 0;
}

void Battle::LoadChar() {
    char1 = Character("/home/sovest/CLionProjects/KURSACH/char_config/Tank.txt", LOC1);
    char2 = Character("/home/sovest/CLionProjects/KURSACH/char_config/Damager.txt", LOC2);
    char3 = Character("/home/sovest/CLionProjects/KURSACH/char_config/Wisard.txt", LOC3);
    char4 = Character("/home/sovest/CLionProjects/KURSACH/char_config/Archer.txt", LOC4);
}

void Battle::LoadEnemy() {
    enemy1 = Enemy("/home/sovest/CLionProjects/KURSACH/enemy_config/enemy1.txt", LOC5);
}

void Battle::mousePressEvent(QMouseEvent * e) {
    if(e->button() == Qt::LeftButton and char1.getRect_()->contains(e->pos())){
        click1 = 1;
    }
    if(e->button() == Qt::LeftButton and char2.getRect_()->contains(e->pos())){
        click1 = 2;
    }
    if(e->button() == Qt::LeftButton and char3.getRect_()->contains(e->pos())){
        click1 = 3;
    }
    if(e->button() == Qt::LeftButton and char4.getRect_()->contains(e->pos())){
        click1 = 4;
    }
}

void Battle::LoadLabels() {
    cname1 = new QLabel(QString::fromStdString(char1.getName()), this);
    cname1->move(LOC1.first, LOC1.second);
    cname1->show();

    cname2 = new QLabel(QString::fromStdString(char2.getName()), this);
    cname2->move(LOC2.first, LOC2.second);
    cname2->show();

    cname3 = new QLabel(QString::fromStdString(char3.getName()), this);
    cname3->move(LOC3.first, LOC3.second);
    cname3->show();

    cname4 = new QLabel(QString::fromStdString(char4.getName()), this);
    cname4->move(LOC4.first, LOC4.second);
    cname4->show();
}
