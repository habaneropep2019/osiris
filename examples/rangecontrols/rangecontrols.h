/****************************************************************************
** $Id: rangecontrols.h,v 1.1 1999/06/03 10:08:56 warwick Exp $
**
** Copyright (C) 1992-1999 Troll Tech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#ifndef RANGECONTROLS_H
#define RANGECONTROLS_H

#include <qvbox.h>

class RangeControls : public QVBox
{
    Q_OBJECT

public:
    RangeControls( QWidget *parent = 0, const char *name = 0 );

};

#endif
