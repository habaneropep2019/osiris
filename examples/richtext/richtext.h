/****************************************************************************
** $Id: richtext.h,v 1.1 1999/06/03 10:08:56 warwick Exp $
**
** Copyright (C) 1992-1999 Troll Tech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#ifndef RICHTEXT_H
#define RICHTEXT_H

#include <qvbox.h>

class QTextView;
class QPushButton;

class MyRichText : public QVBox
{
    Q_OBJECT

public:
    MyRichText( QWidget *parent = 0, const char *name = 0 );

protected:
    QTextView *view;
    QPushButton *bClose, *bNext, *bPrev;
    int num;

protected slots:
    void prev();
    void next();

};

#endif
