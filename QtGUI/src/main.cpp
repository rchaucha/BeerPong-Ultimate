#include "QtGUI.hpp"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtGUI w;
    w.show();
    return a.exec();
}