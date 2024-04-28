#include <qapplication.h>
#include "rot13.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    Rot13 r;
    r.resize(400, 400);
    a.setMainWidget(&r);
    r.setCaption("Qt Example - ROT13");
    r.show();
    return a.exec();
}