#ifndef TOOLWIDGET_H
#define TOOLWIDGET_H

#include <QWidget>

class QToolButton;
class QHBoxLayout;

class ToolWidget : public QWidget
{
	Q_OBJECT

public:
	ToolWidget(QWidget *parent);
	~ToolWidget();

private:

	QToolButton *m_pMainMenuButton;
	QHBoxLayout *m_pHBoxLayout;
	
};

#endif // TOOLWIDGET_H
