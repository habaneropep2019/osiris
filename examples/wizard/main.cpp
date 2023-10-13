/****************************************************************************
** $Id: main.cpp,v 1.2 1999/06/11 03:47:50 warwick Exp $
**
** Copyright (C) 1992-1999 Troll Tech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include "wizard.h"
#include <qapplication.h>

int main(int argc,char **argv)
{
    QApplication a(argc,argv);

    Wizard wizard;
    wizard.setCaption("Wizard Example");
    return wizard.exec();
}
