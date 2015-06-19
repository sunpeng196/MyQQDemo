#include "titlebar.h"
#include <qcoreapplication.h>
#include <QMouseEvent>
#include "myqqdemo.h"


TitleBar::TitleBar(QWidget *parent)
	: QWidget(parent)
{
	this->setFixedHeight(20);

	m_bLeftPressDown = false;

	m_hBoxLayout = new QHBoxLayout(this);

	m_pQQLabelIcon = new QLabel();
	m_pQQLabelIcon->setPixmap(QPixmap(":/logo/Resources/qqlogo-16.png"));

	m_pQQLableTitle = new QLabel("QQ");


	m_pMinButton = new QToolButton();
	m_pMinButton->setIconSize(QSize(30,27));
	m_pMinButton->setObjectName("toolButtonMin");
	m_pMinButton->setAutoRaise(true);
	m_pMinButton->setToolTip("最小化");

	m_pCloseButton = new QToolButton();
	m_pCloseButton->setObjectName("toolButtonClose");
	m_pCloseButton->setIconSize(QSize(30,27));
	m_pCloseButton->setAutoRaise(true);
	m_pCloseButton->setToolTip("关闭");

	m_hBoxLayout->addWidget(m_pQQLabelIcon);
	m_hBoxLayout->addWidget(m_pQQLableTitle);
	m_hBoxLayout->addStretch(1);

	//m_hBoxLayout->addSpacerItem(new QSpacerItem(QSizePolicy::Expanding,QSizePolicy::Minimum));	


	m_hBoxLayout->addWidget(m_pMinButton);
	m_hBoxLayout->addWidget(m_pCloseButton);

	QObject::connect(m_pCloseButton,SIGNAL(clicked()),qApp,SLOT(quit()));

	m_hBoxLayout->setSpacing(0);
	m_hBoxLayout->setContentsMargins(0,0,5,0);

	setLayout(m_hBoxLayout);

}

TitleBar::~TitleBar()
{

}

void TitleBar::mousePressEvent( QMouseEvent * event )
{
	if (event->button() == Qt::LeftButton)
	{
		m_bLeftPressDown = true;

		m_ptPrev = event->globalPos();
		event->ignore();
		return;
	}

	event->ignore();

}

void TitleBar::mouseMoveEvent( QMouseEvent * event )
{
	if (m_bLeftPressDown)
	{
		m_ptMove = event->globalPos();
		MyQQDemo *pQQDemo = (qobject_cast<MyQQDemo*>(parent()));

		QPoint pt = m_ptMove - m_ptPrev;

		pQQDemo->move(pQQDemo->pos() + m_ptMove - m_ptPrev);

		m_ptPrev = m_ptMove;
	}

	//event->ignore();

}

void TitleBar::mouseReleaseEvent( QMouseEvent * event )
{
	if (event->button() == Qt::LeftButton)
	{
		m_bLeftPressDown = false;
	}
}
