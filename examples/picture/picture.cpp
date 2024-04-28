/****************************************************************************
** $Id: qt/examples/picture/picture.cpp   2.3.2   edited 2001-10-18 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include "picture.h"

PictureDisplay::PictureDisplay(const char *fileName)
{
    pict = new QPicture;
    name = fileName;
    if (!pict->load(fileName))
    { // cannot load picture
        delete pict;
        pict = 0;
        name.sprintf("Not able to load picture: %s", fileName);
    }
}

PictureDisplay::~PictureDisplay()
{
    delete pict;
}

void PictureDisplay::paintEvent(QPaintEvent *)
{
    QPainter paint(this); // paint widget
    if (pict)
        paint.drawPicture(*pict); // draw picture
    else
        paint.drawText(rect(), AlignCenter, name);
}

void PictureDisplay::keyPressEvent(QKeyEvent *k)
{
    switch (tolower(k->ascii()))
    {
    case 'r': // reload
        pict->load(name);
        update();
        break;
    case 'q': // quit
        QApplication::exit();
        break;
    }
}
