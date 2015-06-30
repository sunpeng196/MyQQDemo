#ifndef SEARCHLINEEDIT_H
#define SEARCHLINEEDIT_H

#include <QLineEdit>
class QLabel;
class QMouseEvent;


class SearchLineEdit : public QLineEdit
{
	Q_OBJECT

public:
	SearchLineEdit(QWidget *parent);
	~SearchLineEdit();

	//void paintEvent(QPaintEvent * e);

	void mousePressEvent(QMouseEvent *e);

	void focusInEvent(QFocusEvent * e);
	void leaveEvent(QEvent * e);

private:
	bool m_bFocusIn;

	//QLabel *m_pSerachPixMap;
	
};

#endif // SEARCHLINEEDIT_H
