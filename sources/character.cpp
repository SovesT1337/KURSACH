// Copyright by SovesT 2021
// Created by sovest on 18.10.2021.
//

#include <character.hpp>
#include <utility>
#include <map>
#include <fstream>

using std::ifstream;
using std::map;
using std::ofstream;

Character::Character()
{
    Name = "Clyde";
    HP = 1;
    MP = 1;
    Attack = 1;
    Armor = 1;
    Level = 1;
}

Character::Character(string file, pair<int, int> loc)
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
    image[2].load(QString::fromStdString(config["Image3"]));
    image[3].load(QString::fromStdString(config["Image4"]));
    rect = image[0].rect();
    location = loc;
    rect.moveTo(location.first, location.second);
}

int Character::attack() const
{
    return Attack + (Attack * (rand() % 2) / 2);
}

int Character::magic_attack(int Attack_, int mana_usage)
{
    MP -= mana_usage;
    return Attack_;
}

void Character::get_damage(int damage)
{
    HP -= damage - Armor;
}

string Character::getHP()
{
    return std::to_string(HP);
}

void Character::recover_health(int heal)
{
    HP += heal;
}

void Character::recover_mana(int heal)
{
    MP += heal;
}

void Character::level_up(int n)
{
    Level += n;
}

Character Character::operator=(Character *rhs)
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

QImage Character::getImage(int n)
{
    return image[n];
}

QRect Character::getRect()
{
    return rect;
}

QRect *Character::getRect_()
{
    return &rect;
}

pair<int, int> Character::getLocation()
{
    return location;
}

string Character::getName()
{
    return Name;
}

Character::~Character() = default;

bool Character::dead() { return HP <= 0; }
