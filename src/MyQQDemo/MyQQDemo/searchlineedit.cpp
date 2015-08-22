#include "searchlineedit.h"
#include <QLabel>
#include <QtGui/QMouseEvent>
#include <QPainter>
#include <QToolButton>

SearchLineEdit::SearchLineEdit(QWidget *parent)
	: QLineEdit(parent)
{
	m_pLabel = new QLabel(this);
	m_pLabel->setScaledContents(true);
	m_pLabel->setAttribute(Qt::WA_TranslucentBackground);

	setAttribute(Qt::WA_TranslucentBackground);

	m_pLabel->installEventFilter(this);

	setMouseTracking(true);
	this->setFocusPolicy(Qt::StrongFocus);

	this->setPlaceholderText("搜索：联系人、讨论组、群、企业");

	m_pListView = new QListView();
	m_pListView->setParent((QWidget*)this->parent());
	m_pListView->hide();

	QObject::connect(this,
		SIGNAL(textChanged(const QString&)),
		this,
		SLOT(SlotTextChanged(const QString&)));

}

SearchLineEdit::~SearchLineEdit()
{

}

void SearchLineEdit::resizeEvent( QResizeEvent * e )
{
	int nLabelHeight = height() - 4;
	int nLabelWidth = height() - 4;

	m_pLabel->setMaximumSize(nLabelWidth,nLabelHeight);

	m_pLabel->setCursor(Qt::ArrowCursor);

	m_pLabel->setGeometry(width() - nLabelWidth - 2,(height() - nLabelHeight)/2,
		nLabelWidth,nLabelHeight);

	setTextMargins(QMargins(6,0,nLabelHeight+6,0));
	m_pLabel->setPixmap(QPixmap(":/SearchLineEdit/Resources/finger_normal.png"));
}

bool SearchLineEdit::eventFilter( QObject *object , QEvent *event)
{
	if (m_pLabel && object == m_pLabel ) {
		if (event->type() == QEvent::MouseButtonPress) {
			QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
			if (mouseEvent->buttons() & Qt::LeftButton)
			{
				this->clear();
			}			
		}
	} 
	return QLineEdit::eventFilter(object, event);

}

void SearchLineEdit::SlotTextChanged(const QString& str)
{
	QLineEdit *pSender = (QLineEdit*)(sender());

	QPoint pt  = pSender->pos();

	m_pListView->setGeometry(
		pt.x(),
		pt.y()+pSender->height(),
		pSender->width(),
		300);
	m_strList.clear();
	foreach(QChar x , str)
	{
		m_strList.append(x);
	}
	m_strListModel.setStringList(m_strList);
	m_pListView->setModel(&m_strListModel);


	m_pListView->setFixedHeight(463);
	m_pListView->setFixedWidth(this->width());

	if (m_strList.count()>0)
	{
		m_pLabel->setPixmap(QPixmap(":/Search/Resources/mainSearch/main_search_down.png"));
		m_pListView->show();
	}
	else
	{
		m_pLabel->setPixmap(QPixmap(":/SearchLineEdit/Resources/finger_normal.png"));
		m_pListView->hide();
	}
}

