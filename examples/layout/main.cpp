/****************************************************************************
** $Id: qt/examples/layout/layout.cpp   2.3.2   edited 2001-06-12 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include "example_widget.h"

int main(int argc, char **argv)
{
	QApplication a(argc, argv);

	ExampleWidget f;
	a.setMainWidget(&f);
	f.setCaption("Qt Example - Caption");
	f.show();

	return a.exec();
}
