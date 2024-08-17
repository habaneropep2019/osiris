#pragma once

#include <qiconview.h>
#include <qapplication.h>
#include <qdragobject.h>
#include <qpixmap.h>
#include <qiconset.h>

#include <qmime.h>
#include <stdio.h>

class ListenDND : public QObject
{
	Q_OBJECT

      public:
	ListenDND(QWidget *w);

      public slots:
	void dropped(QDropEvent *mime);
	void moved();

      protected:
	QWidget *view;
};