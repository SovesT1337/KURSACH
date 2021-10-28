// Copyright by SovesT 2021
// Created by sovest on 27.10.2021.
//

#ifndef KURSACH_ENEMY_HPP
#define KURSACH_ENEMY_HPP

#include <string>

using std::string;

class Enemy{
private:
    int HP;
    int MP;
    int Attack;
    int Armor;
    int Level;

public:
    Enemy(int, int, int, int, int);

    ~Enemy();

    int attack() const;

    int magic_attack(int, int);

    void get_damage(int);

    void recover_mana(int);

    void recover_health(int);

    void level_up(int);
};

class Student : Enemy{
    Student();

    ~Student();

    void fire_ball();
};

#endif //KURSACH_ENEMY_HPP
