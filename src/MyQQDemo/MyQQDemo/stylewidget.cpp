#include "stylewidget.h"
#include <QMouseEvent>
#include <QDesktopWidget>
#include <QTreeWidgetItem>
#include <QTreeWidget>

StyleWidget::StyleWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.treeWidget->setColumnCount(1);

	
	QTreeWidgetItem *pGoodFriendItem = new QTreeWidgetItem(ui.treeWidget,QStringList(QString("我的好友[10/30]")));
	ui.treeWidget->addTopLevelItem(pGoodFriendItem);

	QList<QTreeWidgetItem *> items;
	for (int i =0;i < 10;++i)
	{
		items.append(new QTreeWidgetItem(pGoodFriendItem, QStringList(QString("item: %1").arg(i))));
	}
	ui.treeWidget->insertTopLevelItems(0,items);

	QTreeWidgetItem *pFriendList = new QTreeWidgetItem(ui.treeWidget,QStringList(QString("同事[10/30]")));
	ui.treeWidget->addTopLevelItem(pFriendList);


	QList<QTreeWidgetItem *> items1;
	for (int i =0;i < 10;++i)
	{
		items1.append(new QTreeWidgetItem(pFriendList, QStringList(QString("item: %1").arg(i))));
	}
	ui.treeWidget->insertTopLevelItems(1,items1);


}

StyleWidget::~StyleWidget()
{

}

void StyleWidget::mousePressEvent( QMouseEvent *e )
{
// 	QPoint pt = e->globalPos();
// 
// 	QPoint ptGloabl = cursor().pos();

// 	QRect abc = geometry();
// 
// 
// 	QString str;
// 	str.sprintf("X:%d,Y:%d.GlobalX:%d,GlobalY:%d",abc.left(),abc.top(),abc.right(),abc.bottom());QS

// 	QPoint pt = pos();
// 
// 	QString str;
// 	str.sprintf("X:%d,Y:%d",pt.x(),pt.y());
// 
// 	setWindowTitle(str);

// 	int iWidth = QApplication::desktop()->width();
// 	int iHeight = QApplication::desktop()->height();
// 
// 	//if (pt.y() <= 20)
// 	{
// 		m_iStartTimer = startTimer(10);		
// 	}


}

void StyleWidget::timerEvent( QTimerEvent * e )
{
// 	QPoint pt = this->pos();
// 
// 	int iStep = (pt.y()+ this->height() - 8)/7;
// 
// 	if (pt.y() + this->height() >= 8)
// 	{
// 		int y = pt.y() - iStep;
// 		this->move(pt.x(),y);
// 	}
// 	else
// 	{
// 		int y = pt.y();
// 		int height = this->height();
// 		killTimer(m_iStartTimer);
// 	}
}
