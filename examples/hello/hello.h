/****************************************************************************
** $Id: hello.h,v 1.2 1999/06/03 01:44:39 warwick Exp $
**
** Copyright (C) 1992-1999 Troll Tech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#ifndef HELLO_H
#define HELLO_H

#include <qwidget.h>


class Hello : public QWidget
{
    Q_OBJECT
public:
    Hello( const char *text, QWidget *parent=0, const char *name=0 );
signals:
    void clicked();
protected:
    void mouseReleaseEvent( QMouseEvent * );
    void paintEvent( QPaintEvent * );
private slots:
    void animate();
private:
    QString t;
    int     b;
};

#endif
