// Copyright by SovesT 2021
// Created by sovest on 18.10.2021.
//

#ifndef KURSACH_CHARACTER_HPP
#define KURSACH_CHARACTER_HPP

#include <string>
using std::string;

class Character {
private:
    int HP;
    int MP;
    string type;
    int level;

public:
    Character();

    ~Character();
};

#endif //KURSACH_CHARACTER_HPP
