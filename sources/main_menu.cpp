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
}

void Menu::LoadImages()
{    
    back.load("/home/sovest/CLionProjects/KURSACH/images/back.png");
}

void Menu::LoadButtons()
{
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
