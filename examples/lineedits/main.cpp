/****************************************************************************
** $Id: qt/examples/lineedits/main.cpp   2.2.4   edited 2000-08-31 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include "lineedits.h"
#include <qapplication.h>

int main( int argc, char **argv )
{
    QApplication a( argc, argv );

    LineEdits lineedits;
    lineedits.setCaption( "LineEdit Examples" );
    a.setMainWidget( &lineedits );
    lineedits.show();

    return a.exec();
}
