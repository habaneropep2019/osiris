/****************************************************************************
** $Id: main.cpp,v 1.2 1999/06/03 01:44:18 warwick Exp $
**
** Copyright (C) 1992-1999 Troll Tech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include <qapplication.h>
#include <qfileinfo.h>
#include <qdir.h>
#include "dirview.h"

int main( int argc, char ** argv ) 
{
    QApplication a( argc, argv );

    DirectoryView mw;

    mw.addColumn( "Name" );
    mw.addColumn( "Type" );
    mw.setTreeStepSize( 20 );
    
    const QFileInfoList* roots = QDir::drives();
    QListIterator<QFileInfo> i(*roots);
    QFileInfo* fi;
    while ( (fi = *i) ) {
	++i;
	Directory * root = new Directory( &mw, fi->filePath() );
	if ( roots->count() <= 1 )
	    root->setOpen( TRUE ); // be interesting
    }

    mw.resize( 400, 400 );
    mw.setCaption( "Directory Browser" );
    a.setMainWidget( &mw );
    mw.show();
    
    return a.exec();
}
