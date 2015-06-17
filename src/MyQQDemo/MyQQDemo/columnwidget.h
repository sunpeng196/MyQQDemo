#ifndef COLUMNWIDGET_H
#define COLUMNWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include "qqstylepushbutton.h"

class QPushButton;
class QButtonGroup;

class QStackedWidget;

class ColumnWidget : public QWidget
{
	Q_OBJECT

public:
	ColumnWidget(QWidget *parent);
	~ColumnWidget();

private:

	QHBoxLayout *m_pHBoxLayout;

	QQStylePushButton *m_pContractBtn;
	QQStylePushButton *m_pGroupBtn;
	QQStylePushButton *m_pLastBtn;

	QButtonGroup *m_tabBarGroup;

	QStackedWidget *m_StackedWidget;

	QVBoxLayout *m_MainLayout;
	
};

#endif // COLUMNWIDGET_H
