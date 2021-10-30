// Copyright by SovesT 2021
// Created by sovest on 30.10.2021.
//

#ifndef KURSACH_BATTLE_GRAPHICS_HPP
#define KURSACH_BATTLE_GRAPHICS_HPP

#include <QWidget>
#include <QApplication>
#include <QPushButton>

class MyButton : public QWidget {

public:
    explicit MyButton(QWidget *parent = 0);
};

int battle(int argc, char *argv[]);

#endif //KURSACH_BATTLE_GRAPHICS_HPP
