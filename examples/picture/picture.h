#pragma once

#include <qapplication.h>
#include <qpainter.h>
#include <qpicture.h>
#include <qpixmap.h>
#include <qwidget.h>
#include <qmessagebox.h>
#include <qfile.h>
#include <ctype.h>

class PictureDisplay : public QWidget // picture display widget
{
      public:
	PictureDisplay(const char *fileName);
	~PictureDisplay();

      protected:
	void paintEvent(QPaintEvent *);
	void keyPressEvent(QKeyEvent *);

      private:
	QPicture *pict;
	QString name;
};