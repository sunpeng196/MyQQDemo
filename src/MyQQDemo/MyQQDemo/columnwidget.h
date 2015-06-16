#ifndef COLUMNWIDGET_H
#define COLUMNWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
class QPushButton;
class QButtonGroup;

class ColumnWidget : public QWidget
{
	Q_OBJECT

public:
	ColumnWidget(QWidget *parent);
	~ColumnWidget();

private:

	QHBoxLayout *m_pHBoxLayout;

	QPushButton *m_pContractBtn;
	QPushButton *m_pGroupBtn;
	QPushButton *m_pLastBtn;

	QButtonGroup *m_tabBarGroup;


	
};

#endif // COLUMNWIDGET_H
