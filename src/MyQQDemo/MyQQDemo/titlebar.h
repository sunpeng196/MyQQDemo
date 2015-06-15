#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QBoxLayout>

class TitleBar : public QWidget
{
	Q_OBJECT

public:
	TitleBar(QWidget *parent);
	~TitleBar();

private:

	QHBoxLayout *m_hBoxLayout;
	
};

#endif // TITLEBAR_H
