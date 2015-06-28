#include "buddylistwidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>
#include <QString>
#include "BuddyItem.h"
#include <QImage>
#include <QBitmap>
#include <QScrollBar>
#include <QPoint>

BuddyListWidget::BuddyListWidget(QWidget *parent)
	: QWidget(parent)
{
	QPalette palette;
	setAutoFillBackground(true);
	QBrush brush(QPixmap(":/MyQQDemo/Resources/Bg.png"));
	palette.setBrush(this->backgroundRole(),brush);
	this->setPalette(palette);

	InitList();

	setMouseTracking(true);

	m_iCurrentSelectd = -1;

	m_nHoverTeamIndex = m_nHoverIndex = -1;

	m_nPressTeamIndex = m_nPressIndex = -1;

	m_nSelTeamIndex = -1;

	m_nSelIndex = -1;

	m_VecScroll = 0;

	m_nLeft = m_nTop = 0;

	m_dwHeadFlashAnimTimerId = 0;


	m_pScrollBar = new QScrollBar(this);

	QObject::connect(m_pScrollBar,SIGNAL(valueChanged(int)),this,SLOT(ScrollBarValueChanged(int)));

	m_pScrollBar->setGeometry(260,0,8,433);
	m_pScrollBar->setObjectName("ScrollBar");


	m_pScrollBar->installEventFilter(this);

	 //setStyleSheet("border:none");


	m_pScrollBar->setStyleSheet("QScrollBar:vertical"
		"{"
		"width:8px;"
		"background:rgba(0,0,0,0%);"
		"margin:0px,0px,0px,0px;"
		"padding-top:9px;"
		"padding-bottom:9px;"
		"}"
		"QScrollBar::handle:vertical"
		"{"
		"width:8px;"
		"background:rgba(0,0,0,25%);"
		" border-radius:4px;"
		"min-height:20;"
		"}"
		"QScrollBar::handle:vertical:hover"
		"{"
		"width:8px;"
		"background:rgba(0,0,0,50%);"
		" border-radius:4px;"
		"min-height:20;"
		"}"
		"QScrollBar::add-line:vertical"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/ScrollBar/Resources/ScrollBar/scrollbar_arrowup_down.png);"
		"subcontrol-position:bottom;"
		"}"
		"QScrollBar::sub-line:vertical"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/ScrollBar/Resources/ScrollBar/scrollbar_arrowup_highlight.png);"
		"subcontrol-position:top;"
		"}"
		"QScrollBar::add-line:vertical:hover"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/ScrollBar/Resources/ScrollBar/scrollbar_arrowdown_normal.png);"
		"subcontrol-position:bottom;"
		"}"
		"QScrollBar::sub-line:vertical:hover"
		"{"
		"height:9px;width:8px;"
		"border-image:url(:/ScrollBar/Resources/ScrollBar/scrollbar_arrowdown_highlight.png);"
		"subcontrol-position:top;"
		"}"
		"QScrollBar::add-page:vertical,QScrollBar::sub-page:vertical"
		"{"
		"background:rgba(0,0,0,10%);"
		"border-radius:4px;"
		"}"
		);

}

BuddyListWidget::~BuddyListWidget()
{

}



void BuddyListWidget::paintEvent( QPaintEvent *e )
{
	QPainter painter(this);

	int h = GetContentHeight();
	if (h > height())
	{
		m_pScrollBar->setHidden(false);
		m_pScrollBar->setEnabled(true);

		m_pScrollBar->setMinimum(0);
		m_pScrollBar->setMaximum(h - height());
	}
	else
	{
		m_pScrollBar->setHidden(true);
	}


	BuddyTeam * lpTeamItem;
	for (int i = 0; i < (int)m_BuddyList.size(); i++)
	{
		DrawBuddyTeam(i);

		lpTeamItem = m_BuddyList.at(i);
		if (lpTeamItem != NULL && lpTeamItem->m_bExpand)
		{
			for (int j = 0; j < (int)lpTeamItem->m_BuddyItemList.size(); j++)
			{
				DrawBuddyItemInBigIcon(i, j);
			}
		}
	}



}

void BuddyListWidget::DrawBuddyItemInBigIcon(int nTeamIndex, int nIndex)
{
	QPainter painter(this);

	BuddyItem * lpItem = GetBuddyItemByIndex(nTeamIndex, nIndex);
	if (NULL == lpItem)
		return;

	QRect rcItem;
	GetItemRectByIndex(nTeamIndex, nIndex, rcItem);

	int nHeadWidth = 40, nHeadHeight = 40;

	QRect rcHead;
	CalcCenterRect(rcItem, nHeadWidth, nHeadHeight, rcHead);
	rcHead.setLeft( rcItem.left() + 6);
	rcHead.setRight(rcHead.left() + nHeadWidth);

	int nHeadRight = rcHead.right();

	if (m_nSelTeamIndex == nTeamIndex && m_nSelIndex == nIndex)				// 选中状态
	{
		painter.drawPixmap(rcItem.left(),rcItem.top(),rcItem.width(),rcItem.height(),
			QPixmap(":/BuddyList/BuddyList/main_yellowbar_bkg.png"));

	}
	else if (m_nHoverTeamIndex == nTeamIndex && m_nHoverIndex == nIndex)	// 高亮状态
	{
		painter.drawPixmap(rcItem.left(),rcItem.top(),rcItem.width(),rcItem.height(),
			QPixmap(":/BuddyList/BuddyList/main_yellowbar_bkg.png"));
	}
	else
	{

	}



	if (m_nSelTeamIndex == nTeamIndex && m_nSelIndex == nIndex)
	{
		QRect rcHeadFrame(rcHead);

		rcHeadFrame.setLeft(rcHeadFrame.left() - 3);
		rcHeadFrame.setRight(rcHeadFrame.right() + 3);
		rcHeadFrame.setTop(rcHeadFrame.top() - 3);
		rcHeadFrame.setBottom(rcHeadFrame.bottom() + 3);


		painter.drawPixmap(rcHeadFrame.left(),rcHeadFrame.top(),rcHeadFrame.width(),rcHeadFrame.height(),
			QPixmap(":/BuddyList/BuddyList/Padding4Select.png"));


	}

	if (lpItem->m_bHeadFlashAnim)	// 头像闪动动画
	{
		QPoint pts[] = { QPoint(-1,1),QPoint(0,0),QPoint(1,1),QPoint(0,0)};

		if (lpItem->m_nHeadFlashAnimState >= 0 && lpItem->m_nHeadFlashAnimState < 4)
			rcHead.translate(pts[lpItem->m_nHeadFlashAnimState]);
	}

	painter.drawPixmap(rcHead,QPixmap(":/headers/Resources/94.png"));


	painter.drawText(nHeadRight+6,rcItem.top()+10,rcItem.width()- nHeadRight - 6,20,0,"sunpeng");
 	painter.drawText(nHeadRight+6,rcItem.top()+30,rcItem.width()- nHeadRight - 6,20,0,"和我一起学习QT，制作QT制作的QQ界面");
}

BuddyItem * BuddyListWidget::GetBuddyItemByIndex(int nTeamIndex, int nIndex)
{
	BuddyTeam * lpTeamItem;

	if (nTeamIndex >= 0 && nTeamIndex < (int)m_BuddyList.size())
	{
		lpTeamItem = m_BuddyList.at(nTeamIndex);
		if (lpTeamItem != NULL)
		{
			if (nIndex >= 0 && nIndex < (int)lpTeamItem->m_BuddyItemList.size())
				return lpTeamItem->m_BuddyItemList.at(nIndex);
		}
	}
	return NULL;
}

void BuddyListWidget::InitList()
{
	BuddyTeam *pUserList = new BuddyTeam("我的好友",48,12);
	m_BuddyList.append(pUserList);

	pUserList = new BuddyTeam("同事",48,12);
	m_BuddyList.append(pUserList);

	pUserList = new BuddyTeam("同学",48,12);
	m_BuddyList.append(pUserList);


}


void BuddyListWidget::SetBuddyItemHeadFlashAnim(int nTeamIndex, int nIndex, bool bHeadFlashAnim)
{
	BuddyItem * lpBuddyItem = GetBuddyItemByIndex(nTeamIndex, nIndex);
	if (NULL == lpBuddyItem || bHeadFlashAnim == lpBuddyItem->m_bHeadFlashAnim)
		return;

	lpBuddyItem->m_bHeadFlashAnim = bHeadFlashAnim;
	lpBuddyItem->m_nHeadFlashAnimState = 0;
	if (bHeadFlashAnim)
	{
		BuddyTeam * lpBuddyTeam = m_BuddyList.at(nTeamIndex);
		if (lpBuddyTeam != NULL)
		{
			lpBuddyTeam->m_nHeadFlashAnim++;
		}

		if (NULL == m_dwHeadFlashAnimTimerId)	// 启动头像闪动动画计时器
			m_dwHeadFlashAnimTimerId = startTimer(250);
	}
	else
	{
		BuddyTeam * lpBuddyTeam = m_BuddyList.at(nTeamIndex);
		if (lpBuddyTeam != NULL)
		{
			lpBuddyTeam->m_nHeadFlashAnim--;
			if (lpBuddyTeam->m_nHeadFlashAnim <= 0)
				lpBuddyTeam->m_nHeadFlashAnimState = 0;
		}

		bool bHasAnim = FALSE;

		int nTeamCnt = m_BuddyList.size();
		for (int i = 0; i < nTeamCnt; i++)
		{
			lpBuddyTeam = m_BuddyList.at(i);
			if (lpBuddyTeam != NULL && lpBuddyTeam->m_nHeadFlashAnim > 0)
			{
				bHasAnim = TRUE;
				break;
			}
		}

		if (!bHasAnim)
		{
			killTimer(m_dwHeadFlashAnimTimerId);
			m_dwHeadFlashAnimTimerId = NULL;

			if (isVisible())
			{
				update();
			}
		}
	}
}


void BuddyListWidget::OnTimer_HeadFlashAnim(int nIDEvent)
{
	if (nIDEvent != m_dwHeadFlashAnimTimerId)
		return;

	int nTeamCnt = m_BuddyList.size();
	for (int i = 0; i < nTeamCnt; i++)
	{
		BuddyTeam * lpBuddyTeam = m_BuddyList.at(i);
		if (lpBuddyTeam != NULL)
		{
			if (lpBuddyTeam->m_nHeadFlashAnim > 0)
			{
				if (!lpBuddyTeam->m_bExpand)
				{
					lpBuddyTeam->m_nHeadFlashAnimState++;
					if (lpBuddyTeam->m_nHeadFlashAnimState >= 2)
						lpBuddyTeam->m_nHeadFlashAnimState = 0;
				}
				else
				{
					int nItemCnt = m_BuddyList.size();
					for (int j = 0; j < nItemCnt; j++)
					{
						BuddyItem * lpBuddyItem = GetBuddyItemByIndex(i, j);
						if (lpBuddyItem != NULL && lpBuddyItem->m_bHeadFlashAnim)
						{
							lpBuddyItem->m_nHeadFlashAnimState++;
							if (lpBuddyItem->m_nHeadFlashAnimState >= 4)
								lpBuddyItem->m_nHeadFlashAnimState = 0;
						}
					}
				}
			}
		}
	}
	update();
}

void BuddyListWidget::mousePressEvent( QMouseEvent *e )
{
	if (e->buttons() == Qt::LeftButton)
	{
		QRect tempRect = rect();
		int w = tempRect.width();
		int h = tempRect.height();

		
		QPoint t = e->pos();
		int nTeamIndex = -1;
		int nIndex = -1;
		HitTest(t,nTeamIndex,nIndex);
		if (nTeamIndex == -1 && nIndex == -1)
		{
			return;
		}

		if (nTeamIndex != -1 && nIndex == -1)//表明选中的是一个组选项
		{
			m_nSelTeamIndex = nTeamIndex;
			m_nSelIndex = -1;

			BuddyTeam *const pItem = m_BuddyList.at(m_nSelTeamIndex);
			pItem->setExpand(!pItem->Expand());
			update();
		}
		else//表明选中的是一个单个项目
		{
			m_nSelTeamIndex = nTeamIndex;
			m_nSelIndex = nIndex;
		}



		
	}

}

void BuddyListWidget::mouseReleaseEvent( QMouseEvent *e )
{


}

void BuddyListWidget::mouseMoveEvent( QMouseEvent *e )
{
	QPoint t = e->pos();
	if (m_nPressTeamIndex != -1)
		return;
	QPoint point = e->pos();
	if (!rect().contains(point))
	{
		m_nHoverIndex = -1;
		m_nHoverTeamIndex = -1;
	}

	int nTeamIndex = -1, nIndex = -1;
	HitTest(point, nTeamIndex, nIndex);

	if (nTeamIndex != m_nHoverTeamIndex || nIndex != m_nHoverIndex)
	{
		m_nHoverTeamIndex = nTeamIndex;
		m_nHoverIndex = nIndex;
		update();
	}
	else
	{

	}

	return QWidget::mouseMoveEvent(e);

}


// int BuddyListWidget::GetIndexFromPoint( const QPoint& pt )
// {
// 	int y = pt.y();
// 
// 	return y/24;
// 
// }

void BuddyListWidget::AddBuddyItem( int iGroupIndex )
{

}

bool BuddyListWidget::GetItemRectByIndex( int nTeamIndex,int nIndex,QRect &rectArea)
{
	BuddyTeam * lpTeamItem;
	BuddyItem * lpItem;

	int nBuddyTeamWidth, nBuddyItemWidth, nBuddyItemHeight;

	QRect rcClient = rect();

	int abc = rcClient.width();
	nBuddyTeamWidth = rcClient.width() - 2 - 2 - 0;
	nBuddyItemWidth = nBuddyTeamWidth;


	nBuddyItemHeight = 54;
	int nLeft = 2;
	int nTop = m_nTop;


	for (int i = 0; i < (int)m_BuddyList.size(); i++)
	{
		lpTeamItem = m_BuddyList.at(i);

		if (lpTeamItem != NULL)
		{
			if (-1 == nIndex && i == nTeamIndex)
			{
				rectArea = QRect(nLeft, nTop, nBuddyTeamWidth,24);
				return TRUE;
			}

			nTop += 24;
			nTop += 1;

			if (lpTeamItem->m_bExpand)
			{
				for (int j = 0; j < (int)lpTeamItem->m_BuddyItemList.size(); j++)
				{
					lpItem = lpTeamItem->m_BuddyItemList.at(j);
					if (lpItem != NULL)
					{
// 						if (BLC_SMALL_ICON_STYLE == m_nStyle && m_bShowBigIconInSel
// 							&& (m_nSelTeamIndex == i && m_nSelIndex == j))
// 							nBuddyItemHeight = m_nBuddyItemHeightInBig;

						if (i == nTeamIndex && j == nIndex)
						{
							rectArea = QRect(nLeft, nTop,nBuddyItemWidth,nBuddyItemHeight);
							return TRUE;
						}
						nTop += nBuddyItemHeight;
						nTop += 1;

// 						if (BLC_SMALL_ICON_STYLE == m_nStyle && m_bShowBigIconInSel
// 							&& (m_nSelTeamIndex == i && m_nSelIndex == j))
// 							nBuddyItemHeight = m_nBuddyItemHeightInSmall;
					}
				}
			}
		}
	}

	return FALSE;
}

//从头到尾遍历，计算每一个索引所对应的鼠标的范围。如果范围当中包含鼠标的点击范围，则当前索引就是
//需要的索引范围。

void BuddyListWidget::HitTest(QPoint pt, int& nTeamIndex, int& nIndex)
{
	BuddyTeam * lpTeamItem;
	BuddyItem * lpItem;
	int nLeft =2, nTop = m_nTop;
	int nBuddyTeamWidth, nBuddyItemWidth, nBuddyItemHeight;
	QRect rcItem;

	nTeamIndex = -1;
	nIndex = -1;

	QRect rcClient = rect();

// 	int nVScrollBarWidth = 0;
// 	if (m_VScrollBar.IsVisible())
// 	{
// 		CRect rcVScrollBar;
// 		m_VScrollBar.GetRect(&rcVScrollBar);
// 		nVScrollBarWidth = rcVScrollBar.Width();
// 	}

	nBuddyTeamWidth = rcClient.width() - 2 - 2 - 0;
	nBuddyItemWidth = nBuddyTeamWidth;
	nBuddyItemHeight = 54;


	for (int i = 0; i < (int)m_BuddyList.size(); i++)
	{
		lpTeamItem = m_BuddyList.at(i);
		if (lpTeamItem != NULL)
		{
			rcItem = QRect(nLeft, nTop, nBuddyTeamWidth,24);
			if (rcItem.contains(pt))
			{
				nTeamIndex = i;
				nIndex = -1;
				return;
			}

			nTop += 24;
			nTop += 0;

			if (lpTeamItem->m_bExpand)
			{
				for (int j = 0; j < (int)lpTeamItem->m_BuddyItemList.size(); j++)
				{
					lpItem = lpTeamItem->m_BuddyItemList[j];
					if (lpItem != NULL)
					{
// 						if (BLC_SMALL_ICON_STYLE == m_nStyle && m_bShowBigIconInSel
// 							&& (m_nSelTeamIndex == i && m_nSelIndex == j))
// 							nBuddyItemHeight = m_nBuddyItemHeightInBig;

						rcItem = QRect(nLeft, nTop, nBuddyItemWidth,nBuddyItemHeight);
						if (rcItem.contains(pt))
						{
							nTeamIndex = i;
							nIndex = j;
							return;
						}

						nTop += nBuddyItemHeight;
						nTop += 1;

// 						if (BLC_SMALL_ICON_STYLE == m_nStyle && m_bShowBigIconInSel
// 							&& (m_nSelTeamIndex == i && m_nSelIndex == j))
// 							nBuddyItemHeight = m_nBuddyItemHeightInSmall;
					}
				}
			}
		}
	}
}

void BuddyListWidget::DrawBuddyTeam(int nIndex)
{
	QPainter painter(this);
	BuddyTeam * lpItem = m_BuddyList.at(nIndex);
	if (NULL == lpItem)
		return;

	QRect rcItem;
	GetItemRectByIndex(nIndex, -1, rcItem);//rcItem为矩形区域所在的位置。


	int h = rcItem.height();

	int nArrowWidth = 12, nArrowHeight = 12;

	QRect rcArrow;
	CalcCenterRect(rcItem, nArrowWidth, nArrowHeight, rcArrow);


	rcArrow.setLeft(rcItem.left() + 2);
	rcArrow.setRight(rcArrow.left() + nArrowWidth);

	QRect rcText(rcItem);
	rcText.setLeft(rcArrow.right() + 6);
	rcText.setTop(rcArrow.top() + 1);

	if (m_nSelTeamIndex == nIndex && m_nSelIndex == -1)//组选中
	{
		painter.drawPixmap(rcItem.left(),rcItem.top(),rcItem.width(),rcItem.height(),
			QPixmap(":/BuddyList/BuddyList/main_yellowbar_bkg.png"));
		if (!lpItem->m_bExpand)
		{
			painter.drawPixmap(rcArrow.left(),rcArrow.top(),rcArrow.width(),rcArrow.height(),QPixmap(":/MainPanel/Resources/mainpanel_foldernode_collapsetexture.png"));
		}
		else
		{
			painter.drawPixmap(rcArrow.left(),rcArrow.top(),rcArrow.width(),rcArrow.height(),QPixmap(":/MainPanel/Resources/mainpanel_foldernode_expandtexture.png"));
		}
	}
	else if (m_nHoverTeamIndex == nIndex && m_nHoverIndex == -1)
	{
		painter.drawPixmap(rcItem.left(),rcItem.top(),rcItem.width(),rcItem.height(),
			QPixmap(":/BuddyList/BuddyList/main_yellowbar_bkg.png"));

		if (!lpItem->m_bExpand)
		{
			painter.drawPixmap(rcArrow.left(),rcArrow.top(),rcArrow.width(),rcArrow.height(),QPixmap(":/MainPanel/Resources/mainpanel_foldernode_collapsetexturehighlight.png"));
		}
		else
		{
			painter.drawPixmap(rcArrow.left(),rcArrow.top(),rcArrow.width(),rcArrow.height(),QPixmap(":/MainPanel/Resources/MainPanel_FolderNode_expandTextureHighlight.png"));
		}
	}
	else
	{
		if (!lpItem->m_bExpand)
		{
			painter.drawPixmap(rcArrow.left(),rcArrow.top(),rcArrow.width(),rcArrow.height(),QPixmap(":/MainPanel/Resources/mainpanel_foldernode_collapsetexture.png"));
		}
		else
		{
			painter.drawPixmap(rcArrow.left(),rcArrow.top(),rcArrow.width(),rcArrow.height(),QPixmap(":/MainPanel/Resources/mainpanel_foldernode_expandtexture.png"));
		}
	}
	BuddyTeam *pTeam = m_BuddyList.at(nIndex);

	bool bShowText = true;
	if (!lpItem->m_bExpand && lpItem->m_nHeadFlashAnim > 0)
	{
		if (1 == lpItem->m_nHeadFlashAnimState)
			bShowText = false;
	}

	if (bShowText)
	{
		painter.drawText(rcText,0,pTeam->GetDesc());
	}

}


void BuddyListWidget::CalcCenterRect(const QRect& rcDest, int cx, int cy, QRect& rcCenter )
{
	int x = ((rcDest.right()-rcDest.left()) - cx + 1) / 2;
	int y = ((rcDest.bottom()-rcDest.top()) - cy + 1) / 2;

	rcCenter.setLeft(rcDest.left()+x);
	rcCenter.setTop(rcDest.top()+y);
	rcCenter.setRight(rcCenter.left()+cx);
	rcCenter.setBottom(rcCenter.top()+cy);
}

void BuddyListWidget::wheelEvent( QWheelEvent * event )
{
	int nLineSize = 30;

	int m = event->delta();

	if (event->delta() >0)
	{	
		int sliderPositon = m_pScrollBar->sliderPosition();
		m_pScrollBar->setSliderPosition(sliderPositon - nLineSize);
	}
	else
	{
		int sliderPositon = m_pScrollBar->sliderPosition();
		m_pScrollBar->setSliderPosition(sliderPositon + nLineSize);
	}


	update();
}



// bool BuddyListWidget::eventFilter( QObject *obj, QEvent *event )
// {
// 	if (m_pScrollBar && obj == m_pScrollBar ) {
// 		if (event->type() == QEvent::MouseButtonPress) 
// 		{
// 			QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
// 			if (mouseEvent->buttons() & Qt::LeftButton)
// 			{
// 				m_LastPt = mouseEvent->pos();
// 				m_bScrollButtonDown = true;
// 			}
// 		}
// 		else if (event->type() == QEvent::MouseButtonRelease)
// 		{
// 			QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
// 			if (mouseEvent->buttons() & Qt::LeftButton)
// 			{
// 				m_bScrollButtonDown = false;
// 			}
// 
// 		}
// 		else if (event->type() == QEvent::MouseMove)
// 		{
// 			QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
// 			if (mouseEvent->buttons() & Qt::LeftButton)
// 			{
// 				if (m_bScrollButtonDown)
// 				{
// 					QPoint pt = mouseEvent->pos();
// 					int deltay = pt.y() - m_LastPt.y();
// 
// 					m_nTop -= deltay;
// 
// 					m_LastPt = pt;
// 
// 					update();
// 
// 				}
// 
// 			}
// 		}
// 	}
// 
// 	return QWidget::eventFilter(obj,event);
// }

int BuddyListWidget::GetContentHeight()
{
	int nTop = 0;
	for (int i = 0;i< m_BuddyList.size();++i)
	{
		nTop += 24;

		BuddyTeam *pItem = m_BuddyList.at(i);
		if (pItem && pItem->Expand())
		{
			for (int j = 0;j<pItem->m_BuddyItemList.size();++j)
			{
				nTop += 54;
				nTop += 1;
			}

		}

	}

	return nTop;

}

void BuddyListWidget::showEvent( QShowEvent * e )
{
	int h = GetContentHeight();
	int m = height();
	if (height() > h)
	{
		m_pScrollBar->setHidden(true);
	}
	else
	{
		m_pScrollBar->setHidden(false);
	}
}


void BuddyListWidget::Scroll()
{
	if (m_pScrollBar->isVisible()&& m_pScrollBar->isEnabled())
	{
		int nPos = m_pScrollBar->sliderPosition();
		m_nTop = 0 - nPos;

		update();
	}
}

void BuddyListWidget::ScrollBarValueChanged( int value )
{
	if (value >0)
	{
		Scroll();
	}
	else
	{
		Scroll();
	}

}

void BuddyListWidget::timerEvent( QTimerEvent * e )
{
	return;
	int m = e->timerId();
	if (e->timerId() == m_dwHeadFlashAnimTimerId)
	{
		OnTimer_HeadFlashAnim(m_dwHeadFlashAnimTimerId);
	}

}
