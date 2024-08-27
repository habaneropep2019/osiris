/****************************************************************************
** $Id: qt/examples/progress/progress.cpp   2.3.2   edited 2001-06-12 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include "progress.h"

AnimatedThingy::AnimatedThingy(QWidget *parent, const QString &s)
	: QLabel(parent), label(s), step(0)
{
	label += "\n... and wasting CPU\nwith this animation!\n";

	for (int i = 0; i < nqix; i++)
		ox[0][i] = oy[0][i] = ox[1][i] = oy[1][i] = 0;
	x0 = y0 = x1 = y1 = 0;
	dx0 = rand() % 8 + 2;
	dy0 = rand() % 8 + 2;
	dx1 = rand() % 8 + 2;
	dy1 = rand() % 8 + 2;
}

void AnimatedThingy::show()
{
	if (!isVisible())
		startTimer(100);
	QWidget::show();
}

void AnimatedThingy::hide()
{
	QWidget::hide();
	killTimers();
}

QSize AnimatedThingy::sizeHint() const
{
	return QSize(120, 100);
}

void AnimatedThingy::timerEvent(QTimerEvent *)
{
	QPainter p(this);
	QPen pn = p.pen();
	pn.setWidth(2);
	pn.setColor(backgroundColor());
	p.setPen(pn);

	step = (step + 1) % nqix;

	p.drawLine(ox[0][step], oy[0][step], ox[1][step], oy[1][step]);

	inc(x0, dx0, width());
	inc(y0, dy0, height());
	inc(x1, dx1, width());
	inc(y1, dy1, height());
	ox[0][step] = x0;
	oy[0][step] = y0;
	ox[1][step] = x1;
	oy[1][step] = y1;

	QColor c;
	c.setHsv((step * 255) / nqix, 255, 255); // rainbow effect
	pn.setColor(c);
	p.setPen(pn);
	p.drawLine(ox[0][step], oy[0][step], ox[1][step], oy[1][step]);
	p.setPen(colorGroup().text());
	p.drawText(rect(), AlignCenter, label);
}

void AnimatedThingy::paintEvent(QPaintEvent *event)
{
	QPainter p(this);
	QPen pn = p.pen();
	pn.setWidth(2);
	p.setPen(pn);
	p.setClipRect(event->rect());
	for (int i = 0; i < nqix; i++) {
		QColor c;
		c.setHsv((i * 255) / nqix, 255, 255); // rainbow effect
		pn.setColor(c);
		p.setPen(pn);
		p.drawLine(ox[0][i], oy[0][i], ox[1][i], oy[1][i]);
	}
	p.setPen(colorGroup().text());
	p.drawText(rect(), AlignCenter, label);
}

void AnimatedThingy::inc(int &x, int &dx, int b)
{
	x += dx;
	if (x < 0) {
		x = 0;
		dx = rand() % 8 + 2;
	} else if (x >= b) {
		x = b - 1;
		dx = -(rand() % 8 + 2);
	}
}