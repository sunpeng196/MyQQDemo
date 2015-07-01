#ifndef SEARCHLINEEDIT_H
#define SEARCHLINEEDIT_H

#include <QLineEdit>
class QToolButton;
class QMouseEvent;

class QLabel;


class SearchLineEdit : public QLineEdit
{
	Q_OBJECT

public:
	SearchLineEdit(QWidget *parent);
	~SearchLineEdit();

	void resizeEvent(QResizeEvent * e);

	virtual bool eventFilter(QObject *obj, QEvent *e);


private:

	QLabel *m_pLabel;
	
};

#endif // SEARCHLINEEDIT_H
