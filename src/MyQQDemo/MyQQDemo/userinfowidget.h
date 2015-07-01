#ifndef USERINFOWIDGET_H
#define USERINFOWIDGET_H

#include <QWidget>

class UserInfoWidget : public QWidget
{
	Q_OBJECT

public:
	UserInfoWidget(QWidget *parent);
	~UserInfoWidget();

	void paintEvent(QPaintEvent * e);

private:
	
};

#endif // USERINFOWIDGET_H
