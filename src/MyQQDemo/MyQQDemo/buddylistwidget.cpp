#include "buddylistwidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>
#include <QString>
#include "BuddyItem.h"
#include <QImage>
#include <QBitmap>

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

}

BuddyListWidget::~BuddyListWidget()
{

}

void BuddyListWidget::paintEvent( QPaintEvent *e )
{
	QPainter painter(this);

	//scroll(0,m_VecScroll);

	painter.drawPixmap(268,0,8,433,QPixmap(":/SCrollBar/ScrollBar/scrollbar_bkg.png"));


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

		break;
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


	int w = rcItem.width();
	int h = rcItem.height();

// 	painter.drawPixmap(rcItem.left(),rcItem.top(),rcItem.width(),rcItem.height(),
// 		QPixmap(":/BuddyList/BuddyList/main_yellowbar_bkg.png"));

	int nHeadWidth = 40, nHeadHeight = 40;

	QRect rcHead;
	CalcCenterRect(rcItem, nHeadWidth, nHeadHeight, rcHead);
	rcHead.setLeft( rcItem.left() + 6);
	rcHead.setRight(rcHead.left() + nHeadWidth);

	int nHeadRight = rcHead.right();

	QString strName1 = "11111111111111111", strName2 = "2222222222222222";

	if (m_nSelTeamIndex == nTeamIndex && m_nSelIndex == nIndex)				// 选中状态
	{
		QPainter painter;
		painter.drawPixmap(rcItem.left(),rcItem.top(),QPixmap(":/BuddyList/BuddyList/BuddyItemSelBg.png"));

	}
	else if (m_nHoverTeamIndex == nTeamIndex && m_nHoverIndex == nIndex)	// 高亮状态
	{
		QPainter painter;
		painter.drawPixmap(rcItem.left(),rcItem.top(),QPixmap(":/BuddyList/BuddyList/BuddyItemHotBg.png"));
	}
	else
	{

	}

	painter.drawPixmap(rcHead,QPixmap(":/headers/Resources/94.png"));

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


	painter.drawText(nHeadRight+6,rcItem.top()+10,rcItem.width()- nHeadRight - 6,20,0,"sunpeng;");
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

void BuddyListWidget::mousePressEvent( QMouseEvent *e )
{
	if (e->buttons() == Qt::LeftButton)
	{
		QRect tempRect = rect();
		int w = tempRect.width();
		int h = tempRect.height();

		
		QPoint t = e->pos();
		if (t.x() >= 268 && t.x()<= w && t.y()>=0 && t.y()<=h)
		{
			m_nTop -= 10;
			update();
			return;
		}

		int iIndex = GetIndexFromPoint(t);

		BuddyTeam *const pItem = m_BuddyList.at(iIndex);
		pItem->setExpand(!pItem->Expand());
		update();

		
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
// 	if (!m_bMouseTracking)
// 	{
// 		TrackMouseLeave(GetSafeHwnd());
// 		m_bMouseTracking = TRUE;
// 	}

	int nTeamIndex = -1, nIndex = -1;
	HitTest(point, nTeamIndex, nIndex);

	if (nTeamIndex != m_nHoverTeamIndex || nIndex != m_nHoverIndex)
	{
		m_nHoverTeamIndex = nTeamIndex;
		m_nHoverIndex = nIndex;
		update();
		//Invalidate(FALSE);
	}

	//m_VScrollBar.OnMouseMove(nFlags, point);

	//CWnd::OnMouseMove(nFlags, point);

	return QWidget::mouseMoveEvent(e);

}


int BuddyListWidget::GetIndexFromPoint( const QPoint& pt )
{
	int y = pt.y();

	return y/24;

}

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
				rectArea = QRect(nLeft, nTop, nLeft+nBuddyTeamWidth, nTop+24);
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
							rectArea = QRect(nLeft, nTop, nLeft+nBuddyItemWidth,nBuddyItemHeight);
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

void BuddyListWidget::HitTest(QPoint pt, int& nTeamIndex, int& nIndex)
{
	BuddyTeam * lpTeamItem;
	BuddyItem * lpItem;
	int nLeft =2, nTop = 0;
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
			rcItem = QRect(nLeft, nTop, nLeft+nBuddyTeamWidth, nTop+24);
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

						rcItem = QRect(nLeft, nTop, nLeft+nBuddyItemWidth, nTop+nBuddyItemHeight);
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

// 	painter.drawPixmap(rcItem.left(),rcItem.top(),rcItem.width(),rcItem.height(),
// 		QPixmap(":/BuddyList/BuddyList/main_yellowbar_bkg.png"));

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
		if (!lpItem->m_bExpand)
		{
			painter.drawPixmap(rcArrow.left(),rcArrow.top(),rcArrow.width(),rcArrow.height(),QPixmap(":/MainPanel/Resources/mainpanel_foldernode_collapsetexture.png"));
		}
		else
		{
			painter.drawPixmap(rcArrow.left(),rcArrow.top(),rcArrow.width(),rcArrow.height(),QPixmap(":/MainPanel/Resources/mainpanel_foldernode_collapsetexturehighlight.png"));
		}
	}
	else if (m_nHoverTeamIndex == nIndex && m_nHoverIndex == -1)
	{
		painter.drawPixmap(rcArrow.left(),rcArrow.top(),rcArrow.width(),rcArrow.height(),QPixmap(""));


		if (!lpItem->m_bExpand)
		{
			painter.drawPixmap(rcArrow.left(),rcArrow.top(),rcArrow.width(),rcArrow.height(),QPixmap(":/MainPanel/Resources/mainpanel_foldernode_collapsetexturehighlight.png"));
		}
		else
		{
			painter.drawPixmap(rcArrow.left(),rcArrow.top(),rcArrow.width(),rcArrow.height(),QPixmap(":/MainPanel/Resources/mainpanel_foldernode_collapsetexturehighlight.png"));
		}
	}
	else
	{
		if (!lpItem->m_bExpand)
		{
			painter.drawPixmap(rcArrow.left(),rcArrow.top(),rcArrow.width(),rcArrow.height(),QPixmap(":/MainPanel/Resources/mainpanel_foldernode_collapsetexturehighlight.png"));
		}
		else
		{
			painter.drawPixmap(rcArrow.left(),rcArrow.top(),rcArrow.width(),rcArrow.height(),QPixmap(":/MainPanel/Resources/mainpanel_foldernode_expandtexture.png"));
		}
	}
	BuddyTeam *pTeam = m_BuddyList.at(nIndex);

	painter.drawText(rcText,0,pTeam->GetDesc());

}


void BuddyListWidget::CalcCenterRect(QRect& rcDest, int cx, int cy, QRect& rcCenter )
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
	if (event->delta() >0)
	{	
		m_nTop += 10;

		if (m_nTop > 0)
		{
			m_nTop = 0;
		}
	}
	else
	{
		m_nTop -= 10;
	}


	update();
}
