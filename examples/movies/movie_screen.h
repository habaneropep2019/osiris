#pragma once

#include <qapplication.h>
#include <qfiledialog.h>
#include <qlabel.h>
#include <qpainter.h>
#include <qmessagebox.h>
#include <qmovie.h>

class MovieScreen : public QFrame
{
    Q_OBJECT
    QMovie movie;
    QString filename;

public:
    MovieScreen(const char *fname, QMovie m, QWidget *p = 0, const char *name = 0, WFlags f = 0);

protected:
    // Draw the contents of the QFrame - the movie and on-screen-display
    void drawContents(QPainter *p);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void movieUpdated(const QRect &area);
    void movieResized(const QSize &size);
    void movieStatus(int status);
};
