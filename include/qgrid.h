/****************************************************************************
** $Id: qgrid.h,v 1.13 1999/05/25 15:36:28 agulbra Exp $
**
** Copyright (C) 1992-1999 Troll Tech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#ifndef QGRID_H
#define QGRID_H

#ifndef QT_H
#include "qframe.h"
#endif // QT_H

class QGridLayout;

class Q_EXPORT QGrid : public QFrame
{
    Q_OBJECT
public:
    enum Direction { Horizontal, Vertical };
    QGrid( int n, QWidget *parent=0, const char *name=0, WFlags f=0 );
    QGrid( int n, Direction, QWidget *parent=0, const char *name=0,
	   WFlags f=0 );
    void setSpacing( int );

protected:
    void frameChanged();

private:
    QGridLayout *lay;
};

#endif //QGRID_H
