#include "Head.h"
#include <conio.h>
#include <ConsoleEngine/EngineCore.h>
#include "BodyManager.h"
#include "Body.h"

// 
// 1. ���� Ư�� �������� �����ߴٸ� ���� �Է¶��� �� �ݴ�������δ� ������ ����.
//    ���� �̵��ϴ� ������ �ݴ�������δ� ���� �ȵȴ�.
// 2. ���� �̵��� �ؼ� CurBody�� ȹ���ߴٸ� �� �������� �� �ٵ�� ���� ����;� �Ѵ�.

void Head::Update()
{

	int InputCount = _kbhit();
	if (0 == InputCount)
	{
		return;
	}

	int2 CurHeadPos = this->GetPos(); //���� ��ġ
	; //���� ��ġ

	int Select = _getch();

	// InputCount = _kbhit();



	// X Y
	// 1 0

	//1�� ���� �Ϸ�
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
		MsgBoxAssert("������ �ִ� �ٵ� �������� �ʽ��ϴ�.");
		return;
	}



	Body* CurBody = BodyManager::GetCurBody();// �̰� �ٵ�


	if (CurBody->GetPos() == GetPos())
	{
		Body* PreBody = CurBody;
		PreBody->SetPos(GetPrePos());
		this->Back = PreBody;


		//Head�� back
		PreBody->SetFront(this);

		BodyManager::ResetBody();

	}

	else
	{
		Follow();


		//Part* CurBack = this->Back; //�Ӹ�

		//while (nullptr != CurBack)
		//{
		//	CurBack->SetPos(CurHeadPos);
		//	//CurBack = CurBack->GetFront(Back);

		//	//CurBack = Follow(CurBack);
		//	

		//	//���� ������ 2��° �ڽ��� �ȵ����


		//	
		//	//��� ȣ���ϸ� this->back�� ��� �ٲܼ� �����ϱ� 		
		//	
		//}

	}


}




