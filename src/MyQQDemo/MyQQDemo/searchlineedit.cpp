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
				return true;
			}			
		}
	} 
	return QLineEdit::eventFilter(object, event);

}

