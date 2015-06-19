#pragma once
#include <QString>
class QPixmap;

class BuddyItem
{
public:
	BuddyItem(void);
	~BuddyItem(void);

public:
	int							m_nID;						// 项ID
	QString						m_strQQNum;					// QQ号码
	QString						m_strNickName;				// 昵称
	QString						m_strMarkName;				// 备注
	QString						m_strSign;					// 签名
	bool						m_bOnline;					// 是否在线标志
	bool						m_bOnlineAnim;				// 上线动画标志
	int							m_nOnlineAnimState;			// 上线动画状态
	bool						m_bOfflineAnim;				// 下线动画标志
	bool						m_bHeadFlashAnim;			// 头像闪动动画标志
	int							m_nHeadFlashAnimState;		// 头像闪动动画状态
	QPixmap					* m_lpHeadImg;				// 头像图片
	bool						m_bGender;	
};

