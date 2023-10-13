/****************************************************************************
** $Id: qt/examples/validator/main.cpp   2.1.0   edited 2000-01-31 $
**
** Copyright (C) 1992-2000 Troll Tech AS.  All rights reserved.
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
