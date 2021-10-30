// Copyright by SovesT 2021
// Created by sovest on 27.10.2021.
//

#ifndef KURSACH_BATTLE_HPP
#define KURSACH_BATTLE_HPP

#include <character.hpp>
#include <enemy.hpp>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Battle{
private:
    vector<string> enemy;
    vector<Character> character;

public:
    Battle(vector<Enemy>, vector<Character>);

    ~Battle();
};

#endif //KURSACH_BATTLE_HPP
