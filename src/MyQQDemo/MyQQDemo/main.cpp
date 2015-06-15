#include "myqqdemo.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MyQQDemo w;
	w.show();
	return a.exec();
}
