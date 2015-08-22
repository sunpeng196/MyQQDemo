#include "chatsessionlistdelegate.h"
#include "RecentChat.h"
#include <QPainter>

ChatSessionListDelegate::ChatSessionListDelegate(QObject *parent)
	: QAbstractItemDelegate(parent)
{

}

ChatSessionListDelegate::~ChatSessionListDelegate()
{

}

void ChatSessionListDelegate::paint( QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index ) const
{
	if (option.state & QStyle::State_MouseOver)
	{
		painter->drawPixmap(option.rect,QPixmap(":/BuddyList/BuddyList/main_yellowbar_bkg.png"));
	}

	if (option.state & QStyle::State_Selected)
	{
		painter->drawPixmap(option.rect,QPixmap(":/BuddyList/BuddyList/main_yellowbar_bkg.png"));
	}

	QRect rect = option.rect;
	RecentChat *pRecent = (RecentChat*)(index.internalPointer());

	quint64 uin = pRecent->m_uin;

	QString headerPath = QString(":/headers/Resources/headers/%1.png").arg(uin%264 + 1);

	QPixmap image(headerPath);

	QRect headerImg(rect);
	headerImg.setWidth(image.width());
	headerImg.setHeight(image.height());
	headerImg.setLeft(rect.left()+2);
	headerImg.setTop(rect.top()+2);

	painter->drawPixmap(headerImg,image);

	QString strShow = QString("%1 (%2)").arg("abc").arg("def");
	painter->drawText(rect.left()+2+48,rect.top()+2,300,30,0,strShow);





}

QSize ChatSessionListDelegate::sizeHint( const QStyleOptionViewItem &option, const QModelIndex &index ) const
{
	return QSize(300,48);
}
