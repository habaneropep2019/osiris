/****************************************************************************
** $Id: qt/examples/rot13/rot13.h   2.1.0   edited 2000-01-31 $
**
** Definition of something or other
**
** Created : 979899
**
** Copyright (C) 1997 by Troll Tech AS.  All rights reserved.
**
****************************************************************************/

#ifndef ROT13_H
#define ROT13_H

#include <qwidget.h>

class QMultiLineEdit;

class Rot13: public QWidget {
    Q_OBJECT
public:
    Rot13();

    QString rot13( const QString & ) const;

private slots:
    void changeLeft();
    void changeRight();

private:
    QMultiLineEdit * left, * right;
};

#endif
