/****************************************************************************
** $Id: main.cpp,v 1.1 1999/06/03 10:08:56 warwick Exp $
**
** Copyright (C) 1992-1999 Troll Tech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include <qapplication.h>
#include <qwindowsstyle.h>
#include "themes.h"

#include "metal.h"

int main( int argc, char ** argv )
{
    QApplication::setColorSpec( QApplication::CustomColor );
    QApplication::setStyle( new QWindowsStyle() );
    QApplication a( argc, argv );

    Themes themes;
    themes.setCaption( "Theme (QStyle) example" );
    themes.resize( 640, 400 );
    a.setMainWidget( &themes );
    themes.show();

    return a.exec();
}
