#include "popup.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    Frame frame;
    frame.setCaption("Qt Example - Custom Popups");
    a.setMainWidget(&frame);
    frame.show();
    return a.exec();
}
