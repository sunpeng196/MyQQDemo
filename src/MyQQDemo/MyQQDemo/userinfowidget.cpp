#include "userinfowidget.h"
#include <QPainter>

UserInfoWidget::UserInfoWidget(QWidget *parent)
	: QWidget(parent)
{



	//setAutoFillBackground(true);


	QPalette palette;
	setAutoFillBackground(true);
	QBrush brush(QColor(233,221,213));
	palette.setBrush(this->backgroundRole(),brush);
	this->setPalette(palette);



}

UserInfoWidget::~UserInfoWidget()
{

 }

void UserInfoWidget::paintEvent( QPaintEvent * e )
{
// 	QPainter painter(this);
// 	painter.drawText(20,20,"fdksjf;asdkjdfk;asdjkf");

}
