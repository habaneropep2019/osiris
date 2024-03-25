/****************************************************************************
** $Id: qt/examples/scrollview/scrollview.cpp   2.3.2   edited 2001-06-12 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#pragma once

#include <qscrollview.h>
#include <qapplication.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qpushbutton.h>
#include <qpainter.h>
#include <qpixmap.h>
#include <qmessagebox.h>
#include <qlayout.h>
#include <qlabel.h>
#include <qmultilineedit.h>
#include <qsizegrip.h>
#include <stdlib.h>

static const int style_id = 0x1000;
static const int lw_id = 0x2000;
static const int mlw_id = 0x4000;
static const int mw_id = 0x8000;
static const int max_lw = 16;
static const int max_mlw = 5;
static const int max_mw = 10;

class BigShrinker : public QFrame
{
    Q_OBJECT
public:
    BigShrinker(QWidget *parent);
    void timerEvent(QTimerEvent *);
    void mouseReleaseEvent(QMouseEvent *e);

signals:
    void clicked(int, int);
};

class BigMatrix : public QScrollView
{
    QMultiLineEdit *dragging;

public:
    BigMatrix(QWidget *parent);
    void viewportMousePressEvent(QMouseEvent *e);
    void viewportMouseReleaseEvent(QMouseEvent *);

    void viewportMouseMoveEvent(QMouseEvent *e);

protected:
    void drawContents(QPainter *p, int cx, int cy, int cw, int ch);

private:
    QPixmap bg;
};

class ScrollViewExample : public QWidget
{
    Q_OBJECT

public:
    ScrollViewExample(int technique, QWidget *parent = 0, const char *name = 0);

private slots:
    void doVPMenuItem(int id);
    void setVPMenuItems();
    void doFMenuItem(int id);
    void setFMenuItems();

private:
    QScrollView *vp;
    QPopupMenu *vp_options;
    QPopupMenu *f_options;
    QPopupMenu *lw_options;
    QPopupMenu *mlw_options;
    QPopupMenu *mw_options;
    QSizeGrip *corner;

    int vauto_id, vaoff_id, vaon_id,
        hauto_id, haoff_id, haon_id,
        corn_id;

    int f_laststyle;
};
