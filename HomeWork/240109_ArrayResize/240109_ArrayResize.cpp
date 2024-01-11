#include<iostream>
#include<ConsoleEngine/EngineDebug.h>
class IntArray
{
	// private: ����Ʈ �������� ������
public:
	// ����Ʈ ������
	IntArray(int _Size)
	{
		ReSize(_Size);
	}

	// ����Ʈ ���� ������
	IntArray(const IntArray& _Other)
	{
		NumValue = _Other.NumValue;
		ArrPtr = _Other.ArrPtr;
	}
	// ����Ʈ �Ҹ���
	~IntArray()
	{
		Release();
	}
	// ����Ʈ ���Կ�����
	void operator=(const IntArray& _Other)
	{
		NumValue = _Other.NumValue;
		ArrPtr = _Other.ArrPtr;
	}

	int& operator[](int _Count)
	{
		return ArrPtr[_Count];
	}

	int& Test(int _Count)
	{
		return ArrPtr[_Count];
	}

	int Num()
	{
		return NumValue;
	}

	void ReSize(int _Size)
	{
		if (0 >= _Size)
		{
			MsgBoxAssert("�迭�� ũ�Ⱑ 0�ϼ� �����ϴ�");
		}
		if (nullptr != ArrPtr)
		{

			NumValue = _Size;


			int* Ptr = ArrPtr; //�̰ɷ� ArrPrt�� �������� �迭�� ����Ű��
			if (nullptr != Ptr)
			{
				for (int i = 0; i < _Size; i++)
				{
					ArrPtr[i] = Ptr[i];
				}

			}
			// nullptr
			ArrPtr = new int[_Size];// 10���� �ٽ� ������̴�

			Release(); // ���⼭ 01234�� ���ư���.
		}

		
		else 
		{
			NumValue = _Size;
			ArrPtr = new int[_Size];

		}


		// Ptr    [0][1][2][3][4]
		// ArrPtr [?][?][?][?][?][?][?][?][?][?]

	}

	void Release()
	{
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
	}

private:
	int NumValue = 0;
	int* ArrPtr = nullptr;
};



int main()
{
	IntArray NewArray = IntArray(5);

	for (int i = 0; i < NewArray.Num(); i++)
	{
		NewArray[i] = i;
	} //01234


	NewArray.ReSize(10);
	//

	for (size_t i = 0; i < NewArray.Num(); i++)
	{
		std::cout << NewArray[i] << std::endl;
	}
}