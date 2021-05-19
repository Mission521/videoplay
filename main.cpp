#include "videoplay.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginwid w;
    w.show();
    return a.exec();
}
