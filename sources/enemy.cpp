// Copyright by SovesT 2021
// Created by sovest on 27.10.2021.
//

#include <enemy.hpp>
#include <utility>
#include <map>
#include <fstream>
#include <iostream>

using std::map;
using std::ifstream;
using std::ofstream;

Enemy::Enemy() {
    Name = "Clyde";
    HP = 1;
    MP = 1;
    Attack = 1;
    Armor = 1;
    Level = 1;
}

Enemy::Enemy(string file, pair<int, int> loc) {
    map<string, string> config;
    ifstream input(file);
    if (input.is_open()){
        while (!input.eof()){
            string st;
            getline(input, st);
            string st1 = st.substr(0, st.find(' '));
            st.erase(0, st.find(' ') + 1);
            string st2 = st.substr(2, st.size());
            config[st1] = st2;
        }
    }
    Name = std::move(config["Name"]);
    HP = stoi(config["HP"]);
    MP = stoi(config["MP"]);
    Attack = stoi(config["Attack"]);
    Armor = stoi(config["Armor"]);
    Level = stoi(config["Level"]);
    image[0].load(QString::fromStdString(config["Image1"]));
    image[1].load(QString::fromStdString(config["Image2"]));
    rect = image[0].rect();
    location = loc;
    rect.moveTo(location.first, location.second);
}

int Enemy::attack() const {
    return Attack;
}

int Enemy::magic_attack(int Attack_, int mana_usage) {
    MP -= mana_usage;
    return Attack_;
}

void Enemy::get_damage(int damage) {
    this->HP -= damage - Armor;
    std::cout << damage << HP << std::endl;
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

Enemy Enemy::operator=(Enemy * rhs) {
    Enemy a(rhs->Name, rhs->HP, rhs->MP, rhs->Attack, rhs->Armor, rhs->Level);
    return a;
}

int Enemy::getHP() {
    return HP;
}

Enemy::~Enemy() = default;
