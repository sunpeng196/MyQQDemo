#ifndef NAVIGATIONWIDGET_H
#define NAVIGATIONWIDGET_H

#include <QWidget>
#include "ui_navigationwidget.h"

class NavigationWidget : public QWidget
{
	Q_OBJECT

public:
	NavigationWidget(QWidget *parent = 0);
	~NavigationWidget();

private:
	Ui::NavigationWidget ui;
};

#endif // NAVIGATIONWIDGET_H
