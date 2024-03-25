#include <qapplication.h>

#include "scrollview.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    ScrollViewExample ve1(1, 0, "ve1");
    ScrollViewExample ve2(2, 0, "ve2");
    ScrollViewExample ve3(3, 0, "ve3");
    ve1.setCaption("Qt Example - Scrollviews");
    ve1.show();
    ve2.setCaption("Qt Example - Scrollviews");
    ve2.show();
    ve3.setCaption("Qt Example - Scrollviews");
    ve3.show();

    QObject::connect(qApp, SIGNAL(lastWindowClosed()), qApp, SLOT(quit()));

    return a.exec();
}