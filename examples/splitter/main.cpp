#include "splitter.h"

int main(int argc, char **argv)
{
	QApplication a(argc, argv);

	QSplitter *s1 = new QSplitter(QSplitter::Vertical, 0, "main");

	QSplitter *s2 = new QSplitter(QSplitter::Horizontal, s1, "top");

	Test *t1 = new Test(s2);
	t1->setBackgroundColor(Qt::blue.light(180));
	t1->setMinimumSize(50, 0);

	Test *t2 = new Test(s2);
	t2->setBackgroundColor(Qt::green.light(180));
	s2->setResizeMode(t2, QSplitter::KeepSize);
	s2->moveToFirst(t2);

	QSplitter *s3 = new QSplitter(QSplitter::Horizontal, s1, "bottom");

	Test *t3 = new Test(s3);
	t3->setBackgroundColor(Qt::red);
	Test *t4 = new Test(s3);
	t4->setBackgroundColor(Qt::white);

	Test *t5 = new Test(s3);
	t5->setMaximumHeight(250);
	t5->setMinimumSize(80, 50);
	t5->setBackgroundColor(Qt::yellow);

#ifdef _WS_QWS_
	// Qt/Embedded XOR drawing not yet implemented.
	s1->setOpaqueResize(TRUE);
#endif
	s2->setOpaqueResize(TRUE);
	s3->setOpaqueResize(TRUE);

	a.setMainWidget(s1);
	s1->setCaption("Qt Example - Splitters");
	s1->show();
	int result = a.exec();
	delete s1;
	return result;
}