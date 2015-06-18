#pragma once
#include <QString>
#include <QList>

class BuddyItem;

class BuddyTeam
{
public:
	BuddyTeam(QString strGroupName,int iAllNumber,int iCurrentNumber)
	{
		m_GroupName = strGroupName;
		m_iAllNumber = iAllNumber;
		m_iCurrentNumber = iCurrentNumber;

		m_bExpand = false;
	}
	~BuddyTeam(void);

	QString	 GetDesc()
	{
		QString str;
		str.sprintf("[%d/%d]",m_iCurrentNumber,m_iAllNumber);

		return m_GroupName + str;
	}

	QString m_GroupName;
	int m_iAllNumber;
	int m_iCurrentNumber;

	void setExpand(bool Expand);

	bool Expand();

	bool m_bExpand;

	QList<BuddyItem*> m_BuddyItemList;
};

