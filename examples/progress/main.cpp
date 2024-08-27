#include "cpu_waster.h"

int main(int argc, char **argv)
{
	QApplication a(argc, argv);

	int wincount = argc > 1 ? atoi(argv[1]) : 1;

	for (int i = 0; i < wincount; i++) {
		CPUWaster *cpuw = new CPUWaster;
		if (i == 0)
			a.setMainWidget(cpuw);
		cpuw->setCaption("Qt Example - Progress");
		cpuw->show();
	}
	return a.exec();
}