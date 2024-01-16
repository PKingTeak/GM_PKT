#pragma once
#include "Part.h"

class Head : public Part
{

protected:
	void Update() override;
	int2 Dir = {0,0};
};

