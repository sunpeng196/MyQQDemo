#ifndef APPWIDGET2_H
#define APPWIDGET2_H

#include <QWidget>
#include "ui_appwidget2.h"

class AppWidget2 : public QWidget
{
	Q_OBJECT

public:
	AppWidget2(QWidget *parent = 0);
	~AppWidget2();

private:
	Ui::AppWidget2 ui;
};

#endif // APPWIDGET2_H
