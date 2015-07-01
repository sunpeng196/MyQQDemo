#ifndef APPWIDGET_H
#define APPWIDGET_H

#include <QWidget>
class QHBoxLayout;
class QPushButton;
class QToolButton;


class AppWidget : public QWidget
{
	Q_OBJECT

public:
	AppWidget(QWidget *parent);
	~AppWidget();

	//void paintEvent(QPaintEvent *event);

private:

	QHBoxLayout *mainLayout;

	QToolButton *m_pAppMenuBtn;
	QPushButton *m_pSystemSetting;
	QPushButton *m_pMessageManager;
	QPushButton *m_pFileAssiant;
	QPushButton *m_pMyShouCang;
	QPushButton *m_pFind;
	QPushButton *m_pAppBaby;

	bool eventFilter(QObject *obj, QEvent *event);
	
};

#endif // APPWIDGET_H
