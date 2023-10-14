/****************************************************************************
** $Id: qt/extensions/opengl/examples/overlay_x11/gearwidget.h   2.1.1   edited 2000-01-31 $
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
