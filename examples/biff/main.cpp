/****************************************************************************
** $Id: main.cpp,v 1.2 1999/06/03 01:43:59 warwick Exp $
**
** Copyright (C) 1992-1999 Troll Tech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include <qapplication.h>
#include "biff.h"


int main( int argc, char ** argv )
{
    QApplication a( argc, argv );
    Biff b;
    a.setMainWidget( &b );
    b.show();
    return a.exec();
}
