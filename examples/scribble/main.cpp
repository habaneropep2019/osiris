/****************************************************************************
** $Id: main.cpp,v 1.1 1999/06/03 10:08:56 warwick Exp $
**
** Copyright ( C ) 1992-1999 Troll Tech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include "scribble.h"
#include <qapplication.h>


int main( int argc, char **argv )
{
    QApplication a( argc, argv );

    Scribble scribble;
    scribble.resize( 500, 350 );
    a.setMainWidget( &scribble );
    scribble.show();

    return a.exec();
}
