#include "searchlineedit.h"
#include <QLabel>
#include <QtGui/QMouseEvent>

SearchLineEdit::SearchLineEdit(QWidget *parent)
	: QLineEdit(parent)
{
	setAttribute(Qt::WA_TranslucentBackground);
	setStyleSheet("background: transparent;border:none;");
	
	

	m_pSerachPixMap = new QLabel(this);
	m_pSerachPixMap->setStyleSheet("border-width:0px");
	m_pSerachPixMap->setPixmap(QPixmap(":/SearchLineEdit/Resources/finger_normal.png"));
	m_pSerachPixMap->setAttribute(Qt::WA_TranslucentBackground);

	setPlaceholderText("搜索:联系人、讨论组、群、企业");
}

SearchLineEdit::~SearchLineEdit()
{

}

void SearchLineEdit::paintEvent( QPaintEvent * e )
{
	m_pSerachPixMap->setGeometry(width()- QPixmap(":/SearchLineEdit/Resources/finger_normal.png").width(),
		6,
		QPixmap(":/SearchLineEdit/Resources/finger_normal.png").width(),
		QPixmap(":/SearchLineEdit/Resources/finger_normal.png").height());

	return QLineEdit::paintEvent(e);
}

void SearchLineEdit::mousePressEvent( QMouseEvent *e )
{

}

void SearchLineEdit::focusInEvent( QFocusEvent * e )
{
	if (!e->gotFocus())
	{
		setPlaceholderText("搜索:联系人、讨论组、群、企业");
	}

}
