#pragma once
#include <QString>
#include <QtGlobal>
 #include <QObject>
class FriendInfo:public QObject
{
	Q_OBJECT
public:
	FriendInfo(void);
	~FriendInfo(void);

	qint64 m_uin;
	QString m_status;//"online"

	QString m_Markname;
	int m_iType;

	int m_Cate;

	QString m_nickName;
	int m_iFaceIndex;

	bool m_bMessageArrive;

	int m_iHeaderFlashIndex;

};

