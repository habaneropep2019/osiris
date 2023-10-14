/****************************************************************************
** $Id: qt/extensions/opengl/examples/box/glbox.h   2.1.1   edited 2000-01-31 $
**
** Definition of GLBox
** This is a simple QGLWidget displaying an openGL wireframe box
**
****************************************************************************/

#ifndef GLBOX_H
#define GLBOX_H

#include <qgl.h>


class GLBox : public QGLWidget
{
    Q_OBJECT

public:

    GLBox( QWidget* parent, const char* name );
    ~GLBox();

public slots:

    void		setXRotation( int degrees );
    void		setYRotation( int degrees );
    void		setZRotation( int degrees );

protected:

    void		initializeGL();
    void		paintGL();
    void		resizeGL( int w, int h );

    virtual GLuint 	makeObject();

private:

    GLuint object;
    GLfloat xRot, yRot, zRot, scale;

};


#endif // GLBOX_H
