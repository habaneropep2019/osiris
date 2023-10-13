/****************************************************************************
** $Id: main.cpp,v 1.1 1999/06/03 10:08:56 warwick Exp $
**
** Copyright (C) 1992-1999 Troll Tech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include "richtext.h"
#include <qapplication.h>

int main( int argc, char **argv )
{
    QApplication a( argc, argv );

    MyRichText richtext;
    richtext.resize( 450, 350 );
    richtext.setCaption( "Fortune" );
    a.setMainWidget( &richtext );
    richtext.show();

    return a.exec();
}
