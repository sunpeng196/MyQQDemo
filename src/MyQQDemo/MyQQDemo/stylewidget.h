#ifndef STYLEWIDGET_H
#define STYLEWIDGET_H

#include <QWidget>
#include "ui_stylewidget.h"

class StyleWidget : public QWidget
{
	Q_OBJECT

public:
	StyleWidget(QWidget *parent = 0);
	~StyleWidget();

private:
	Ui::StyleWidget ui;
};

#endif // STYLEWIDGET_H
