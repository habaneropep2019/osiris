#include "cpu_waster.h"
#include "progress.h"

int CPUWaster::drawItemRects(int id)
{
    int n = id - first_draw_item;
    int r = 100;
    while (n--)
        r *= (n % 3 ? 5 : 4);
    return r;
}

QString CPUWaster::drawItemText(int id)
{
    QString str;
    str.sprintf("%d Rectangles", drawItemRects(id));
    return str;
}

CPUWaster::CPUWaster() : pb(0)
{
    menubar = new QMenuBar(this, "menu");
    CHECK_PTR(menubar);

    QPopupMenu *file = new QPopupMenu();
    CHECK_PTR(file);
    menubar->insertItem("&File", file);
    for (int i = first_draw_item; i <= last_draw_item; i++)
        file->insertItem(drawItemText(i), i);
    connect(menubar, SIGNAL(activated(int)), this, SLOT(doMenuItem(int)));
    file->insertSeparator();
    file->insertItem("Quit", qApp, SLOT(quit()));

    options = new QPopupMenu();
    CHECK_PTR(options);
    menubar->insertItem("&Options", options);
    td_id = options->insertItem("Timer driven", this, SLOT(timerDriven()));
    ld_id = options->insertItem("Loop driven", this, SLOT(loopDriven()));
    options->insertSeparator();
    dl_id = options->insertItem("Default label", this, SLOT(defaultLabel()));
    cl_id = options->insertItem("Custom label", this, SLOT(customLabel()));
    options->insertSeparator();
    md_id = options->insertItem("No minimum duration", this, SLOT(toggleMinimumDuration()));
    options->setCheckable(TRUE);
    loopDriven();
    defaultLabel();

    setFixedSize(400, 300);

    setBackgroundColor(black);
}

void CPUWaster::doMenuItem(int id)
{
    if (id >= first_draw_item && id <= last_draw_item)
        draw(drawItemRects(id));
}

void CPUWaster::stopDrawing() { got_stop = TRUE; }

void CPUWaster::timerDriven()
{
    timer_driven = TRUE;
    options->setItemChecked(td_id, TRUE);
    options->setItemChecked(ld_id, FALSE);
}

void CPUWaster::loopDriven()
{
    timer_driven = FALSE;
    options->setItemChecked(ld_id, TRUE);
    options->setItemChecked(td_id, FALSE);
}

void CPUWaster::defaultLabel()
{
    default_label = TRUE;
    options->setItemChecked(dl_id, TRUE);
    options->setItemChecked(cl_id, FALSE);
}

void CPUWaster::customLabel()
{
    default_label = FALSE;
    options->setItemChecked(dl_id, FALSE);
    options->setItemChecked(cl_id, TRUE);
}

void CPUWaster::toggleMinimumDuration()
{
    options->setItemChecked(md_id,
                            !options->isItemChecked(md_id));
}

void CPUWaster::timerEvent(QTimerEvent *)
{
    pb->setProgress(pb->totalSteps() - rects);
    rects--;

    {
        QPainter p(this);

        int ww = width();
        int wh = height();

        if (ww > 8 && wh > 8)
        {
            QColor c(rand() % 255, rand() % 255, rand() % 255);
            int x = rand() % (ww - 8);
            int y = rand() % (wh - 8);
            int w = rand() % (ww - x);
            int h = rand() % (wh - y);
            p.fillRect(x, y, w, h, c);
        }
    }

    if (!rects || got_stop)
    {
        pb->setProgress(pb->totalSteps());
        QPainter p(this);
        p.fillRect(0, 0, width(), height(), backgroundColor());
        enableDrawingItems(TRUE);
        killTimers();
        delete pb;
        pb = 0;
    }
}

QProgressDialog *CPUWaster::newProgressDialog(const char *label, int steps, bool modal)
{
    QProgressDialog *d = new QProgressDialog(label, "Cancel", steps, this,
                                             "progress", modal);
    if (options->isItemChecked(md_id))
        d->setMinimumDuration(0);
    if (!default_label)
        d->setLabel(new AnimatedThingy(d, label));
    return d;
}

void CPUWaster::enableDrawingItems(bool yes)
{
    for (int i = first_draw_item; i <= last_draw_item; i++)
    {
        menubar->setItemEnabled(i, yes);
    }
}

void CPUWaster::draw(int n)
{
    if (timer_driven)
    {
        if (pb)
        {
            qWarning("This cannot happen!");
            return;
        }
        rects = n;
        pb = newProgressDialog("Drawing rectangles.\n"
                               "Using timer event.",
                               n, FALSE);
        pb->setCaption("Please Wait");
        connect(pb, SIGNAL(cancelled()), this, SLOT(stopDrawing()));
        enableDrawingItems(FALSE);
        startTimer(0);
        got_stop = FALSE;
    }
    else
    {
        QProgressDialog *lpb = newProgressDialog(
            "Drawing rectangles.\nUsing loop.", n, TRUE);
        lpb->setCaption("Please Wait");

        QPainter p(this);
        for (int i = 0; i < n; i++)
        {
            lpb->setProgress(i);
            if (lpb->wasCancelled())
                break;

            QColor c(rand() % 255, rand() % 255, rand() % 255);
            int x = rand() % (width() - 8);
            int y = rand() % (height() - 8);
            int w = rand() % (width() - x);
            int h = rand() % (height() - y);
            p.fillRect(x, y, w, h, c);
        }

        p.fillRect(0, 0, width(), height(), backgroundColor());

        delete lpb;
    }
}
