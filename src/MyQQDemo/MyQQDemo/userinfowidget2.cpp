#include "userinfowidget2.h"

UserInfoWidget2::UserInfoWidget2(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	ui.lineEdit->setAttribute(Qt::WA_TranslucentBackground, true);   
}

UserInfoWidget2::~UserInfoWidget2()
{

}
