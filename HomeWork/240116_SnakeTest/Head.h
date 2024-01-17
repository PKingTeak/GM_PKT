#pragma once
#include "Part.h"

class Head : public Part
{
public:
	
	

protected:
	void Update() override;
	int2 Dir = {0,0};

};

