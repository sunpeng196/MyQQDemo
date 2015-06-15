#ifndef MYQQDEMO_H
#define MYQQDEMO_H

#include <QtGui/QMainWindow>
#include "ui_myqqdemo.h"

class MyQQDemo : public QMainWindow
{
	Q_OBJECT

public:
	MyQQDemo(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MyQQDemo();

private:
	Ui::MyQQDemoClass ui;
};

#endif // MYQQDEMO_H
