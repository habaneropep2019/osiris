#include "httpd.h"
#include "httpinfo.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	HttpInfo info;
	app.setMainWidget(&info);
	info.setCaption("Qt Example - httpd");
	info.show();
	return app.exec();
}
