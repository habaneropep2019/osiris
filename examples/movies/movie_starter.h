#pragma once

#include <qfiledialog.h>

class MovieStarter : public QFileDialog
{
	Q_OBJECT
      public:
	MovieStarter(const char *dir);

      public slots:
	void startMovie(const QString &filename);

	// QDialog's method - normally closes the file dialog.
	// We want it left open, and we want Cancel to quit everything.
	void done(int r);
};