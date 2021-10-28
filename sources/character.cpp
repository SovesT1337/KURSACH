// Copyright by SovesT 2021
// Created by sovest on 18.10.2021.
//

#include <character.hpp>

Character::Character(int HP_, int MP_, int Attack_, int Armor_, int Level_) {
    HP = HP_;
    MP = MP_;
    Attack = Attack_;
    Armor = Armor_;
    Level = Level_;
}

int Character::attack() const {
    return Attack;
}

int Character::magic_attack(int Attack_, int mana_usage) {
    MP -= mana_usage;
    return Attack_;
}

void Character::get_damage(int damage) {
    HP -= damage - Armor;
}

void Character::recover_health(int heal) {
    HP += heal;
}

void Character::recover_mana(int heal) {
    MP += heal;
}

void Character::level_up(int n) {
    Level += n;
}
