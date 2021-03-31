#include <iostream>
#include <QtGui>
#include "pane.h"

Pane::Pane()
{

}

void Pane::Draw( QPainter* qp)
{
	QRect rect = this->rect();
	int height = rect.height();
	int bottom = rect.bottom();
	int step = (height * PARTOFFIELD) / COUNTLINES;

//	QRect rc(10, 10, 100, 100);
	qp->begin(this);
	qp->setPen(QPen(Qt::black, 1));
//	qp->setBrush(black);
	qp->drawRect(/*rc*/rect);
	for(int i = 1; i <= 5; i++)
	{
	QLine  l(rect.left(), bottom - step *i , rect.right(), bottom - step * i );
	std::cout << l.dy() << std::endl;

	qp->drawLine(l);
	}
	if (note != Not)
	{
		drawNote(note, *qp);
	}
	qp->end();
}

void Pane::drawNote(Notes note, QPainter& qp)
{

	QRect rect = this->rect();
	int step = (rect.height() * PARTOFFIELD)/COUNTLINES;
	int hdiff = step/2;
	int corr = CORRECTION;

	if (note <= Re )
		corr = FINECORRECTION;

	const QPoint& p = QPoint(rect.left() + 50, (rect.bottom() - (note * hdiff)) + corr  );
	qp.setBrush(Qt::black);
	qp.drawEllipse(p, 3,3);
/*an additional line for Do*/
	if (note == Do)
	{
		const QPoint& dpl = QPoint(p.x() - 5, p.y());
		const QPoint& dpr = QPoint(p.x() + 5, p.y());
		const QLine& dash = QLine(dpl, dpr);
		qp.setPen(QPen(Qt::black, 1));
		qp.drawLine(dash);
	}
/*a note head: before Si - up, for Si - down.*/
	const int HEADHEIGHT = 10;
	const QPoint& start = QPoint(p.x() + 2, p.y());
	QPoint end = QPoint();
	if (note != Si)
	{
		end = QPoint(p.x() + 2, p.y() - HEADHEIGHT);
	}
	else
	{
		end = QPoint(p.x() + 2, p.y() + HEADHEIGHT);

	}

	const QLine& head = QLine(start, end);
	qp.drawLine(head);

}

void Pane::paintEvent(QPaintEvent *e)
{
	QPainter* qp = new QPainter(this);
	Draw( qp);
}

void Pane::setNote(Notes note)
{
	this->note = note;
	Draw(new QPainter(this));
}
