#include "Part.h"


void Part::Follow()
{
	if (nullptr == Back)
	{
		return;
	}


//	this->SetPrePos(GetPrePos());
	PrePos = this->GetPrePos();
	

	Back->SetPos(PrePos);

	Back->Follow();
	//Àç±Í·Î
}


