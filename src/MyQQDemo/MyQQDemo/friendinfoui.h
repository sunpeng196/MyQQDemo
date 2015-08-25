#ifndef FRIENDINFOUI_H
#define FRIENDINFOUI_H

#include <QWidget>
#include "ui_friendinfoui.h"

class FriendInfoUI : public QWidget
{
	Q_OBJECT

public:
	FriendInfoUI(QWidget *parent = 0);
	~FriendInfoUI();

	Ui::FriendInfoUI ui;
};

#endif // FRIENDINFOUI_H
