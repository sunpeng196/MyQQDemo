#include "qqstylepushbutton.h"



QQStylePushButton::QQStylePushButton( const QString& normalIcon, const QString& hoverIcon, const QString& selectedIcon,const QString &tooltips, QWidget *parent ): QPushButton(parent)
{
	m_NormalIcon.addFile(normalIcon);
	m_hoverIcon.addFile(hoverIcon);
	m_selectedIcon.addFile(selectedIcon);
	setToolTip(tooltips);

	setStyleSheet("background: transparent;");


	setIcon(m_NormalIcon);

}

QQStylePushButton::~QQStylePushButton()
{

}

void QQStylePushButton::mousePressEvent( QMouseEvent *e )
{
	setIcon(m_selectedIcon);
	setChecked(true);
	return QPushButton::mousePressEvent(e);
}

void QQStylePushButton::enterEvent( QEvent *event )
{
	if (isChecked())
	{
		setIcon(m_selectedIcon);
	}
	else
	{
		setIcon(m_hoverIcon);
	}
	
	return QPushButton::enterEvent(event);
}

void QQStylePushButton::leaveEvent( QEvent *event )
{
	if (isChecked())
	{
		setIcon(m_selectedIcon);
	}
	else
	{
		setIcon(m_NormalIcon);
	}

	return QPushButton::leaveEvent(event);
}
