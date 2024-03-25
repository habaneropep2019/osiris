/****************************************************************************
** $Id: qt/examples/movies/main.cpp   2.3.2   edited 2001-06-12 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#include "movie_screen.h"
#include "movie_starter.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    if (argc > 1)
    {
        // Commandline mode - show movies given on the command line
        //
        for (int arg = 1; arg < argc; arg++)
            (void)new MovieScreen(argv[arg], QMovie(argv[arg]), 0, 0,
                                  Qt::WDestructiveClose);
        QObject::connect(qApp, SIGNAL(lastWindowClosed()), qApp, SLOT(quit()));
    }
    else
    {
        // "GUI" mode - open a chooser for movies
        //
        MovieStarter *fd = new MovieStarter(".");
        fd->show();

        // Some help text to explain the `hidden' features.
        QLabel *help = new QLabel(
            "Choose some movies.\n\n"
            "Shift-click to Restart.\n"
            "Click to Pause,\n"
            "then left-click to Step,\n"
            "control-left-click to Step 10,\n"
            "right-click to Unpause\n\n"
            "Windows may be resized to enlarge movie.",
            0);
        help->setCaption("Qt Examples - Movies");
        help->setIndent(10);
        help->show();
    }

    // Go!
    return a.exec();
}
