// Copyright by SovesT 2021
// Created by sovest on 27.10.2021.
//

#ifndef KURSACH_ENEMY_HPP
#define KURSACH_ENEMY_HPP

#include <string>
#include <utility>
#include <QImage>
#include <QRect>

using std::pair;
using std::string;
using std::vector;

class Enemy{
private:
    string Name;
    int HP;
    int MP;
    int Attack;
    int Armor;
    int Level;
    QImage image[4];
    QRect rect;
    pair<int, int> location;

public:
    Enemy();
    Enemy(string, pair<int, int>);
    ~Enemy();
    int attack() const;
    int magic_attack(int, int);
    void get_damage(int);
    void recover_mana(int);
    void recover_health(int);
    void level_up(int);
    QImage getImage(int);
    QRect getRect();
    QRect* getRect_();
    string getName();
    string getHP();
    pair<int, int> getLocation();
    Enemy operator=(Enemy*);
    bool dead();
};

#endif //KURSACH_ENEMY_HPP
