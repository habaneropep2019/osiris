/****************************************************************************
** $Id: qt/examples/iconview/main.cpp   2.3.2   edited 2001-06-12 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include <stdio.h>

#include "listendnd.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    QIconView qiconview;
    qiconview.setSelectionMode(QIconView::Extended);

    for (unsigned int i = 0; i < 3000; i++)
    {
        QIconViewItem *item = new QIconViewItem(&qiconview, QString("Item %1").arg(i + 1));
        item->setRenameEnabled(TRUE);
    }

    qiconview.setCaption("Qt Example - Iconview");

    ListenDND listen_dnd(&qiconview);
    QObject::connect(&qiconview, SIGNAL(dropped(QDropEvent *, const QValueList<QIconDragItem> &)),
                     &listen_dnd, SLOT(dropped(QDropEvent *)));
    QObject::connect(&qiconview, SIGNAL(moved()), &listen_dnd, SLOT(moved()));

    a.setMainWidget(&qiconview);
    qiconview.show();
    qiconview.resize(qiconview.sizeHint());

    return a.exec();
}
