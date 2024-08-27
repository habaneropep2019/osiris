#include "semaphores.h"

// Use pointers to create semaphores after QApplication object!
QSemaphore *yellowSem, *greenSem;

void YellowThread::run()
{
	for (int i = 0; i < 20; i++) {
		(*yellowSem)++;

		QCustomEvent *event = new QCustomEvent(12345);
		event->setData(new QString("Yellow!"));
		QThread::postEvent(receiver, event);
		msleep(200);

		(*greenSem)--;
	}

	(*yellowSem)++;

	QCustomEvent *event = new QCustomEvent(12346);
	event->setData(new QString("Yellow!"));
	QThread::postEvent(receiver, event);

	(*greenSem)--;
}

void GreenThread::run()
{
	for (int i = 0; i < 20; i++) {
		(*greenSem)++;

		QCustomEvent *event = new QCustomEvent(12345);
		event->setData(new QString("Green!"));
		QThread::postEvent(receiver, event);
		msleep(200);

		(*yellowSem)--;
	}

	(*greenSem)++;

	QCustomEvent *event = new QCustomEvent(12346);
	event->setData(new QString("Green!"));
	QThread::postEvent(receiver, event);
	msleep(10);

	(*yellowSem)--;
}

SemaphoreExample::SemaphoreExample()
	: QWidget(), yellowThread(this), greenThread(this)
{
	button = new QPushButton("&Ignition!", this);
	connect(button, SIGNAL(clicked()), SLOT(startExample()));

	mlineedit = new QMultiLineEdit(this);
	label = new QLabel(this);

	QVBoxLayout *vbox = new QVBoxLayout(this, 5);
	vbox->addWidget(button);
	vbox->addWidget(mlineedit);
	vbox->addWidget(label);
}

void SemaphoreExample::startExample()
{
	if (yellowThread.running() || greenThread.running()) {
		QMessageBox::information(
			this, "Sorry",
			"The threads have not completed yet, and must finish before "
			"they can be started again.");

		return;
	}

	mlineedit->clear();

	while (yellowSem->available() < yellowSem->total())
		(*yellowSem)--;
	(*yellowSem)++;

	yellowThread.start();
	greenThread.start();
}

void SemaphoreExample::customEvent(QCustomEvent *event)
{
	switch (event->type()) {
	case 12345: {
		QString *s = (QString *)event->data();

		mlineedit->append(*s);

		if (*s == "Green!")
			label->setBackgroundColor(green);
		else
			label->setBackgroundColor(yellow);
		label->setText(*s);

		delete s;

		break;
	}

	case 12346: {
		QString *s = (QString *)event->data();

		QMessageBox::information(this, (*s) + " - Finished",
					 "The thread creating the \"" + *s +
						 "\" events has finished.");

		break;
	}

	default: {
		qWarning("Unknown custom event type: %d", event->type());
	}
	}
}