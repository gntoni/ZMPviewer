#include "zmpview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    zmpview w;
    w.show();

    return a.exec();
}
