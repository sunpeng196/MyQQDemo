#ifndef USERINFOWIDGET2_H
#define USERINFOWIDGET2_H

#include <QWidget>
#include "ui_userinfowidget2.h"

class UserInfoWidget2 : public QWidget
{
	Q_OBJECT

public:
	UserInfoWidget2(QWidget *parent = 0);
	~UserInfoWidget2();

private:
	Ui::UserInfoWidget2 ui;
};

#endif // USERINFOWIDGET2_H
