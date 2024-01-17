#include "Head.h"
#include <conio.h>
#include <ConsoleEngine/EngineCore.h>
#include "BodyManager.h"
#include "Body.h"

// 
// 1. 내가 특정 방향으로 진행했다면 다음 입력때는 그 반대방향으로는 갈수가 없다.
//    내가 이동하는 방향의 반대방향으로는 가면 안된다.
// 2. 내가 이동을 해서 CurBody를 획득했다면 그 다음부터 그 바디는 나를 따라와야 한다.

void Head::Update()
{

	int InputCount = _kbhit();
	if (0 == InputCount)
	{
		return;
	}

	int2 CurHeadPos = this->GetPos(); //현재 위치
	; //이전 위치

	int Select = _getch();

	// InputCount = _kbhit();



	// X Y
	// 1 0

	//1번 과제 완료
	switch (Select)
	{
	case 'A':
	case 'a':
		if (Dir != Right)
		{

			Dir = Left;
			SetPrePos(CurHeadPos);
			AddPos(Dir);
		}
		break;
	case 'S':
	case 's':
		if (Dir != Up)
		{
			Dir = Down;
			SetPrePos(CurHeadPos);
			AddPos(Dir);
		}
		break;
	case 'W':
	case 'w':
		if (Dir != Down)
		{
			Dir = Up;
			SetPrePos(CurHeadPos);
			AddPos(Dir);
		}

		break;
	case 'D':
	case 'd':
		if (Dir != Left)
		{
			Dir = Right;
			SetPrePos(CurHeadPos);
			AddPos(Dir);
		}

		break;
	case '1':
		GetCore()->EngineEnd();
		break;
	default:
		break;
	}

	if (nullptr == BodyManager::GetCurBody())
	{
		MsgBoxAssert("먹을수 있는 바디가 존재하지 않습니다.");
		return;
	}



	Body* CurBody = BodyManager::GetCurBody();// 이게 바디


	if (CurBody->GetPos() == GetPos())
	{
		Body* PreBody = CurBody;
		PreBody->SetPos(GetPrePos());
		this->Back = PreBody;


		//Head의 back
		PreBody->SetFront(this);

		BodyManager::ResetBody();

	}

	else
	{
		Follow();


		//Part* CurBack = this->Back; //머리

		//while (nullptr != CurBack)
		//{
		//	CurBack->SetPos(CurHeadPos);
		//	//CurBack = CurBack->GetFront(Back);

		//	//CurBack = Follow(CurBack);
		//	

		//	//여기 까지는 2번째 자식이 안따라옴


		//	
		//	//재귀 호출하면 this->back을 계속 바꿀수 있으니까 		
		//	
		//}

	}


}




