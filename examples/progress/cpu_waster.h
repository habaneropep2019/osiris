#pragma once

#include <qprogressdialog.h>
#include <qapplication.h>
#include <qmenubar.h>
#include <qpopupmenu.h>
#include <qpainter.h>
#include <stdlib.h>

class CPUWaster : public QWidget
{
    Q_OBJECT

    enum
    {
        first_draw_item = 1000,
        last_draw_item = 1006
    };

    int drawItemRects(int id);
    QString drawItemText(int id);

public:
    CPUWaster();

public slots:
    void doMenuItem(int id);
    void stopDrawing();
    void timerDriven();
    void loopDriven();
    void defaultLabel();
    void customLabel();
    void toggleMinimumDuration();

private:
    void timerEvent(QTimerEvent *);
    QProgressDialog *newProgressDialog(const char *label, int steps, bool modal);
    void enableDrawingItems(bool yes);
    void draw(int n);

    QMenuBar *menubar;
    QProgressDialog *pb;
    QPopupMenu *options;
    int td_id, ld_id;
    int dl_id, cl_id;
    int md_id;
    int rects;
    bool timer_driven;
    bool default_label;
    bool got_stop;
};