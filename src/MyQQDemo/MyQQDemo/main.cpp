#include "myqqdemo.h"
#include <QtGui/QApplication>
#include <QFile>
#include <QTextCodec>
#include "stylewidget.h"
#include "appwidget2.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

#ifdef WIN32
	QTextCodec *codec = QTextCodec::codecForName("system");
#else
	QTextCodec *codec = QTextCodec::codecForName("GBK");
#endif	
	QTextCodec::setCodecForTr(codec);
	QTextCodec::setCodecForLocale(codec);
	QTextCodec::setCodecForCStrings(codec);

// 	QFile file(":/qss/QQStyle.css");
// 	if (file.open(QIODevice::ReadOnly))
// 	{
// 		qApp->setStyleSheet(file.readAll());
// 	}
// 	file.close();

// 	StyleWidget w;
// 	//QMessageBox::information(NULL, "Title", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
// 	w.show();

	MyQQDemo w;
	w.show();

	



	return a.exec();
}
