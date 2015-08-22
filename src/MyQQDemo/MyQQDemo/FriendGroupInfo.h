#pragma once
#include <QString>
#include <QList>
#include <QObject>

class FriendInfo;


class FriendGroupInfo:public QObject
{
	Q_OBJECT
public:
	FriendGroupInfo(void);
	~FriendGroupInfo(void);

	void AddFriendFriendList(FriendInfo *pInfo);

	bool HasMessageArrive();

	int GetOnLineNumber();

	QString m_GroupInfoName;

	QList<FriendInfo*> m_FriendInfoList;

	bool m_bShowM;
};

