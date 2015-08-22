#include "FriendGroupInfo.h"
#include "FriendInfo.h"


FriendGroupInfo::FriendGroupInfo(void)
{
}


FriendGroupInfo::~FriendGroupInfo(void)
{
}

void FriendGroupInfo::AddFriendFriendList( FriendInfo *pInfo )
{
	m_FriendInfoList.append(pInfo);
}

int FriendGroupInfo::GetOnLineNumber()
{
	int iNumber = 0;
	foreach(FriendInfo *pInfo,m_FriendInfoList)
	{
		if ((pInfo->m_status == "away")||(pInfo->m_status == "online")||(pInfo->m_status == "busy"))
		{
			++iNumber;
		}
	}

	return iNumber;

}

bool FriendGroupInfo::HasMessageArrive()
{
	bool bHasMessage = false;
	foreach(FriendInfo *pInfo,m_FriendInfoList)
	{
		if (pInfo->m_bMessageArrive == true)
		{
			bHasMessage = true;
			break;
		}
	}
	return bHasMessage;

}
