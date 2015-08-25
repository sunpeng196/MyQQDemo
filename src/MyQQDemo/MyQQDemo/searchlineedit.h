#ifndef SEARCHLINEEDIT_H
#define SEARCHLINEEDIT_H

#include <QLineEdit>
#include <QListView>
#include <QStringListModel>
#include <QStringList>
class QToolButton;
class QMouseEvent;

class QLabel;


class SearchLineEdit : public QLineEdit
{
	Q_OBJECT

public:
	SearchLineEdit(QWidget *parent);
	~SearchLineEdit();

	void contextMenuEvent(QContextMenuEvent *event);


	void resizeEvent(QResizeEvent * e);

	virtual bool eventFilter(QObject *obj, QEvent *e);

	QListView *m_pListView;

	public slots:
		void SlotTextChanged(const QString&);


private:

	QLabel *m_pLabel;

	QStringListModel m_strListModel;
	QStringList m_strList;
	
};

#endif // SEARCHLINEEDIT_H
