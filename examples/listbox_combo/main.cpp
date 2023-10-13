/****************************************************************************
** $Id: main.cpp,v 1.1 1999/06/03 10:08:55 warwick Exp $
**
** Copyright (C) 1992-1999 Troll Tech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include "listbox_combo.h"
#include <qapplication.h>

int main( int argc, char **argv )
{
    QApplication a( argc, argv );

    ListBoxCombo listboxcombo;
    listboxcombo.resize( 400, 270 );
    listboxcombo.setCaption( "Examples for Listboxes and Comboboxes" );
    a.setMainWidget( &listboxcombo );
    listboxcombo.show();

    return a.exec();
}
