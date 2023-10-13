/****************************************************************************
** $Id: main.cpp,v 1.2 1999/06/03 01:44:50 warwick Exp $
**
** Copyright (C) 1992-1999 Troll Tech AS.  All rights reserved.
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
