#include "mainwindow.hpp"

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app{argc, argv};
    QWarhammerSimulator::Gui::MainWindow m;
    m.show();
    return app.exec();
}
