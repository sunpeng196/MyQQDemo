#include "columnwidget.h"
#include <QPushButton>
#include <QButtonGroup>
#include <QStackedWidget>
#include <QMenu>
#include <QLabel>
#include <QPainter>
#include <QMouseEvent>
#include <QAction>

ColumnWidget::ColumnWidget(QWidget *parent)
	: QWidget(parent)
{
	 m_iCurrentHoverItem = -1;
	 m_iCurrentChooseItem = -1;
	 Init();
	 setMouseTracking(true);

	 m_nLeft = m_nTop = 0;

	 SetCurrentItem(0);
	 setStyleSheet("border:none");
}

ColumnWidget::~ColumnWidget()
{

}



void ColumnWidget::paintEvent( QPaintEvent * e )
{
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	painter.drawPixmap(0,0,width(),height(),QPixmap(":/MainTab/Resources/main_tabctrl_background.png"));

	for (int i = 0;i < m_TabCtrlList.size();++i)
	{
		DrawItem(i);
	}

}

void ColumnWidget::mousePressEvent( QMouseEvent * e )
{
	int iIndex = GetPointIndex(e->pos());
	SetCurrentItem(iIndex);
	update();

	if (iIndex == m_iCurrentChooseItem)
	{
		QMenu *pMenu = new QMenu(this);

		QMenu *pHeadImage = new QMenu(pMenu);

		QAction *pShowLargeHead = new QAction(pHeadImage);
		pShowLargeHead->setCheckable(true);
		pShowLargeHead->setChecked(true);
		pShowLargeHead->setText("大头像");

		pHeadImage->addAction(pShowLargeHead);
		pHeadImage->addAction("小头像");
		pHeadImage->addSeparator();

		pHeadImage->addAction("选中时显示大头像");
		pHeadImage->addSeparator();
		pHeadImage->addAction("显示我的大头像");



		QAction *pHeaderShow = new QAction(this);
		pHeaderShow->setText("头像显示");
		pHeaderShow->setMenu(pHeadImage);


		pMenu->addAction(pHeaderShow);




		pMenu->addAction(new QAction("名称显示",this));
		pMenu->addAction(new QAction("列表显示",this));
		pMenu->addSeparator();
		pMenu->addAction(new QAction("排序显示",this));
		pMenu->addAction(new QAction("刷新好友列表",this));
		pMenu->addAction(new QAction("显示在线联系人",this));
		pMenu->addSeparator();
		pMenu->addAction(new QAction("显示生活服务分组",this));
		pMenu->addAction(new QAction("显示陌生人分组",this));
		pMenu->addAction(new QAction("显示黑名单",this));



		//pMenu->exec(e->globalPos());

		emit currentRowChanged(m_iCurrentChooseItem);
	}
}

void ColumnWidget::mouseMoveEvent( QMouseEvent *e )
{
	int iIndex = GetPointIndex(e->pos());
	SetHoverItem(iIndex);
	update();
}

int ColumnWidget::GetPointIndex(const QPoint &pt )
{
	int iRet = -1;
	for (int i = 0;i < m_TabCtrlList.size();++i)
	{
		QRect rect;
		GetItemRectByIndex(i,rect);
		if (rect.contains(pt))
		{
			iRet = i;
			break;
		}
	}

	return iRet;
}


bool ColumnWidget::GetItemRectByIndex(int nIndex, QRect& rect)
{
	TabCtrlItem * lpItem;
	int nLeft = m_nLeft, nTop = m_nTop;

	int iWidth = (width()-2)/3-1;

	for (int i = 0; i < (int)m_TabCtrlList.size(); i++)
	{
		lpItem = m_TabCtrlList.at(i);
		if (lpItem != NULL)
		{
			if (i == nIndex)
			{
				rect = QRect(nLeft, nTop,iWidth,35);
				return TRUE;
			}
			nLeft += iWidth;
			nLeft += 1;
		}
	}

	return false;
}


void ColumnWidget::DrawItem(int i)
{
	QPainter painter(this);

	TabCtrlItem * lpItem = m_TabCtrlList.at(i);
	if (NULL == lpItem) return;

	QRect rcItem;
	GetItemRectByIndex(i, rcItem);


	if (m_iCurrentChooseItem == i)
	{
		int cxIcon = lpItem->m_SelectedImage.width();
		int cyIcon = lpItem->m_SelectedImage.height();

		QRect rcIcon;
		CalcCenterRect(rcItem, cxIcon, cyIcon, rcIcon);
		painter.drawPixmap(rcItem,QPixmap(":/MainTab/Resources/maintab/main_tab_check.png"));

		painter.drawPixmap(rcIcon,lpItem->m_SelectedImage);

	}
	else if (m_iCurrentHoverItem == i)
	{
		int cxIcon = lpItem->m_SelectedImage.width();
		int cyIcon = lpItem->m_SelectedImage.height();

		QRect rcIcon;
		CalcCenterRect(rcItem, cxIcon, cyIcon, rcIcon);

		painter.drawPixmap(rcIcon,lpItem->m_SelectedImage);
	}
	else
	{
		int cxIcon = lpItem->m_SelectedImage.width();
		int cyIcon = lpItem->m_SelectedImage.height();

		QRect rcIcon;
		CalcCenterRect(rcItem, cxIcon, cyIcon, rcIcon);

		painter.drawPixmap(rcIcon,lpItem->m_SelectedImage);
	}

	if (m_iCurrentChooseItem == i)
	{

			QRect rcArrow;
			rcArrow.setLeft(rcItem.left()+lpItem->m_nLeftWidth);
			rcArrow.setTop(rcItem.top()+20);



			painter.drawPixmap(rcItem.width()-14 - 6,2,14,30,QPixmap(":/MainTab/Resources/maintab/main_tabbtn_down.png"));

			int iXPosition = rcItem.left() + rcItem.width()/3 + 3;
			painter.drawPixmap(iXPosition,0,22,38,QPixmap(":/MainTab/Resources/main_tabctrl_arrow.png"));

	}

}


void ColumnWidget::CalcCenterRect(QRect& rcDest, int cx, int cy, QRect& rcCenter )
{
	int x = ((rcDest.width()) - cx + 1) / 2;
	int y = ((rcDest.height()) - cy + 1) / 2;

	rcCenter.setLeft(rcDest.left() + x);
	rcCenter.setTop(rcDest.top() + y);
	rcCenter.setWidth(cx);
	rcCenter.setHeight(cy);

}