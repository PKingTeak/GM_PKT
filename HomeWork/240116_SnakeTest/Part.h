#pragma once
#include <ConsoleEngine/ConsoleObject.h>

class Part : public ConsoleObject
{
public:
	Part* GetBack()
	{
		return Back;
	}

protected:
	Part* Front = nullptr;
	Part* Back = nullptr;
};

