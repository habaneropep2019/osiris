#pragma once

#include <qapplication.h>
#include <qlabel.h>
#include <qcolor.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qlineedit.h>
#include <qmultilineedit.h>
#include <qmenubar.h>
#include <qpopupmenu.h>

class ExampleWidget : public QWidget
{
      public:
	ExampleWidget(QWidget *parent = 0, const char *name = 0);
	~ExampleWidget();

      private:
};