#include <QApplication>
#include <QPushButton>
#include <battle_graphics.hpp>
#include <main_menu.hpp>

void refresh()
{
    ofstream out("/home/sovest/CLionProjects/KURSACH/config/Archer.txt");
    out << "Name = Saxman\n"
           "Type = Archer\n"
           "HP = 100\n"
           "MP = 10\n"
           "Attack = 30\n"
           "Armor = 9\n"
           "Level = 1\n"
           "Image1 = /home/sovest/CLionProjects/KURSACH/images/archer_1.png\n"
           "Image2 = /home/sovest/CLionProjects/KURSACH/images/archer_2.png\n"
           "Image3 = /home/sovest/CLionProjects/KURSACH/images/archer_3.png\n"
           "Image4 = /home/sovest/CLionProjects/KURSACH/images/archer_4.png";
    out.close();
    out.open("/home/sovest/CLionProjects/KURSACH/config/Damager.txt");
    out << "Name = Trendkiller\n"
           "Type = Damager\n"
           "HP = 100\n"
           "MP = 10\n"
           "Attack = 30\n"
           "Armor = 9\n"
           "Level = 1\n"
           "Image1 = /home/sovest/CLionProjects/KURSACH/images/damager_1.png\n"
           "Image2 = /home/sovest/CLionProjects/KURSACH/images/damager_2.png\n"
           "Image3 = /home/sovest/CLionProjects/KURSACH/images/damager_3.png\n"
           "Image4 = /home/sovest/CLionProjects/KURSACH/images/damager_4.png";
    out.close();
    out.open("/home/sovest/CLionProjects/KURSACH/config/Tank.txt");
    out << "Name = Viktor\n"
           "Type = Tank\n"
           "HP = 100\n"
           "MP = 10\n"
           "Attack = 30\n"
           "Armor = 9\n"
           "Level = 1\n"
           "Image1 = /home/sovest/CLionProjects/KURSACH/images/tank_1.png\n"
           "Image2 = /home/sovest/CLionProjects/KURSACH/images/tank_2.png\n"
           "Image3 = /home/sovest/CLionProjects/KURSACH/images/tank_3.png\n"
           "Image4 = /home/sovest/CLionProjects/KURSACH/images/tank_4.png";
    out.close();
    out.open("/home/sovest/CLionProjects/KURSACH/config/Wisard.txt");
    out << "Name = Katia\n"
           "Type = Wisard\n"
           "HP = 100\n"
           "MP = 10\n"
           "Attack = 30\n"
           "Armor = 9\n"
           "Level = 1\n"
           "Image1 = /home/sovest/CLionProjects/KURSACH/images/wisard_1.png\n"
           "Image2 = /home/sovest/CLionProjects/KURSACH/images/wisard_2.png\n"
           "Image3 = /home/sovest/CLionProjects/KURSACH/images/wisard_3.png\n"
           "Image4 = /home/sovest/CLionProjects/KURSACH/images/wisard_4.png";
    out.close();
}

int main(int argc, char *argv[])
{
    refresh();
    menu(argc, argv);
    battle(argc, argv);
}
