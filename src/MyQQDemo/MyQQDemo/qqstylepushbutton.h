#ifndef QQSTYLEPUSHBUTTON_H
#define QQSTYLEPUSHBUTTON_H

#include <QPushButton>
#include <QIcon>

class QQStylePushButton : public QPushButton
{
	Q_OBJECT

public:
	QQStylePushButton(const QString& normalIcon,
		const QString& hoverIcon,
		const QString& selectedIcon,
		const QString& tooltip,
		QWidget *parent);
	~QQStylePushButton();

	void mousePressEvent(QMouseEvent *e);

	void enterEvent(QEvent *event);
	void leaveEvent(QEvent *event);

private:
	QIcon m_NormalIcon;
	QIcon m_selectedIcon;
	QIcon m_hoverIcon;
	
};

#endif // QQSTYLEPUSHBUTTON_H
