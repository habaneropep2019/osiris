#include "qmag.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    MagWidget m;
    a.setMainWidget(&m);
    m.show();
    return a.exec();
}
