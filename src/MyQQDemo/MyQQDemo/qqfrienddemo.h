#ifndef QQFRIENDDEMO_H
#define QQFRIENDDEMO_H

#include <QtGui/QWidget>
#include "ui_qqfrienddemo.h"

class QQFriendDemo : public QWidget
{
	Q_OBJECT

public:
	QQFriendDemo(QWidget *parent = 0, Qt::WFlags flags = 0);
	~QQFriendDemo();

private:
	Ui::QQFriendDemoClass ui;
};

#endif // QQFRIENDDEMO_H
