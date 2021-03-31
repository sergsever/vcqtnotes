#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qwidget.h>
#include "pane.h"
#include <qlayout.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	Pane* p = new Pane();
	p->setGeometry(50, 50, 200, 100);
	this->layout()->addWidget(p);
	p->setNote(Do);
}

MainWindow::~MainWindow()
{
    delete ui;
}

