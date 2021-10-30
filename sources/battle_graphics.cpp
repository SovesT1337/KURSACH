// Copyright by SovesT 2021
// Created by sovest on 30.10.2021.
//

#include <battle_graphics.hpp>

MyButton::MyButton(QWidget *parent) : QWidget(parent) {
    QPushButton *quitBtn = new QPushButton("Quit", this);
    quitBtn->setGeometry(50, 40, 75, 30);

    connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);
}

int battle(int argc, char *argv[]) {
    QApplication battle(argc, argv);

    MyButton window;

    window.resize(1920, 1080);
    window.setWindowTitle("BATTLE");
    window.show();

    return battle.exec();
}
