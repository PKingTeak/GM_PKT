#include "Part.h"

void Part::Follow()
{
	if (nullptr == Back)
	{
		return;
	}

	Back->SetPos();

	Back->Follow();
	
}