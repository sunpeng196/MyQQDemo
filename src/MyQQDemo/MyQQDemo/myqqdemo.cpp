#include "myqqdemo.h"

MyQQDemo::MyQQDemo(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);

	setMinimumSize(270,650);
	setMaximumSize(600,715);

	this->setFixedSize(270,650);



	
}

MyQQDemo::~MyQQDemo()
{

}
