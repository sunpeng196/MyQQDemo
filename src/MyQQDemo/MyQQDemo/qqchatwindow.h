#ifndef QQCHATWINDOW_H
#define QQCHATWINDOW_H

#include <QWidget>
#include "ui_qqchatwindow.h"

class QQChatWindow : public QWidget
{
	Q_OBJECT

public:
	QQChatWindow(QWidget *parent = 0);
	~QQChatWindow();

private:
	Ui::QQChatWindow ui;
};

#endif // QQCHATWINDOW_H
