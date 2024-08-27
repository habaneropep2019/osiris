/****************************************************************************
** $Id: qt/examples/tetrix/qdragapp.h   2.3.2   edited 2001-01-26 $
**
** Copyright (C) 1992-2000 Trolltech AS.  All rights reserved.
**
** This file is part of an example program for Qt.  This example
** program may be used, distributed and modified without limitation.
**
*****************************************************************************/

#ifndef QDRAGAPP_H
#define QDRAGAPP_H

#include "qapplication.h"
#include "qtetrix.h"

class QDragger;
class DropWindow;

struct DropInfo {
	DropInfo()
	{
		w = 0;
	}
	~DropInfo()
	{
		delete w;
	}
	DropWindow *w;
	bool userOpened;
};

struct DraggedInfo {
	QWidget *w;
	QWidget *mother;
	QPoint pos;
};

class DropWindow : public QWidget
{
	Q_OBJECT
      public:
	void paintEvent(QPaintEvent *);
	void closeEvent(QCloseEvent *);

	QDragger *master;
};

class QDragger : public QObject
{
	Q_OBJECT
      public:
	QDragger();
	~QDragger();

	bool notify(QObject *, QEvent *); // event filter
	void closeDropWindow(DropWindow *);
      public slots:
	void openDropWindow();
	void killDropWindow();
	void killAllDropWindows();
	void sendChildHome();
	void sendAllChildrenHome();

      private:
	bool isParentToDragged(QWidget *);
	bool noWidgets(QWidget *);
	void killDropWindow(DropInfo *);
	void killAllDropWindows(bool);
	void sendChildHome(DraggedInfo *);
	void sendAllChildrenHome(QWidget *);
	QWidget *openDropWindow(const QRect &, bool);

	bool startGrab();
	void grabFinished();
	bool dragEvent(QWidget *, QMouseEvent *);
	bool killDropEvent(QMouseEvent *);
	bool sendChildEvent(QMouseEvent *);

	bool killingDrop;
	bool sendingChild;
	QWidget *clickedWidget;
	QWidget *hostWidget;
	QCursor cursor;

	QPopupMenu *menu;
	QPoint clickOffset;
	QColor dragBackground;
	QColor dragForeground;
	DraggedInfo dragInfo;
	QIntDict<DraggedInfo> draggedDict;
	QIntDict<DropInfo> dropDict;
};

class QDragApplication : public QApplication
{
	Q_OBJECT
      public:
	QDragApplication(int &argc, char **argv);
	virtual ~QDragApplication();

	virtual bool notify(QObject *, QEvent *); // event filter

      private:
	QDragger *dragger;
};

#endif // QDRAGAPP_H
