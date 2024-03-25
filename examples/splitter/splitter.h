/****************************************************************************
** $Id: qt/examples/splitter/splitter.cpp   2.3.2   edited 2001-06-12 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#pragma once

#include <qapplication.h>
#include <qlabel.h>
#include <qsplitter.h>
#include <qmultilineedit.h>

#include <qpainter.h>

class Test : public QWidget
{
public:
    Test(QWidget *parent = 0, const char *name = 0, int f = 0);
    void paintEvent(QPaintEvent *e);

private:
};
