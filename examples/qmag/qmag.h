#pragma once

#include <qcombobox.h>
#include <qpushbutton.h>
#include <qpixmap.h>
#include <qimage.h>
#include <qlabel.h>
#include <qfiledialog.h>
#include <qregexp.h>

#include <qapplication.h>
#include <qpainter.h>
#include <qwmatrix.h>

class MagWidget : public QWidget
{
	Q_OBJECT
      public:
	MagWidget(QWidget *parent = 0, const char *name = 0);

      public slots:
	void setZoom(int);
	void setRefresh(int);
	void save();
	void multiSave();

      protected:
	void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *);
	void mouseReleaseEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
	void focusOutEvent(QFocusEvent *);
	void timerEvent(QTimerEvent *);
	void resizeEvent(QResizeEvent *);

      private:
	void grabAround(QPoint pos);
	void grab();

	QComboBox *zoom;
	QComboBox *refresh;
	QPushButton *saveButton;
	QPushButton *multiSaveButton;
	QPushButton *quitButton;
	QPixmap pm; // pixmap, magnified
	QPixmap p; // pixmap
	QImage image; // image of pixmap (for RGB)
	QLabel *rgb;
	int yoffset; // pixels in addition to the actual picture
	int z; // magnification factor
	int r; // autorefresh rate (index into refreshrates)
	bool grabbing; // TRUE if qmag is currently grabbing
	int grabx, graby;
	QString multifn; // filename for multisave
};