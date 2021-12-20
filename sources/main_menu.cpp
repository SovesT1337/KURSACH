#include <main_menu.hpp>

int menu(int argc, char *argv[])
{
    QApplication menu(argc, argv);

    Menu window;

    window.resize(1920, 1080);
    window.setWindowTitle("MENU");
    window.show();

    return menu.exec();
}

Menu::Menu(QWidget *parent)
{
    LoadImages();
    LoadButtons();

    InitGame();
}

void Menu::LoadImages()
{    
    back.load("/home/sovest/CLionProjects/KURSACH/images/back.png");
}

void Menu::LoadButtons()
{
    level01 = new QPushButton("Level 1", this);
    level02 = new QPushButton("Level 2", this);
    level03 = new QPushButton("Level 3", this);
    level01->move(900, 300);
    level02->move(900, 400);
    level03->move(900, 500);

    exit = new QPushButton("Exit", this);
    exit->move(1650, 350);

    connect(exit, &QPushButton::clicked, this, &Menu::Exit);
    connect(level01, &QPushButton::clicked, this, &Menu::LoadLevel1);
    connect(level02, &QPushButton::clicked, this, &Menu::LoadLevel2);
    connect(level03, &QPushButton::clicked, this, &Menu::LoadLevel3);
}

void Menu::Exit(){
    ofstream out(configfile);
    QApplication::quit();
}

void Menu::LoadLevel1(){
    ofstream out(configfile);
    out << "Enemy1 = /home/sovest/CLionProjects/KURSACH/config/Enemy1.txt\n";
    out << "Enemy2 = /home/sovest/CLionProjects/KURSACH/config/Enemy1.txt\n";
    out << "Enemy3 = /home/sovest/CLionProjects/KURSACH/config/Enemy1.txt\n";
    out << "Enemy4 = /home/sovest/CLionProjects/KURSACH/config/Enemy1.txt";
    QApplication::quit();
}

void Menu::LoadLevel2(){
    ofstream out(configfile);
    out << "Enemy1 = /home/sovest/CLionProjects/KURSACH/config/Enemy2.txt\n";
    out << "Enemy2 = /home/sovest/CLionProjects/KURSACH/config/Enemy2.txt\n";
    out << "Enemy3 = /home/sovest/CLionProjects/KURSACH/config/Enemy2.txt\n";
    out << "Enemy4 = /home/sovest/CLionProjects/KURSACH/config/Enemy2.txt";
    QApplication::quit();
}

void Menu::LoadLevel3(){
    ofstream out(configfile);
    out << "Enemy1 = /home/sovest/CLionProjects/KURSACH/config/Enemy3.txt\n";
    out << "Enemy2 = /home/sovest/CLionProjects/KURSACH/config/Enemy3.txt\n";
    out << "Enemy3 = /home/sovest/CLionProjects/KURSACH/config/Enemy3.txt\n";
    out << "Enemy4 = /home/sovest/CLionProjects/KURSACH/config/Enemy3.txt";
    QApplication::quit();
}

void Menu::doDrowing()
{
    QPainter qp(this);

    qp.drawImage(0, 0, back);
}

void Menu::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    doDrowing();
}

void Menu::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);
    
    repaint();
}

void Menu::InitGame()
{
    timerId = startTimer(DELAY);
}
