#include "Part.h"


void Part::Follow()
{
	
	if (nullptr == Back)
	{
		return;
	}

	Part* NextBack = Back; //백노드를 가르킴

	//NextBack->SetFront(this); //이게 넣어준거 아닌가?
	PrePos = this->GetPrePos();
	
	Back->SetPos(PrePos); //back이 PrePos의 뒤 즉 몸통
	//헤드의 위치
	
	//NextBack = Back->GetBack();
	if (nullptr == NextBack)
	{
		return;
	}
	
	FollowPosition();

	NextBack->Follow();
	//재귀로
}

Part* Part::GetLastBack()
{
	if (nullptr == Back)
	{
		return this;
	}

	return Back->GetLastBack();
}

int2 Part::FollowPosition()
{
	if (nullptr == Back)
	{
		return this->GetPos();
	}
	//
	Back->SetPrePos(this->GetPos());
	




}




