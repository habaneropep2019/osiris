#pragma once

#include <qapplication.h>
#include <qdialog.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qcheckbox.h>
#include <qradiobutton.h>
#include <qbuttongroup.h>
#include <qlcdnumber.h>
#include <qslider.h>
#include <qmenubar.h>
#include <qfontdialog.h>
#include <qlayout.h>
#include <qvbox.h>
#include <qwidgetstack.h>

#include <qpainter.h>
#include <qpixmap.h>
#include <qpicture.h>

#include <stdlib.h>

class ModeNames
{
      public:
	enum Mode { Text, Image, Picture };
};

class XFormControl : public QVBox, public ModeNames
{
	Q_OBJECT
      public:
	XFormControl(const QFont &initialFont, QWidget *parent = 0,
		     const char *name = 0);
	~XFormControl()
	{
	}

	QWMatrix matrix();

      signals:
	void newMatrix(QWMatrix);
	void newText(const QString &);
	void newFont(const QFont &);
	void newMode(int);
      private slots:
	void newMtx();
	void newTxt(const QString &);
	void selectFont();
	void fontSelected(const QFont &);
	void changeMode(int);
	void timerEvent(QTimerEvent *);

      private:
	Mode mode;
	QSlider *rotS; // Rotation angle scroll bar
	QSlider *shearS; // Shear value scroll bar
	QSlider *magS; // Magnification value scroll bar
	QLCDNumber *rotLCD; // Rotation angle LCD display
	QLCDNumber *shearLCD; // Shear value LCD display
	QLCDNumber *magLCD; // Magnification value LCD display
	QCheckBox *mirror; // Checkbox for mirror image on/of
	QWidgetStack *optionals;
	QLineEdit *textEd; // Inp[ut field for xForm text
	QPushButton *fpb; // Select font push button
	QRadioButton *rb_txt; // Radio button for text
	QRadioButton *rb_img; // Radio button for image
	QRadioButton *rb_pic; // Radio button for picture
	QFont currentFont;
};

/*
  ShowXForm displays a text or a pixmap (QPixmap) using a coordinate
  transformation matrix (QWMatrix)
*/

class ShowXForm : public QWidget, public ModeNames
{
	Q_OBJECT
      public:
	ShowXForm(const QFont &f, QWidget *parent = 0, const char *name = 0);
	~ShowXForm()
	{
	}
	void showIt(); // (Re)displays text or pixmap

	Mode mode() const
	{
		return m;
	}
      public slots:
	void setText(const QString &);
	void setMatrix(QWMatrix);
	void setFont(const QFont &f);
	void setPixmap(QPixmap);
	void setPicture(const QPicture &);
	void setMode(int);

      private:
	QSizePolicy sizePolicy() const;
	QSize sizeHint() const;
	void paintEvent(QPaintEvent *);
	void resizeEvent(QResizeEvent *);
	QWMatrix mtx; // coordinate transform matrix
	QString text; // text to be displayed
	QPixmap pix; // pixmap to be displayed
	QPicture picture; // text to be displayed
	QRect eraseRect; // covers last displayed text/pixmap
	Mode m;
};

/*
    Grand unifying widget, putting ShowXForm and XFormControl
    together.
*/

class XFormCenter : public QHBox, public ModeNames
{
	Q_OBJECT
      public:
	XFormCenter(QWidget *parent = 0, const char *name = 0);
      public slots:
	void setFont(const QFont &f)
	{
		sx->setFont(f);
	}
	void newMode(int);

      private:
	ShowXForm *sx;
	XFormControl *xc;
};