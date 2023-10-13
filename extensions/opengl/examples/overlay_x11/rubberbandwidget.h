/****************************************************************************
** $Id: rubberbandwidget.h,v 1.1 1999/05/27 08:26:57 aavit Exp $
**
** Definition of a widget that draws a rubberband. Designed to be used 
** in an X11 overlay visual
**
** Copyright (C) 1999 by Troll Tech AS.  All rights reserved.
**
****************************************************************************/

#ifndef RUBBERBANDWIDGET_H
#define RUBBERBANDWIDGET_H

#include <qwidget.h>


class RubberbandWidget : public QWidget
{
public:
    RubberbandWidget( QColor transparentColor, QWidget *parent=0, 
		      const char *name=0, WFlags f=0 );

protected:
    void mousePressEvent( QMouseEvent* e );
    void mouseMoveEvent( QMouseEvent* e );
    void mouseReleaseEvent( QMouseEvent* e );

    QColor c;
    QPoint p1;
    QPoint p2;
    QPoint p3;
    bool on;
};

#endif
