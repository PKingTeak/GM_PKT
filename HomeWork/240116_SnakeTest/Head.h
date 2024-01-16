#pragma once
#include "Part.h"

class Head : public Part
{
public:
	
	void Follow(Part* _CurBack);
	

protected:
	void Update() override;
	int2 Dir = {0,0};

};

