#include "movie_starter.h"
#include "movie_screen.h"

MovieStarter::MovieStarter(const char *dir) : QFileDialog(dir, "*.gif")
{
    // behave as in getOpenFilename
    setMode(ExistingFile);
    // When a file is selected, show it as a movie.
    connect(this, SIGNAL(fileSelected(const QString &)),
            this, SLOT(startMovie(const QString &)));
}

void MovieStarter::startMovie(const QString &filename)
{
    if (filename) // Start a new movie - have it delete when closed.
        (void)new MovieScreen(filename, QMovie(filename), 0, 0, WDestructiveClose);
}

void MovieStarter::done(int r)
{
    if (r != Accepted)
        qApp->quit(); // end on Cancel
    setResult(r);

    // And don't hide.
}
