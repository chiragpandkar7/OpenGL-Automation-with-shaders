#include "stdafx.h"
#include "Visualize.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Visualize w;
    w.show();
    return a.exec();
}
