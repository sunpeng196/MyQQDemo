#ifndef COLUMNWIDGET_H
#define COLUMNWIDGET_H

#include <QWidget>

class TabCtrlItem
{
public:
	QPixmap m_NormalImage;
	QPixmap m_HoverImage;
	QPixmap m_SelectedImage;
	QString m_ToolTipString;

	int						m_nWidth, m_nHeight;
	int						m_nLeftWidth, m_nRightWidth;
	int						m_nPadding;
};



class ColumnWidget : public QWidget
{
	Q_OBJECT

public:
	ColumnWidget(QWidget *parent);
	~ColumnWidget();

	void keyPressEvent(QKeyEvent * e);


signals:  
	void currentRowChanged ( int currentRow );
public:
	void Init()
	{
		TabCtrlItem *pNewItem = new TabCtrlItem();
		pNewItem->m_ToolTipString = "联系人";
		AddTabCtrlItem(pNewItem);

		pNewItem->m_HoverImage = QPixmap(":/ColumnIcon/Resources/icon_contacts_hover.png");
		pNewItem->m_NormalImage = QPixmap(":/ColumnIcon/Resources/icon_contacts_normal.png");
		pNewItem->m_SelectedImage = QPixmap(":/ColumnIcon/Resources/icon_contacts_selected.png");
		pNewItem->m_nPadding = 1;




		pNewItem  = new TabCtrlItem();
		pNewItem->m_ToolTipString = "会话";
		pNewItem->m_HoverImage = QPixmap(":/ColumnIcon/Resources/icon_last_hover.png");
		pNewItem->m_NormalImage = QPixmap(":/ColumnIcon/Resources/icon_last_normal.png");
		pNewItem->m_SelectedImage = QPixmap(":/ColumnIcon/Resources/icon_last_normal_msg.png");
		pNewItem->m_nPadding = 1;
		AddTabCtrlItem(pNewItem);

		pNewItem = new TabCtrlItem();
		pNewItem->m_ToolTipString = "群/讨论组";
		pNewItem->m_HoverImage = QPixmap(":/ColumnIcon/Resources/icon_group_hover.png");
		pNewItem->m_NormalImage = QPixmap(":/ColumnIcon/Resources/icon_group_normal.png");
		pNewItem->m_SelectedImage = QPixmap(":/ColumnIcon/Resources/icon_group_selected.png");
		pNewItem->m_nPadding = 1;
		AddTabCtrlItem(pNewItem);
	}

	void paintEvent(QPaintEvent * e);
	void focusInEvent(QFocusEvent *e);
	//void focusOutEvent(QFocusEvent *e);

	void DrawItem( int i );


	int m_iCurrentHoverItem,m_iCurrentChooseItem;

	void AddTabCtrlItem(TabCtrlItem *pNewItem)
	{

		pNewItem->m_nWidth = (width()-2)/3 -1;
		pNewItem->m_nHeight = 35;


		pNewItem->m_nLeftWidth = (width()-2)/3-20;
		pNewItem->m_nRightWidth = 20;


		m_TabCtrlList.append(pNewItem);
	}

	void SetCurrentItem(int iItemIndex)
	{
		m_iCurrentChooseItem = iItemIndex;
	}

	void SetHoverItem(int iHoverItem)
	{
		m_iCurrentHoverItem = iHoverItem;
	}

	void mousePressEvent(QMouseEvent * e);

	void mouseMoveEvent(QMouseEvent *e);

	int GetPointIndex(const QPoint &pt);
	bool GetItemRectByIndex(int nIndex, QRect& rect);
	void CalcCenterRect(QRect& rcDest, int cx, int cy, QRect& rcCenter );
	QList<TabCtrlItem*> m_TabCtrlList;

	int m_nLeft,m_nTop;

	QRect m_CurCurrentArrowRect;

	bool m_bShowRect;

	
};

#endif // COLUMNWIDGET_H
