/****************************************************************************
** $Id: main.cpp,v 1.1 1999/06/03 10:08:56 warwick Exp $
**
** Copyright (C) 1992-1999 Troll Tech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include "rangecontrols.h"
#include <qapplication.h>

int main( int argc, char **argv )
{
    QApplication a( argc, argv );

    RangeControls rangecontrols;
    rangecontrols.resize( 500, 300 );
    rangecontrols.setCaption( "Examples for Range Control Widgets" );
    a.setMainWidget( &rangecontrols );
    rangecontrols.show();

    return a.exec();
}
