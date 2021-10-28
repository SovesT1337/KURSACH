//
// Created by sovest on 27.10.2021.
//

#ifndef KURSACH_BATTLE_HPP
#define KURSACH_BATTLE_HPP

#include <character.hpp>
#include <enemy.hpp>
#include <vector>

using std::vector;

class Battle{
private:

public:
    Battle();

    ~Battle();

    void enemy_turn();

    void your_turn();
};

#endif //KURSACH_BATTLE_HPP
