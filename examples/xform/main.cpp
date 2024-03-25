#include "xform.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    XFormCenter *xfc = new XFormCenter;

    a.setMainWidget(xfc);
    xfc->setCaption("Qt Example - XForm");
    xfc->show();
    return a.exec();
}