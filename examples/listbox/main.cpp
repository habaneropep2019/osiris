/****************************************************************************
** $Id: main.cpp,v 1.1 1999/06/16 20:42:22 agulbra Exp $
**
** Copyright (C) 1992-1999 Troll Tech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include "listbox.h"
#include <qapplication.h>

int main( int argc, char **argv )
{
    QApplication a( argc, argv );

    ListBoxDemo t;
    t.setCaption( "List Box Configuration Example" );
    a.setMainWidget( &t );
    t.show();

    return a.exec();
}
