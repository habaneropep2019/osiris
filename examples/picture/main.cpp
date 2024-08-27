#include "picture.h"

void paintCar(QPainter *p);

int main(int argc, char **argv)
{
	QApplication a(argc, argv); // QApplication required!

	const char *fileName = "car.pic"; // default picture file name

	if (argc == 2) // use argument as file name
		fileName = argv[1];

	if (!QFile::exists(fileName)) {
		QPicture pict; // our picture
		QPainter paint; // our painter

		paint.begin(&pict); // begin painting onto picture
		paintCar(&paint); // paint!
		paint.end(); // painting done

		pict.save(fileName); // save picture
		QMessageBox::information(0, "Qt picture example",
					 "Saved.  Run me again!");
		return 0;
	} else {
		PictureDisplay test(fileName); // create picture display
		a.setMainWidget(&test); // set main widget
		test.setCaption("Qt Example - Picture");
		test.show(); // show it

		return a.exec(); // start event loop
	}
}

void paintCar(QPainter *p) // paint a car
{
	QPointArray a;
	QBrush brush(Qt::yellow, Qt::SolidPattern);
	p->setBrush(brush); // use solid, yellow brush

	a.setPoints(5, 50, 50, 350, 50, 450, 120, 450, 250, 50, 250);
	p->drawPolygon(a); // draw car body

	QFont f("courier", 12, QFont::Bold);
	p->setFont(f);

	QColor windowColor(120, 120, 255); // a light blue color
	brush.setColor(windowColor); // set this brush color
	p->setBrush(brush); // set brush
	p->drawRect(80, 80, 250, 70); // car window
	p->drawText(180, 80, 150, 70, Qt::AlignCenter,
		    "--  Qt  --\nTrolltech AS");

	QPixmap pixmap;
	if (pixmap.load("flag.bmp")) // load and draw image
		p->drawPixmap(100, 85, pixmap);

	p->setBackgroundMode(Qt::OpaqueMode); // set opaque mode
	p->setBrush(Qt::DiagCrossPattern); // black diagonal cross pattern
	p->drawEllipse(90, 210, 80, 80); // back wheel
	p->setBrush(Qt::CrossPattern); // black cross fill pattern
	p->drawEllipse(310, 210, 80, 80); // front wheel
}