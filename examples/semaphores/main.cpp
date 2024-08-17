/****************************************************************************
** $Id: qt/examples/semaphores/main.cpp   2.3.2   edited 2001-07-19 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/
#include <qapplication.h>
#include "semaphores.h"

#if defined(QT_NO_THREAD)
# error Thread support not enabled.
#endif

extern QSemaphore *yellowSem;
extern QSemaphore *greenSem;

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	yellowSem = new QSemaphore(1);
	greenSem = new QSemaphore(1);

	SemaphoreExample se;
	app.setMainWidget(&se);
	se.show();

	int r = app.exec();

	delete yellowSem;
	delete greenSem;

	return r;
}
