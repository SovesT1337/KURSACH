// Copyright by SovesT 2021
// Created by sovest on 18.10.2021.
//

#ifndef KURSACH_CHARACTER_HPP
#define KURSACH_CHARACTER_HPP

#include <string>
using std::string;

class Character {
private:
    string Name;
    int HP;
    int MP;
    int Attack;
    int Armor;
    int Level;

public:
    Character(string, int, int, int, int, int);

    ~Character();

    int attack() const;

    int magic_attack(int, int);

    void get_damage(int);

    void recover_mana(int);

    void recover_health(int);

    void level_up(int);

    void death();
};

#endif //KURSACH_CHARACTER_HPP
