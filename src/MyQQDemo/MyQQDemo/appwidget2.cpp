#include "appwidget2.h"

AppWidget2::AppWidget2(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	setAutoFillBackground(true);


	QPalette palette;
	setAutoFillBackground(true);
	QBrush brush(QColor(233,221,213));
	palette.setBrush(this->backgroundRole(),brush);
	this->setPalette(palette);
}

AppWidget2::~AppWidget2()
{

}
