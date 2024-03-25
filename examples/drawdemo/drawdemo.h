//
// DrawView has installable draw routines, just add a function pointer
// and a text in the table above.
//

#ifndef DRAWVIEW_H
#define DRAWVIEW_H

#include <qwidget.h>
#include <qpainter.h>
#include <qprinter.h>
#include <qpushbutton.h>
#include <qradiobutton.h>
#include <qbuttongroup.h>
#include <qapplication.h>
#include <math.h>

class DrawView : public QWidget
{
    Q_OBJECT
public:
    DrawView();
    ~DrawView();
public slots:
    void updateIt(int);
    void printIt();

protected:
    void drawIt(QPainter *);
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);

private:
    QPrinter *printer;
    QButtonGroup *bgroup;
    QPushButton *print;
    int drawindex;
    int maxindex;
};

#endif