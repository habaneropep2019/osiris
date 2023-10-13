/****************************************************************************
** $Id: qt/examples/life/main.cpp   2.1.0   edited 2000-01-31 $
**
** Copyright (C) 1992-2000 Troll Tech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include "lifedlg.h"
#include <qapplication.h>


int main( int argc, char **argv )
{
    QApplication a( argc, argv );

    LifeDialog *life = new LifeDialog;
    a.setMainWidget( life );
    life->show();

    return a.exec();
}
