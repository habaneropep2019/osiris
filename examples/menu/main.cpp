#include "menu.h"

int main(int argc, char **argv)
{
	QApplication a(argc, argv);
	MenuExample m;

	a.setMainWidget(&m);
	m.setCaption("Qt Examples - Menus");
	m.show();
	return a.exec();
}
