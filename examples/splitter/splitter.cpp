/****************************************************************************
** $Id: qt/examples/splitter/splitter.cpp   2.3.2   edited 2001-06-12 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include "splitter.h"

Test::Test(QWidget *parent, const char *name, int f) : QWidget(parent, name, f)
{
}

void Test::paintEvent(QPaintEvent *e)
{
	QPainter p(this);
	p.setClipRect(e->rect());
	const int d = 1000; // large number
	int x1 = 0;
	int x2 = width() - 1;
	int y1 = 0;
	int y2 = height() - 1;

	int x = (x1 + x2) / 2;
	p.drawLine(x, y1, x + d, y1 + d);
	p.drawLine(x, y1, x - d, y1 + d);
	p.drawLine(x, y2, x + d, y2 - d);
	p.drawLine(x, y2, x - d, y2 - d);

	int y = (y1 + y2) / 2;
	p.drawLine(x1, y, x1 + d, y + d);
	p.drawLine(x1, y, x1 + d, y - d);
	p.drawLine(x2, y, x2 - d, y + d);
	p.drawLine(x2, y, x2 - d, y - d);
}
