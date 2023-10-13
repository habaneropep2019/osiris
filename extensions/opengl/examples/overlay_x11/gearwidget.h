/****************************************************************************
** $Id: gearwidget.h,v 1.1 1999/05/27 08:26:57 aavit Exp $
**
** Definition of a simple Qt OpenGL widget
**
** Copyright (C) 1999 by Troll Tech AS.  All rights reserved.
**
****************************************************************************/

#ifndef GEAR_H
#define GEAR_H

#include <qgl.h>

class GearWidget : public QGLWidget
{
public:
    GearWidget( QWidget *parent=0, const char *name=0 );

protected:
    void initializeGL();
    void resizeGL( int, int );
    void paintGL();
};


#endif
