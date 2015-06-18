#include "BuddyTeam.h"



BuddyTeam::~BuddyTeam(void)
{
}

void BuddyTeam::setExpand( bool Expand )
{
	m_bExpand = Expand;
}

bool BuddyTeam::Expand()
{
	return m_bExpand;
}
