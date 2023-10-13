/****************************************************************************
** $Id: main.cpp,v 1.2 1999/06/03 01:46:07 warwick Exp $
**
** Copyright (C) 1992-1999 Troll Tech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include <qapplication.h>
#include "vw.h"

int main( int argc, char ** argv ) {
    QApplication a( argc, argv );
    VW mw;
    a.setMainWidget( &mw );
    mw.setCaption( "" );
    mw.show();
    return a.exec();
}
