#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QWidget>
#include "ui_messagebox.h"

class MessageBox : public QWidget
{
	Q_OBJECT

public:
	MessageBox(QWidget *parent = 0);
	~MessageBox();

private:
	Ui::MessageBox ui;
};

#endif // MESSAGEBOX_H
