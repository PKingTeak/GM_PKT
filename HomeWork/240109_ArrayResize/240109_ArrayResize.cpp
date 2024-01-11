#include<iostream>
#include<ConsoleEngine/EngineDebug.h>
class IntArray
{
	// private: 디폴트 접근제한 지정자
public:
	// 디폴트 생성자
	IntArray(int _Size)
	{
		ReSize(_Size);
	}

	// 디폴트 복사 생성자
	IntArray(const IntArray& _Other)
	{
		NumValue = _Other.NumValue;
		ArrPtr = _Other.ArrPtr;
	}
	// 디폴트 소멸자
	~IntArray()
	{
		Release();
	}
	// 디폴트 대입연산자
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
			MsgBoxAssert("배열의 크기가 0일수 없습니다");
		}
		if (nullptr != ArrPtr)
		{

			NumValue = _Size;


			int* Ptr = ArrPtr; //이걸로 ArrPrt의 힘공간의 배열을 가르키고
			if (nullptr != Ptr)
			{
				for (int i = 0; i < _Size; i++)
				{
					ArrPtr[i] = Ptr[i];
				}

			}
			// nullptr
			ArrPtr = new int[_Size];// 10개로 다시 만들것이다

			Release(); // 여기서 01234가 날아간다.
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