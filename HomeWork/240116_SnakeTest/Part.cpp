#include "Part.h"


void Part::Follow()
{
	
	if (nullptr == Back)
	{
		return;
	}

	Part* NextBack = Back; //���带 ����Ŵ

	NextBack->SetFront(this); //�̰� �־��ذ� �ƴѰ�?
	PrePos = this->GetPrePos();
	
	Back->SetPos(PrePos); //back�� PrePos�� �� �� ����

	//NextBack = Back->GetBack();
	if (nullptr == NextBack)
	{
		return;
	}
	

	NextBack->Follow();
	
	//��ͷ�
}

Part* Part::GetLastBack()
{
	if (nullptr == Back)
	{
		return this;
	}

	return Back->GetLastBack();
}






