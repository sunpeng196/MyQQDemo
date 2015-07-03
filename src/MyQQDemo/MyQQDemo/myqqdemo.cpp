#include "myqqdemo.h"
#include "titlebar.h"
#include "columnwidget.h"
#include "toolwidget.h"
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include "searchlineedit.h"
#include "buddylistwidget.h"
#include "columnwidget2.h"
#include <Windows.h>
#include <QMouseEvent>
#include <QApplication>
#include <QDesktopWidget>
#include <QPainter>
#include "userinfowidget.h"
#include "userinfowidget2.h"
#include "appwidget2.h"
#include <QStackedWidget>
#include <QListWidget>
#include <QStringListModel>

MyQQDemo::MyQQDemo(QWidget *parent, Qt::WFlags flags)
	: QFrame(parent, flags)
{
	setWindowFlags(Qt::FramelessWindowHint);

	setMinimumSize(270,650);
	setMaximumSize(600,715);

	this->setFixedSize(QSize(281,700));

	//this->setFixedSize(270,650);
	//QString styleSheet = "QMainWindow:{border:0px;}";
	setStyleSheet("QFrame {background-image:url(:/MyQQDemo/Resources/main.jpg);border:0px solid black;}");

	m_pTitleBar = new TitleBar(this);
	m_pTitleBar->setGeometry(0,0,281,30);


 	m_pColumnWidget = new ColumnWidget(this);//new ColumnWidget(this);
 	m_pColumnWidget->setGeometry(0,175,281,38);
	m_pColumnWidget->setObjectName("widgetColumn");



	//setCursor();

// 	m_pToolWidget = new ToolWidget(this);
// 
// 	m_pToolWidget->setGeometry(0,100,270,30);

	m_pSytemTrayIcon = new QSystemTrayIcon(this);
	m_pSytemTrayIcon->setIcon(QIcon(":/MyQQDemo/Resources/app_icon_16 (3).png"));
	m_pSytemTrayIcon->show();

	QMenu *pMenu = m_pSytemTrayIcon->contextMenu();
	//pMenu->addAction(new QAction(tr("显示主界面")));

	m_pSytemTrayIcon->setContextMenu(pMenu);

// 	m_pSearchLineEdit = new SearchLineEdit(this);
// 
// 	m_pSearchLineEdit->setGeometry(0,100,280,30);




/*	m_pBuddyList->setGeometry(0,214,278,443);*/


// 	m_pGroupList->setGeometry(0,214,278,443);
// 	m_pLastGroup->setGeometry(0,214,278,443);

// 	m_pBuddyList->setVisible(true);
// 	m_pGroupList->setVisible(false);
// 	m_pLastGroup->setVisible(false);

	m_pStackedWidget = new QStackedWidget(this);

	m_pBuddyList = new BuddyListWidget(m_pStackedWidget);
	//m_pGroupList = new BuddyListWidget(m_pStackedWidget);
	//m_pLastGroup = new BuddyListWidget(m_pStackedWidget);


	m_pStackedWidget->addWidget(m_pBuddyList);

	QListWidget *pListWidget = new QListWidget(m_pStackedWidget);
	m_pStackedWidget->addWidget(pListWidget);

	pListWidget->addItem(new QListWidgetItem("asdfjklsaj"));

	QListWidget *pListWidget2 = new QListWidget(m_pStackedWidget);
	m_pStackedWidget->addWidget(pListWidget2);

	pListWidget2->addItem(new QListWidgetItem("daskfjklask;jfasd;fjas"));



	//m_pStackedWidget->addWidget(m_pGroupList);
	//m_pStackedWidget->addWidget(m_pLastGroup);

	//QListWidget *pList = new QListWidget(m_pStackedWidget);



	m_pStackedWidget->setCurrentIndex(0);
	m_pStackedWidget->setGeometry(0,214,278,443);

	QObject::connect(m_pColumnWidget,SIGNAL(currentRowChanged(int)),m_pStackedWidget,SLOT(setCurrentIndex(int)));


	m_pBuddyList->SetBuddyItemHeadFlashAnim(0,1,true);


	m_pAppWidget = new AppWidget2(this);

	m_pAppWidget->setGeometry(0,height()-60,width(),60);

	QRect rect = m_pAppWidget->rect();


	rect = m_pAppWidget->geometry();

	QPoint pt = m_pAppWidget->pos();

	int h = m_pAppWidget->height();
	int w = m_pAppWidget->width();


	m_enHideType = en_None;

	setMouseTracking(true);

	m_bTimed = false;//表明是否启动监控鼠标离开的监视器。该监视器在窗口移动到窗口边缘的时候开始启动

	m_bLeftBtnDown = false;//表明鼠标左键是否被按下

	m_bSearchEnable = false;

	m_pSearchLineEdit = new SearchLineEdit(this);

	int m = width();
	m_pSearchLineEdit->setGeometry(0,145,width(),30);

	m_UserInfoWidget = new UserInfoWidget2(this);

	m_UserInfoWidget->setGeometry(0,30,width(),100);





	



	
}

MyQQDemo::~MyQQDemo()
{

}

void MyQQDemo::mousePressEvent( QMouseEvent * e )
{
	m_bLeftBtnDown = true;

// 	QPoint pt = e->pos();
// 	QRect rect(1,120,280,30);
// 	if (rect.contains(pt))
// 	{
// 		m_bSearchEnable = true;
// 		update();
// 	}
// 	else
// 	{
// 		m_bSearchEnable = false;
// 		update();
// 	}
}

void MyQQDemo::mouseMoveEvent( QMouseEvent * e )
{
// 	QPoint pt = e->pos();
// 	if (pt.x() <= 4 && pt.y()<= 4)
// 	{
// 		setCursor(Qt::SizeFDiagCursor);
// 	}
// 	else if(pt.x()<= 4 && pt.y() + 4 > height())
// 	{
// 		setCursor(Qt::SizeBDiagCursor);
// 	}
// 	else if (pt.x() + 4 >= width() && pt.y()<= 4)
// 	{
// 		setCursor(Qt::SizeBDiagCursor);
// 	}
// 	else if (pt.x() + 4 >= width() && pt.y() + 4 >height())
// 	{
// 		setCursor(Qt::SizeFDiagCursor);
// 	}
// 	else if (pt.x() <= 4)//左边
// 	{
// 		setCursor(Qt::SizeHorCursor);
// 	}
// 	else if (pt.y() + 4 >= height())//底部
// 	{
// 		setCursor(Qt::SizeVerCursor);
// 	}
// 	else if (pt.x() + 4 >= width())//最右边
// 	{
// 		setCursor(Qt::SizeHorCursor);
// 	}
// 	else if (pt.y() <= 4)//顶部
// 	{
// 		setCursor(Qt::SizeVerCursor);
// 	}
// 	else
// 	{
// 		setCursor(Qt::ArrowCursor);
// 	}


}

void MyQQDemo::mouseReleaseEvent( QMouseEvent * e )
{
	m_bLeftBtnDown = false;
}

bool MyQQDemo::winEvent( MSG * message, long * result )
{
	switch(message->message)  
	{  
	case WM_NCHITTEST:
		{

			BeginHide(pos());

			return false;
		}
		 

		
	}  
	return false;  

}


void MyQQDemo::BeginHide(QPoint point)
{
	QRect rect = QApplication::desktop()->availableGeometry();

	int iScreenHeight = rect.height();
	int iScreenWidth  = rect.width();

	if( (m_enHideType != en_None) && !m_bTimed && (point.x() < iScreenWidth + 20))
	{   
 		m_iMouseChecker = startTimer(20);
 		m_bTimed = true;
 
 		m_bFinished = false;
 		m_bHiding = false;
		m_iAniTimer = startTimer(20);
	}
}

void MyQQDemo::FixMoving(const QPoint& point)
{
	INT nScreenHeight = QApplication::desktop()->height();
	INT nScreenWidth  = QApplication::desktop()->width();

	INT nHeight = height();
	INT nWidth  = width();

	//粘附在上边
	if (point.y() <= 20)
	{  
		m_enHideType = en_Top;
	}
	//粘附在下边
	else if(point.y() >= (nScreenHeight - 20 - 30))
	{   
		m_enHideType = en_Bottom;
	}
	//粘附在左边	
	else if (point.x() < 20)
	{	
// 		if(!m_bSized)
// 		{
// 			CRect tRect;
// 			::GetWindowRect(m_hOwnHwnd,tRect);
// 			m_nWindowHeight = tRect.Height();			
// 		}
// 		pRect->right = nWidth;
// 		pRect->left = 0;
// 		pRect->top = -m_nEdgeHeight;
// 		pRect->bottom = nScreenHeight - m_nTaskBarHeight;
/*		m_bSized = TRUE;*/
		m_enHideType = en_Left;
	}
	//粘附在右边
	else if(point.x() >= (nScreenWidth - 20))
	{   
// 		if(!m_bSized)
// 		{
// 			CRect tRect;
// 			::GetWindowRect(m_hOwnHwnd,tRect);
// 			m_nWindowHeight = tRect.Height();						
// 		}
// 		pRect->left = nScreenWidth - nWidth;
// 		pRect->right = nScreenWidth;
// 		pRect->top = -m_nEdgeHeight;
// 		pRect->bottom = nScreenHeight - m_nTaskBarHeight;
// 		m_bSized = true;
		m_enHideType = en_Right;
	}
	//不粘附
	else
	{   
// 		if(m_bSized)
// 		{  
// 			pRect->bottom = pRect->top + m_nWindowHeight;
// 			m_bSized = false;
// 			InvalidateRect(m_hOwnHwnd,NULL,FALSE);
// 			SetWindowPos(HWND_TOPMOST,CRect(pRect->left,pRect->top,pRect->right,m_nWindowHeight));
// 		}
// 
// 		//如果Timer开启了,则关闭之
// 		if(m_bTimed)
// 		{  
// 			if(::KillTimer(m_hOwnHwnd,IDI_CHECKMOUSE) == 1)
// 				m_bTimed = false;
// 		}
		m_enHideType = en_None;
	}
}


void MyQQDemo::HideWindow()
{
	if(m_enHideType == en_None) return;


	int nHeight = rect().height();
	int nWidth  = rect().width();

	//步幅
	int nStride = 0;

	switch(m_enHideType)
	{
	case en_Top:
		{
			nStride = nHeight/7;
			QRect posi = geometry();
			int iNextTopPosition = posi.top() - nStride;

			if (posi.bottom() <= 3)//底部距离<=3表明到达终点
			{
				iNextTopPosition = 3 - height();
				m_bFinished = true;

			}
			this->move(posi.left(),iNextTopPosition);
		}
		break;
	case en_Bottom:
		{
// 			nStride = nHeight/STEPS_COUNT;
// 			rcWindow.top += nStride;
// 			if(rcWindow.top >= (GetSystemMetrics(SM_CYSCREEN) - m_nEdgeWidth))
// 			{
// 				rcWindow.top = GetSystemMetrics(SM_CYSCREEN) - m_nEdgeWidth;
// 				m_bFinished = true;
// 			}
// 			rcWindow.bottom = rcWindow.top + nHeight;
		}
		break;
	case en_Left:
		{
// 			nStride = nWidth/STEPS_COUNT;
// 			rcWindow.right -= nStride;
// 			if(rcWindow.right <= m_nEdgeWidth)
// 			{
// 				rcWindow.right = m_nEdgeWidth;
// 				m_bFinished = true;
// 			}
// 			rcWindow.left = rcWindow.right - nWidth;
// 			rcWindow.top = -m_nEdgeHeight;
// 			rcWindow.bottom = GetSystemMetrics(SM_CYSCREEN) - m_nTaskBarHeight;
		}
		break;
	case en_Right:
		{
// 			nStride = nWidth/STEPS_COUNT;
// 			rcWindow.left += nStride;
// 			if(rcWindow.left >= (GetSystemMetrics(SM_CXSCREEN) - m_nEdgeWidth))
// 			{
// 				rcWindow.left = GetSystemMetrics(SM_CXSCREEN) - m_nEdgeWidth;
// 				m_bFinished = true;
// 			}		
// 			rcWindow.right = rcWindow.left + nWidth;
// 			rcWindow.top = -m_nEdgeHeight;
// 			rcWindow.bottom = GetSystemMetrics(SM_CYSCREEN) - m_nTaskBarHeight;
		}
		break;
	}
}

void MyQQDemo::resizeEvent( QMouseEvent *e )
{

}

void MyQQDemo::timerEvent( QTimerEvent * e )
{
	if(e->timerId() == m_iMouseChecker)
	{
		QPoint point = cursor().pos();

		QRect rcWindow = geometry();

		rcWindow.adjust(-20,-20,20,20);

		if(!rcWindow.contains(point))
		{
			killTimer(m_iMouseChecker);
			m_bTimed = false;

			m_bFinished = false;			
			m_bHiding = true;
			m_iAniTimer = startTimer(20);		
		}
		//update();
	}
	else if(e->timerId() == m_iAniTimer)
	{
		if(m_bFinished)
			killTimer(m_iAniTimer);
		else
			m_bHiding ? HideWindow():ShowWindow();	

		//update();
	}
}


void MyQQDemo::ShowWindow()
{
	if(m_enHideType == en_None) return;

	QRect rcWindow = geometry();

	int nStride = 0;

	switch(m_enHideType)
	{
	case en_Top:
		{
			nStride = rcWindow.height()/7;
			int iNextHeight = rcWindow.top() + nStride;
			if(rcWindow.top() > -3)
			{
				iNextHeight = -3;
				m_bFinished = true;
			}

			this->move(rcWindow.left(),iNextHeight);
		}
		
		break;
// 	case en_Bottom:
// 		{
// 			nStride = nHeight/STEPS_COUNT;
// 			rcWindow.top -= nStride;
// 			if(rcWindow.top <= (GetSystemMetrics(SM_CYSCREEN) - nHeight))
// 			{
// 				rcWindow.top = GetSystemMetrics(SM_CYSCREEN) - nHeight;
// 				m_bFinished = true;
// 			}
// 			rcWindow.bottom = rcWindow.top + nHeight;
// 		}
// 		break;
// 	case en_Left:
// 		{
// 			nStride = nWidth/STEPS_COUNT;
// 			rcWindow.right += nStride;
// 			if(rcWindow.right >= nWidth)
// 			{
// 				rcWindow.right = nWidth;
// 				m_bFinished = true;
// 			}
// 			rcWindow.left = rcWindow.right - nWidth;
// 			rcWindow.top = -m_nEdgeHeight;
// 			rcWindow.bottom = GetSystemMetrics(SM_CYSCREEN) - m_nTaskBarHeight;
// 		}
// 		break;
// 	case en_Right:
// 		{
// 			nStride = nWidth/STEPS_COUNT;
// 			rcWindow.left -= nStride;
// 			if(rcWindow.left <= (GetSystemMetrics(SM_CXSCREEN) - nWidth))
// 			{
// 				rcWindow.left = GetSystemMetrics(SM_CXSCREEN) - nWidth;
// 				m_bFinished = true;
// 			}
// 			rcWindow.right = rcWindow.left + nWidth;
// 			rcWindow.top = -m_nEdgeHeight;
// 			rcWindow.bottom = GetSystemMetrics(SM_CYSCREEN) - m_nTaskBarHeight;
// 		}
// 		break;
	}

}

void MyQQDemo::moveEvent( QMoveEvent * event )
{
	QPoint pt = event->pos();
	QPoint globalPt = mapToGlobal(pt);
	FixMoving(globalPt);
}

// void MyQQDemo::paintEvent( QPaintEvent *e )
// {
// 	QPainter painter(this);
// 
// 	if (m_bSearchEnable)
// 	{
// 		painter.drawPixmap(0,120,281,500,QPixmap(":/Search/Resources/mainSearch/main_search_frame.png"));
// 
// 		return;
// 
// 	}
// 	else
// 	{
// 		painter.drawPixmap(1,120,280,30,QPixmap(":/Search/Resources/main_search_bkg.png"));
// 	}
// 
// 
// 
// 
// 
// 	return QFrame::paintEvent(e);
// }
