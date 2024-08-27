#pragma once

#include <qapplication.h>
#include <qwidget.h>
#include <qpushbutton.h>
#include <qmultilineedit.h>
#include <qthread.h>
#include <qlayout.h>
#include <qmessagebox.h>
#include <qlabel.h>

class YellowThread : public QThread
{
      public:
	YellowThread(QWidget *o) : receiver(o)
	{
		;
	}

	void run();

      private:
	QWidget *receiver;
};

class GreenThread : public QThread
{
      public:
	GreenThread(QWidget *o) : receiver(o)
	{
		;
	}

	void run();

      private:
	QWidget *receiver;
};

class SemaphoreExample : public QWidget
{
	Q_OBJECT
      public:
	SemaphoreExample();

	void customEvent(QCustomEvent *);

      public slots:
	void startExample();

      protected:
      private:
	QMultiLineEdit *mlineedit;
	QPushButton *button;
	QLabel *label;

	YellowThread yellowThread;
	GreenThread greenThread;
};