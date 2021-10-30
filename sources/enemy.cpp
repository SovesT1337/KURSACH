// Copyright by SovesT 2021
// Created by sovest on 27.10.2021.
//

#include <enemy.hpp>

Enemy::Enemy(string Name_, int HP_, int MP_, int Attack_, int Armor_, int Level_) {
    Name = Name_;
    HP = HP_;
    MP = MP_;
    Attack = Attack_;
    Armor = Armor_;
    Level = Level_;
}

int Enemy::attack() const {
    return Attack;
}

int Enemy::magic_attack(int Attack_, int mana_usage) {
    MP -= mana_usage;
    return Attack_;
}

void Enemy::get_damage(int damage) {
    HP -= damage - Armor;
}

void Enemy::recover_health(int heal) {
    HP += heal;
}

void Enemy::recover_mana(int heal) {
    MP += heal;
}

void Enemy::level_up(int n) {
    Level += n;
}

//void Enemy::death() {
//    Enemy::~Enemy();
//}

int Enemy::fire_ball() {
    return Enemy::magic_attack(20, 10);
}
