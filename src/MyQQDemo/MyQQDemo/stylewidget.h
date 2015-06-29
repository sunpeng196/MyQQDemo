#ifndef STYLEWIDGET_H
#define STYLEWIDGET_H

#include <QWidget>
#include "ui_stylewidget.h"
class QMouseEvent;

class StyleWidget : public QWidget
{
	Q_OBJECT

public:
	StyleWidget(QWidget *parent = 0);
	~StyleWidget();

	void mousePressEvent(QMouseEvent *e);

	int m_iStartTimer;

	void timerEvent(QTimerEvent * e);

private:
	Ui::StyleWidget ui;
};

#endif // STYLEWIDGET_H
