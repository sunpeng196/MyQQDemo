#ifndef COLUMNWIDGET2_H
#define COLUMNWIDGET2_H

#include <QWidget>

class QPushButton;

class ColumnWidget2 : public QWidget
{
	Q_OBJECT

public:
	ColumnWidget2(QWidget *parent);
	~ColumnWidget2();

private:
	QPushButton *m_pContractBtn;
};

#endif // COLUMNWIDGET2_H
