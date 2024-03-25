/****************************************************************************
** $Id: qt/examples/progress/progress.cpp   2.3.2   edited 2001-06-12 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#pragma once

#include <qprogressdialog.h>
#include <qapplication.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qpainter.h>
#include <stdlib.h>

class AnimatedThingy : public QLabel
{
public:
    AnimatedThingy(QWidget *parent, const QString &s);

    void show();
    void hide();
    QSize sizeHint() const;

protected:
    void timerEvent(QTimerEvent *);
    void paintEvent(QPaintEvent *event);

private:
    void inc(int &x, int &dx, int b);

    enum
    {
        nqix = 10
    };
    int ox[2][nqix];
    int oy[2][nqix];
    int x0, y0, x1, y1;
    int dx0, dy0, dx1, dy1;
    QString label;
    int step;
};
