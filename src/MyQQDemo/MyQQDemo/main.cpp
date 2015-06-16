#include "myqqdemo.h"
#include <QtGui/QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QFile file(":/qss/QQStyle.css");
	if (file.open(QIODevice::ReadOnly))
	{
		qApp->setStyleSheet(file.readAll());
	}
	file.close();

	MyQQDemo w;
	w.show();
	return a.exec();
}
