#ifndef PANE_H
#define PANE_H

#include <QWidget>

enum Notes
{
	Not = 0,
	Do = 1,
	Re = 2,
	Mi = 3,
	Fa = 4,
	Sol = 5,
	La = 6,
	Si = 7

};

class Pane : public QWidget
{
public:
    Pane();
	void setNote(Notes note);
protected:
	Notes note = Not;
void paintEvent(QPaintEvent* e);
	void Draw(QPainter* pt);
	void drawNote(Notes note, QPainter& qp);
};

#endif // PANE_H
