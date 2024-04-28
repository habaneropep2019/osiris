
#include "movie_screen.h"

MovieScreen::MovieScreen(const char *fname, QMovie m, QWidget *p, const char *name, WFlags f) : QFrame(p, name, f)
{
    setCaption(fname);
    filename = fname;
    movie = m;

    // Set a frame around the movie.
    setFrameStyle(QFrame::WinPanel | QFrame::Sunken);

    // No background needed, since we draw on the whole widget.
    movie.setBackgroundColor(backgroundColor());
    setBackgroundMode(NoBackground);

    // Get the movie to tell use when interesting things happen.
    movie.connectUpdate(this, SLOT(movieUpdated(const QRect &)));
    movie.connectResize(this, SLOT(movieResized(const QSize &)));
    movie.connectStatus(this, SLOT(movieStatus(int)));
}

void MovieScreen::drawContents(QPainter *p)
{
    // Get the current movie frame.
    QPixmap pm = movie.framePixmap();

    // Get the area we have to draw in.
    QRect r = contentsRect();

    // Only rescale is we need to - it can take CPU!
    if (r.size() != pm.size())
    {
        QWMatrix m;
        m.scale((double)r.width() / pm.width(),
                (double)r.height() / pm.height());
        pm = pm.xForm(m);
    }

    // Draw the [possibly scaled] frame.  movieUpdated() below calls
    // repaint with only the changed area, so clipping will ensure we
    // only do the minimum amount of rendering.
    //
    p->drawPixmap(r.x(), r.y(), pm);

    // The on-screen display

    const char *message = 0;

    if (movie.paused())
    {
        message = "PAUSED";
    }
    else if (movie.finished())
    {
        message = "THE END";
    }
    else if (movie.steps() > 0)
    {
        message = "FF >>";
    }

    if (message)
    {
        // Find a good font size...
        p->setFont(QFont("Helvetica", 24));

        QFontMetrics fm = p->fontMetrics();
        if (fm.width(message) > r.width() - 10)
            p->setFont(QFont("Helvetica", 18));

        fm = p->fontMetrics();
        if (fm.width(message) > r.width() - 10)
            p->setFont(QFont("Helvetica", 14));

        fm = p->fontMetrics();
        if (fm.width(message) > r.width() - 10)
            p->setFont(QFont("Helvetica", 12));

        fm = p->fontMetrics();
        if (fm.width(message) > r.width() - 10)
            p->setFont(QFont("Helvetica", 10));

        // "Shadow" effect.
        p->setPen(black);
        p->drawText(1, 1, width() - 1, height() - 1, AlignCenter, message);
        p->setPen(white);
        p->drawText(0, 0, width() - 1, height() - 1, AlignCenter, message);
    }
}

void MovieScreen::mouseReleaseEvent(QMouseEvent *event)
{
    // Do what the Help says...

    if (event->state() & ShiftButton)
    {
        movie.restart();
    }
    else if (!movie.paused())
    {
        movie.pause();
    }
    else
    {
        if (event->button() & LeftButton)
            movie.step((event->state() & ControlButton) ? 10 : 1);
        else if (event->button() & (MidButton | RightButton))
            movie.unpause();
    }

    repaint(); // To hide/show "PAUSED".
}

void MovieScreen::movieUpdated(const QRect &area)
{
    if (!isVisible())
        show();

    // The given area of the movie has changed.

    QRect r = contentsRect();

    if (r.size() != movie.framePixmap().size())
    {
        // Need to scale - redraw whole frame.
        repaint(r);
    }
    else
    {
        // Only redraw the changed area of the frame
        repaint(area.x() + r.x(), area.y() + r.x(),
                area.width(), area.height());
    }
}

void MovieScreen::movieResized(const QSize &size)
{
    // The movie changed size, probably from its initial zero size.

    int fw = frameWidth();
    resize(size.width() + fw * 2, size.height() + fw * 2);
    qApp->setMainWidget(this); // Just geometry, etc.
    qApp->setMainWidget(0);    // Not Close==Quit
}

void MovieScreen::movieStatus(int status)
{
    // The movie has sent us a status message.

    if (status < 0)
    {
        QString msg;
        msg.sprintf("Could not play movie \"%s\"", (const char *)filename);
        QMessageBox::message("Error", msg);
    }
    else if (status == QMovie::Paused || status == QMovie::EndOfMovie)
    {
        repaint(); // Ensure status text is displayed
    }
}
