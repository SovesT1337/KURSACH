// Copyright by SovesT 2021
// Created by sovest on 27.10.2021.
//

#include <enemy.hpp>
#include <utility>
#include <map>
#include <fstream>

using std::ifstream;
using std::map;
using std::ofstream;

Enemy::Enemy()
{
    Name = "Clyde";
    HP = 1;
    MP = 1;
    Attack = 1;
    Armor = 1;
    Level = 1;
}

Enemy::Enemy(string file, pair<int, int> loc)
{
    map<string, string> config;
    ifstream input(file);
    if (input.is_open())
    {
        while (!input.eof())
        {
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

QImage Enemy::getImage(int n)
{
    return image[n];
}

QRect Enemy::getRect()
{
    return rect;
}

QRect *Enemy::getRect_()
{
    return &rect;
}

int Enemy::attack() const
{
    return Attack;
}

string Enemy::getHP()
{
    return std::to_string(HP);
}

int Enemy::magic_attack(int Attack_, int mana_usage)
{
    MP -= mana_usage;
    return Attack_;
}

void Enemy::get_damage(int damage)
{
    this->HP -= damage - Armor;
}

void Enemy::recover_health(int heal)
{
    HP += heal;
}

void Enemy::recover_mana(int heal)
{
    MP += heal;
}

void Enemy::level_up(int n)
{
    Level += n;
}

Enemy Enemy::operator=(Enemy *rhs)
{
    HP = rhs->HP;
    MP = rhs->MP;
    Attack = rhs->Attack;
    Armor = rhs->Armor;
    Level = rhs->Level;
    image[0] = rhs->image[0];
    image[1] = rhs->image[1];
    rect = rhs->rect;
    location = rhs->location;
    return *this;
}

string Enemy::getName()
{
    return Name;
}

Enemy::~Enemy() = default;

bool Enemy::dead() { return HP <= 0; }
