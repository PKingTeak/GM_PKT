#pragma once
#include "Part.h"

class Head : public Part
{
public:
	
	void FollowHead(Part* _Body)
	{
		

	}

protected:
	void Update() override;
	int2 Dir = {0,0};

};

