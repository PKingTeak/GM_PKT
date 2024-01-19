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

		Part* LastBack = GetLastBack(); // 이거는 백이 끊겨서 결국 
		//원래 있던 몸통을 자르고 새로 연결하기 때문에 끝인걸 채크해줘야된다. 
		// 결굴 head에 맨 끝에 있는곳으로 채크하고 배치해야된다. 
		LastBack->SetBack(CurBody);
		CurBody->SetPos(LastBack->GetPrePos());

		BodyManager::ResetBody();

	}

	else
	{
		Follow();


		
	}


}




