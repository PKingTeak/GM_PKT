#pragma once
#include <ConsoleEngine/ConsoleObject.h>

class Part : public ConsoleObject
{
public:

	Part* GetBack()
	{
		return Back;
	}
	void SetBack(Part* _Back)
	{
		Back = _Back;
		
	}


	void SetFront(Part* _Front)
	{
		Front = _Front;
	}
	Part* GetFront()
	{
		return Front;
	}
	void SetPrePos(int2 _PrePos)
	{
		PrePos = _PrePos;
	}

	int2  GetPrePos()
	{
		return PrePos;
	}
	 void Follow();
	// void SetBack(Part* _Back);

	 
	 Part* GetLastBack();

	 


protected:
	Part* Front = nullptr;
	Part* Back = nullptr;
	int2 PrePos;

};

