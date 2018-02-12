#include "haircutmainwidj.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HaircutMainWidj w;
    w.show();

    return a.exec();
}
